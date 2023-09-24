/*! \mainpage Drone filters
 *
 * \section This file contains filter created for the drone in Itiration 1.
 *
 *A brief description of the project:
 * This is a file containing filters created for the drone project. The drone is a rescue drone that help rescue humans and animals form danger.
 * The drone uses filters to process the image it is caputing to help identify the distance and the surroundings of the rescue object.
 * We have created filters that is used by the drone to process the images. This is part of iteration 1.
 *
 *How to build and run the project:
 * The folder contains a makefile that makes the files for the filters. The call commands are available at calls.txt. 
 * To run the project you have to follow the following steps:
 * -Open terminal 
 * -cd to the project file->src
 * -type <make> in terminal 
 * -type <./image_processor pics/statue.png canny pics/statue-canny.png> in terminal
 * The last call runs the project, which runs all the filters, it is the last call in image_processor calls which is located 
 * in call.txt in the src folder. 
 * To run individual filters, you do the following:
* -Open terminal 
 * -cd to the project file->src
 * -type <make> in terminal 
 * -type one of the image processor calls in calls.txt based on the filter you want to run.
 *
 *A brief overview of the main classes:
 * Image class:
 *  This class is the Image class which contains the main methods and constructors to modify or create an image.

 * Filter class: 
 *  In this class , we have created the Apply method that was used by the other filters which allows them to access an image modify it then output an image(or two).

 * Greyscale filter class: 
 *  This class takes two images, original and filtered, and applies the greyscale filter to the original image and sets the filtered image to that image.

 * Gausssian filter class: 
 *   This class takes two images, original and filtered, and applies the gaussian filter to the original image and sets the filtered image to that image.
 *   It does this by taking a kernal and reduce the noise in the image.

 * Sobel filter class: 
 *  This class takes two images , original and filtered and applies a sobel filter on to the original image and outputs two filtered images from it. 
 *  It does this by taking a kernel and modifies the intensity and the direction of the image. Those two images(intensity and direction) are later used by the double threshold filter.

 * Non-max suppression filter class:
 *   This class takes two images, original and filtered, and applies the Non-max suppression filter to the original image and sets the filtered image to that image.
 *   It does this by eliminating fuzzy edges by keeping the strongest pixel. 

 * Double threshold filter class:
 *   This class takes two images, original and filtered, and applies the Non-max suppression filter to the original image and sets the filtered image to that image.
 *   It does this by making each pixel a strong value if it is greater than the strong threshold and vise-versa.

*  Hysteresis filter class: 
 *  This class takes two images, original and filtered, and applies the hysteresis filter to the original image and sets the filtered image to that image.
 *  It does this by going through  each pixel in the input image and if it's strong,
 *  we make it strong in the resulting image. If it's weak but is neighboring a strong pixel,
 *  then we make it strong in the resulting image. Otherwise we make it zero. This helps
 *  recognize softer edges in an image.
 *
 * Canny filter class:
 *  This class takes two images, original and filtered, and applies all the above filters in order to the original image and sets the filtered image to that image.
 *  It does this by taking the output of the first filter and sets it to the input of the second one. It does this to all the filters.

 * YaqdhanFilter class:
 *   This class takes two images, original and filtered, and applies the Yaqdhan's filter to the original image and sets the filtered image to that image.
 *   Yaqdhan's filter takes a kernal and changes the blue pixel value slightly using Random.

 * MeanFilter class:  
 *  This class takes two images, original and filtered, and applies the MeanFilter to the original image and sets the filtered image to that image.
 *  In this class , i looped through each pixel and modified the RGB values through an equation. I then saved those new pixels to the output image.
 *
 * How to start extending the system:
 *  To add new filters to the system , we first need to create a header file that that inherits the Apply function from filter.h and add whatever other functions and variables are needed for our implementation. we need to make sure to include the required header files for our program to run
 *  we would then need to create a .cc file that does the implementation. we need to make sure that we included all the required files.
 *  to test our files we could add a similar call to other functions in the main.cc file. We first need to include our header file and then name our filter a familiar name and and set up its respective unique pointer. We could then call our file in the terminal and check the output. If we were happy with our output
 *  we would then add it in the canny edge filter to extend our system. we should decide what input it needs and whats the best use of its output. When deciding its targets we could add the new filter to the canny edge by modifying a few system lines then running the code to check if our output is accurate or not.
 */
 
