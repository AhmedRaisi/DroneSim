/**
 * @file hysteresis_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef IMAGE_H
#define IMAGE_H
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is the Image class which contains the main methods to modify or creat an image.
 *
 */

class Image{
    public:
    unsigned char* image;
    /**
    * @brief This Image constructor takes no arguments and it creates an empty image.
    *         
    * @return This Image function does not return any value.
    */

    Image();
    /**
    * @brief This Image constructor takes two arguments the width and the height and it creates an image with those dimentions.      
    * @return This Image function does not return any value.
    */

    Image(int width,int height);
    /**
    * @brief This Image constructor takes one arguments which is the filename which is an input image.      
    * @return This Image function does not return any value.
    */

    Image(unsigned char* input_image, int width, int height);
    
    Image(const char* filename);
    /**
    * @brief This is a destructor that deletes the image from the memory.
    *         
    * @return The image destructor does not return any value.
    */
    ~Image();
    /**
    * @brief The = operator funtion sets the height, width and components of one image to the other.
    *         
    * @return This function does not return any value.
    */
    void operator=(const Image& other_image);
    /**
    * @brief The SaveAs function takes one argument and saves the image in the argumwnt name.
    *         
    * @return This function retuens an integer value.
    */
    int SaveAs(const char* filename);
    /**
    * @brief The GetHeight function takes no arguments and it gives the height value.
    *         
    * @return This function returns the height value of the image.
    */
    int GetHeight();
    /**
    * @brief The GetWidth function takes no arguments and it gives the width value.
    *         
    * @return This function returns the width value of the image.
    */
    int GetWidth();
    /**
     * @brief The GetComponentNum function takes no arguments and it gives the hnumber of components in the pixel.
    *         
    * @return Theis function returns the component number of the pixel.
    */
    int GetComponentNum();
    /**
    * @brief The GetPixel funtion takes two arguments which are the x and y values of the pixel location in the image.
    *         
    * @return This funtion returns the pixel at the specific location.
    */
    unsigned char* GetPixel(int x,int y);
    /**
    * @brief The SetPixel funtion takes two arguments which are the x and y values of the pixel location and sets the pixel in that location in the in the image.
    *         
    * @return This funtion returns no value.
    */
    void SetPixel(int x,int y,unsigned char* pixels);
    /**
     * @brief The GetPixelFloat funtion takes two arguments which are the x and y values of the pixel location in the image.
    *         
    * @return This funtion returns the pixel in float type at the specific location.
    */
    float getPixelFloat(int x, int y) const;
    /**
    * @brief The SetPixelfloat funtion takes two arguments which are the x and y values of the pixel location and sets the pixel in float type in the specifix location in the image.
    *         
    * @return This funtion returns no value.
    */
    void setPixelFloat(int x, int y, float value);
    int width, height , components;
};
#endif