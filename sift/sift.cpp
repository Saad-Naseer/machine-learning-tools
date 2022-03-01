
#include <iostream>
#include <vector>
#include <opencv2/highhui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

int main()
{
    cv::Mat image = cv::imread("/home/saad/Desktop/saad.jpg");
    auto detector = cv::xfeatures2d::SiftFeatureDetector::create();
    std::vector<cv::KeyPoint>keypoints;
    detector->detect(image, keypoints);
    cv::Mat image_with_keypoints;
    cv::drawKeypoints(image, keypoints, image_with_keypoints);
    auto extractor = cv::xfeatures2d::SiftDescriptorExtractor::create();
    cv::Mat descriptors;
    extractor->compute(image, keypoints, descriptors);
    cv::namedWindow("image with keypoints", cv::WINDOW_AUTOSIZE);
    cv::imshow("image with keypoints", image_with_keypoints);
    cv::namedWindow("Sift vector as image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Sift vector as image", descriptors);
    cv::waitKey(0);
    return 0;
}
