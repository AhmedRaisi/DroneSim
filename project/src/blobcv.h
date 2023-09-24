/**
 * @file hysteresis_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */
#ifndef DRONE_H_
#define DRONE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
using namespace cv;
#include <iostream>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is the blob detection class that uses opencv to detect blobs.
 *
 */

class BlobDetector
{
    public:
    /**
    * @brief This method takes an old image detects the keypoints and draws them onto new image
    *         
    * @return Does not return any value just updates newimage
    */
        void DetectBlobs(const char* oldimage, const char* newimage);

    private:
        std::vector<KeyPoint> keypoints; 
};

#endif