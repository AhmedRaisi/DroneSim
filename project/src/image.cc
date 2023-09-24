#define STB_IMAGE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <string>
#include "image.h"
#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;

Image::~Image(){
    
}

Image::Image(){

}

Image::Image(int width, int height){
    int components;
    this->width = width;
    this->height = height;
    this-> components =4;
    image=new unsigned char[width*height*4];
}

Image::Image(const char* filename){
	unsigned char *loadedImage = stbi_load(filename, &width, &height, &components, STBI_rgb_alpha);
    this-> components =4;
    components = 4; // Images may have less components, but we are forcing alpha with STBI_rgb_alpha

    // Copy the image data into a local image buffer and free the image
    image = new unsigned char[width*height*this->components];
	std::copy(loadedImage, loadedImage + width*height*components, image); // copy allows us to copy one byte array to another
    stbi_image_free(loadedImage);

}

Image::Image(unsigned char* input_image, int width, int height){
    this->components = 4;
    this->width = width;
    this->height = height;

    image = input_image;
}

void Image::operator=(const Image& other_image){
    this->width = other_image.width;
    this->height = other_image.height;
    this->components = other_image.components;

    image = new unsigned char[width*height*components];
    memcpy(image, other_image.image, width*height*components);
}

int Image::SaveAs(const char* filename){
    return stbi_write_png(filename, width, height, 4, image, width*4);
}

int Image::GetComponentNum(){
    return components;
}

int Image::GetHeight(){
    return height;
}

int Image::GetWidth(){
    return width;
}

unsigned char* Image::GetPixel(int x, int y){
    unsigned char* pixel = &image[(y*width + x)*4];
    return pixel;
}

void Image::SetPixel(int x,int y,unsigned char* pixels){
    unsigned char* pixel = &image[(y*width + x)*4];

    // Edit these [red, green, blue, alpha / transparency] values below (values between 0 and 255):
    pixel[0] = pixels[0];
    pixel[1] = pixels[1];      
    pixel[2] = pixels[2];
    pixel[3] = pixels[3]; //alpha
}

float Image::getPixelFloat(int x, int y) const {
    unsigned char* pixel = &image[(x + width*y)*4];
    return *reinterpret_cast<float*>(pixel);
}

void Image::setPixelFloat(int x, int y, float value){
    unsigned char* pixel = &image[(x + width*y)*4];
    *reinterpret_cast<float*>(pixel) = value;
}