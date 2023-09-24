#include <iostream>
#include <fstream>

#include "web_app.h"
#include "base64.h"
#include "movement.h"
#include "patrol.h"
#include "drone.h"
#include "entityFactory.h"
#include "hospital.h"
#include "recharge.h"
#include "robot.h"
#include "apply_rgb.h"
#include "stb_image.h"
#include "stb_image_write.h"
#include "image.h"
#include "camera.h"
    
//*****************************************************************************************
// Edit the following functions to suit your needs.  Do most of the work inside the
// simulation facade and not here.  The primary purpose of these functions are to
// communicate with the UI.
//*****************************************************************************************

DroneFactory* factory = new DroneFactory();
Drone* deleteThisDrone = factory->CreateEntity();

void WebApp::CreateEntity(picojson::object& entityData, ICameraController& cameraController) {
    // Creates an entity based on JSON data stored as an object.
    // Print out actual json:
    picojson::value val(entityData);
    std::cout << val.serialize() << std::endl;

    // Use your simulatin facade to create a new entity.
    // Below is an example on how to get data values from picojson.
    // The code should be in the factory, not here!
    if (entityData["name"].get<std::string>() == "drone") {
        deleteThisDrone->id = entityData["entityId"].get<double>();
        deleteThisDrone->speed = 20;

        // Get the position as an array
        picojson::array position = entityData["position"].get<picojson::array>();
        deleteThisDrone->position[0] = 110;
        deleteThisDrone->position[1] = 2.5;
        deleteThisDrone->position[2] = 60;

        // Get the direction as an array
        picojson::array dir = entityData["direction"].get<picojson::array>();
        deleteThisDrone->dir[0] = dir[0].get<double>();
        deleteThisDrone->dir[1] = dir[1].get<double>();
        deleteThisDrone->dir[2] = dir[1].get<double>();

        // Create cameras for the entity.
        picojson::array cameras = entityData["cameras"].get<picojson::array>();
        for (int i = 0; i < cameras.size(); i++) {
            Camera* camera = new Camera(cameras[i].get<double>(), &cameraController);
            deleteThisDrone->cameras.push_back(camera);
        }
    }
}

void WebApp::Update(double dt) {
    // Updates the simulation.  This may be called multiple times per frame.
    Patrol patrol;
    patrol.Move(deleteThisDrone);
    
    deleteThisDrone->Update(dt);
}

void WebApp::FinishUpdate(picojson::object& returnValue) {
    // Called after all updating is done.

    // Below is an example of how to send the position and direction to the UI.  
    // In general you will want to loop through entities that have changed to update
    // their position and direction:
    picojson::object entity;
    entity["entityId"] = picojson::value((double)0);
    
    // Save the position as an array
    picojson::array pos;
    pos.push_back(picojson::value(deleteThisDrone->position[0]));
    pos.push_back(picojson::value(deleteThisDrone->position[1]));
    pos.push_back(picojson::value(deleteThisDrone->position[2]));
    entity["pos"] = picojson::value(pos);

    // Save the direction as an array
    picojson::array dir;
    dir.push_back(picojson::value(deleteThisDrone->dir[0]));
    dir.push_back(picojson::value(deleteThisDrone->dir[1]));
    dir.push_back(picojson::value(deleteThisDrone->dir[2]));
    entity["dir"] = picojson::value(dir);

    // Send the compile picojson data to the UI in the returnValue variable
    returnValue["entity"+std::to_string(deleteThisDrone->id)] = picojson::value(entity);
}

//*****************************************************************************************
// The code below you probably will not need to touch.  These are the functions 
// that will talk to the UI over web sockets.
//*****************************************************************************************

WebApp::WebApp() : start(std::chrono::system_clock::now()), time(0.0), running(true) {
    imageProcessThread = new std::thread(&WebApp::ProcessImageQueue, this);
}

WebApp::~WebApp() {
    running = false;
    imageProcessCond.notify_all();
    imageProcessThread->join();
}

