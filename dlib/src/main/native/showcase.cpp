#include "showcase.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <opencv2/opencv.hpp>

#include <dlib/array2d.h>
#include <dlib/opencv.h>
#include <dlib/pixel.h>
#include <dlib/image_transforms.h>

#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>

#include <vector>

using namespace std;

void Showcase::displayImageUsingOpenCVInCpp(cv::Mat mat) {
    /*cv::Mat mat(height, width, CV_8UC3);
    mat.data = reinterpret_cast<unsigned char *>(data);*/

    cv::imshow("OpenCV", mat);
    cv::waitKey();
}

void Showcase::displayImageUsingDLibInCpp(cv::Mat mat) {
    /*cv::Mat mat(height, width, CV_8UC3);
    mat.data = reinterpret_cast<unsigned char *>(data);*/

    dlib::cv_image<dlib::bgr_pixel> image(mat);

    dlib::image_window window;
    window.clear_overlay();
    window.set_image(image);
    window.wait_until_closed();
}

void Showcase::drawCircleImageUsingOpenCVInCpp(int x, int y, int radius, int red, int green, int blue, cv::Mat mat) {
    /*cv::Mat mat(height, width, CV_8UC3);
    mat.data = reinterpret_cast<unsigned char *>(data);*/

    cv::Point center(x, y);
    cv::Scalar color(red, green, blue);

    cv::circle(mat, center, radius, color);
}

void Showcase::drawCircleImageUsingDLibInCpp(int x, int y, int radius, int red, int green, int blue, cv::Mat mat) {
    /*cv::Mat mat(height, width, CV_8UC3);
    mat.data = reinterpret_cast<unsigned char *>(data);*/

    dlib::cv_image<dlib::bgr_pixel> image(mat);

    dlib::dpoint center(x, y);
    dlib::bgr_pixel color(red, green, blue);
    dlib::draw_solid_circle(image, center, radius, color);
}

cv::Point Showcase::returnPoint(double x, double y) {
    return cv::Point(x, y);
}

cv::Rect Showcase::returnRect(cv::Point topLeft, cv::Point bottomRight) {
    return cv::Rect(topLeft, bottomRight);
}

std::vector<cv::Rect> Showcase::returnRects() {
    std::vector<cv::Rect> rects;
    cv::Rect rect0(5, 0, 0, 0);
    cv::Rect rect1(1, 1, 1, 1);
    rects.push_back(rect0);
    rects.push_back(rect1);
    return rects;
}