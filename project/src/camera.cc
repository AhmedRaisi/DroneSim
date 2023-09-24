#include "camera.h"

// Constructor
Camera::Camera(int cameraId, ICameraController* controller) : id(id), controller(controller) {
    controller->AddObserver(*this);
}

// Takes a picture using the specified camera id
void Camera::TakePicture() {
    controller->TakePicture(id);
}

// Processes images asynchonously.  The returned camera result will be passed into the ImageProcessingComplete(...) method
ICameraResult* Camera::ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
    if (cameraId == id || cameraId < 0) {
        // These will output the image to files.  Ultimately this is just for debugging:
        std::ofstream colorFile ("color.jpg", std::ios::out | std::ios::binary);
        colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
        std::ofstream depthFile ("depth.jpg", std::ios::out | std::ios::binary);
        depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);


        // Use the following to convert color and depth images to RGBA image from memory (inside your image class / perhaps with a new constructor):
        int width, height, components;
        unsigned char* buffer = stbi_load_from_memory((const unsigned char*)images[0].data, images[0].length, &width, &height, &components, 4);
        components = 4;

        unsigned char* input_image = new unsigned char[width*height*components];
        std::copy(buffer, buffer + width*height*components, input_image); // copy allows us to copy one byte array to another
        stbi_image_free(buffer);

        Image image = Image(input_image,width,height);

        ApplyRGB apply;
        int found_notfound = apply.ApplyFilter(&image);
        


        // Generate the result of image processing.  This could include images using the Result class.
        CameraResult* result = new CameraResult();
        //found = -1;
        if (found_notfound==0){
            //found = 0;
            result->found = true;
            result->pos[0] = xPos;
            result->pos[1] = yPos;
            result->pos[2] = zPos;
        }
        return result;
    }
    else {
        return NULL;
    }
}

// After the asynchronous image processing, this method will be synchronized with the update loop.
void Camera::ImageProcessingComplete(ICameraResult* result) {
    CameraResult& res = *static_cast<CameraResult*>(result);
    if (res.found) {
        std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[1] << std::endl;
    }
    delete result;
}