void WebApp::receiveJSON(picojson::value& val) {
    picojson::object data = val.get<picojson::object>();
    std::string cmd = data["command"].get<std::string>();
    picojson::object returnValue;
    returnValue["id"] = data["id"];
    ReceiveCommand(cmd, data, returnValue);
    picojson::value retVal(returnValue);
    sendJSON(retVal);
}

void WebApp::ReceiveCommand(const std::string& cmd, picojson::object& data, picojson::object& returnValue) {
    if (cmd == "image") {
        std::unique_lock<std::mutex> lock(imageProcessMutex);
        data["time"].set<double>(time);
        imageQueue.push(data);
        imageProcessCond.notify_all();
        return;
    }


    std::unique_lock<std::mutex> updateLock(updateMutex);
    if (cmd == "createEntity") {
        CreateEntity(data, *this);
    } 
    else if (cmd == "update") {
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
        double delta = diff.count() - time;
        time += delta;

        double simSpeed = data["simSpeed"].get<double>();
        delta *= simSpeed;

        if (delta > 0.1) {
            for (float f = 0.0; f < delta; f+=0.01) {
                Update(0.01);
            }
        }
        else {
            Update(delta);
        }
        FinishUpdate(returnValue);
    }
    else if (cmd == "keyup") {
        KeyUp(data["key"].get<std::string>(), data["keyCode"].get<double>());
    }
    else if (cmd == "keydown") {
        KeyDown(data["key"].get<std::string>(), data["keyCode"].get<double>());
    }
    else {
        std::cout << "Unknown command: " << cmd << " - " << picojson::value(data).serialize() << std::endl;
    }
}

void WebApp::KeyUp(const std::string& key, int keyCode) {
    keyValue[key] = 0;
}

void WebApp::KeyDown(const std::string& key, int keyCode) {
    keyValue[key] = 1;
}

bool WebApp::IsKeyDown(const std::string& key) {
    std::map<std::string,int>::iterator it = keyValue.find(key);
    if (it != keyValue.end()) {
        return it->second;
    } 

    return false;
}

void WebApp::TakePicture(int cameraId) {
    picojson::object obj;
    picojson::value val;
    obj["takePicture"] = picojson::value((double)cameraId);
    picojson::value v(obj);
    sendJSON(v);
}

void WebApp::ProcessImageQueue() {
    while (running) {
        std::unique_lock<std::mutex> lock(imageProcessMutex);
        if (imageQueue.size() > 0) {
            picojson::object data = imageQueue.front();
            imageQueue.pop();
            lock.unlock();
            
            std::vector<std::string> decodedImages;
            std::vector<RawCameraImage> imageData;
            
            const picojson::array& images = data["images"].get<picojson::array>();

            for (int i = 0; i < images.size(); i++) {
                std::string decoded = base64_decode(images[i].get<std::string>().substr(23));
                decodedImages.push_back(decoded);
                RawCameraImage rawImage;
                rawImage.data = reinterpret_cast<const unsigned char*>(decodedImages[i].c_str());
                rawImage.length = decoded.length();
                imageData.push_back(rawImage);
            }

            int cameraId = data["cameraId"].get<double>();
            const picojson::array& pos = data["position"].get<picojson::array>();

            for (int i = 0; i < cameraObservers.size(); i++) {
                ICameraResult* result = cameraObservers[i]->ProcessImages(
                    cameraId,
                    pos[0].get<double>(),
                    pos[1].get<double>(),
                    pos[2].get<double>(),
                    imageData,
                    data
                );
                if (result) {
                    std::unique_lock<std::mutex> updateLock(updateMutex);
                    cameraObservers[i]->ImageProcessingComplete(result);
                }
            }
        }
        else {
          imageProcessCond.wait(lock);
        }
    }
}

void WebApp::AddObserver(ICameraObserver& observer) {
    cameraObservers.push_back(&observer);
}

void WebApp::RemoveObserver(ICameraObserver& observer) {
    cameraObservers.erase(std::remove(cameraObservers.begin(), cameraObservers.end(), &observer), cameraObservers.end()); 
}