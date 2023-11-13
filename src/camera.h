#ifndef CAMERA_H_
#define CAMERA_H_

#include "WebServer.h"
#include "camera_controller.h"
//#include "drone.h"
#include "stb_image.h"
#include "stb_image_write.h"
#include "image.h"
#include "apply_rgb.h"

#include <fstream>
#include <map>
#include <chrono>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

class Camera : public ICameraObserver {
public:
    // Structure the result however you like
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };

    // Constructor
    Camera(int cameraId, ICameraController* controller);

    // Takes a picture using the specified camera id
    void TakePicture();

    // Processes images asynchonously.  The returned camera result will be passed into the ImageProcessingComplete(...) method
    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const;

    // After the asynchronous image processing, this method will be synchronized with the update loop.
    void ImageProcessingComplete(ICameraResult* result);

    int found;
private:
    ICameraController* controller;
    int id;
};
#endif