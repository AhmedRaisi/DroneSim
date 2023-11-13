#include "blobcv.h"



void DetectBlobs(const char* oldimage, const char* newimage)
{
     std::vector<KeyPoint> keypoints;
     //copy oldimage into oim, apply greyscale
     Mat oim = imread(oldimage, IMREAD_GRAYSCALE );  
     SimpleBlobDetector::Params params;
     
     // Change thresholds
     params.minThreshold = 10;
     params.maxThreshold = 200;

     // Filter by Area.
     params.filterByArea = false;
     params.minArea = 500;

     // Filter by Circularity
     params.filterByCircularity = false;
     params.minCircularity = 0.1;

     // Filter by Convexity
     params.filterByConvexity = true;
     params.minConvexity = 0.87;

     // Filter by Inertia
     params.filterByInertia = true;
     params.minInertiaRatio = 0.01;

     cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);
     detector->detect(oim, keypoints);
    //create detector from opencv library
    //SimpleBlobDetector detector;
    //create new image Mat
    Mat nim;
    //detect keypoints from old image and save to keypoints
    //detector.detect(oim, keypoints);
     
    // DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
    cv::drawKeypoints( oim , keypoints, nim, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS ); 
     //imshow("keypoints", nim );
     //cv::waitKey(0);
    imwrite(newimage, nim);

}