#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

int main()
{
    cv::Mat image = ("path to image", CV_LOAD_IMAGE_GRAYSCALE);
    //find keypoints
    auto detector = cv::xfeatures2d::SurfFeatureDetector::create();
    std::vector<cv::KeyPoint>keypoints;
    detector->detect(image, keypoints);
    //present the keypoints on image
    cv::Mat image_with_keypoints;
    cv::drawKeypoints(image, keypoints, image_with_keypoints, (255,0,0), 4);
    // for visualization
    cv::namedWindow("Image with keypoints(4000 threshold)", cv::WINDOW_AUTOSIZE);
    cv::imshow("Image with keypoints(4000 threshold)", image_with_keypoints);
    // set the orientation of keypoints in the same direction
    detector->setUpright(true);
    detector->detect(image, keypoints);
    //present the keypoints on image
    cv::drawKeypoints(image, keypoints, image_with_keypoints, (255,0,0), 4);
    // for visualization
    cv::namedWindow("Image with keypoints(Oriented in same direction)", cv::WINDOW_AUTOSIZE);
    cv::imshow("Image with keypoints(Oriented in same direction)", image_with_keypoints);
    //find descriptors
    auto extractor = cv::xfeatures2d::SurfDescriptorExtractor::create();
    cv::Mat descriptors;
    extractor->compute(image, keypoints, descriptors);
    cv::namedWindow("Surf image as vector", cv::WINDOW_AUTOSIZE);
    cv::imshow("Surf image as vector", descriptors);
    // set the dimension of descriptor vector to 128
    extractor->setExtended(true);
    extractor->compute(image, keypoints, descriptors);
    cv::namedWindow("Surf image as vector(128-dim)", cv::WINDOW_AUTOSIZE);
    cv::imshow("Surf image as vector(128-dim)", descriptors);
    cv::waitKey(0);
    return 0;
    
       
}
