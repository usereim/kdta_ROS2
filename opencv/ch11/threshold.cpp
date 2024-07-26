#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Mat img = imread(folder + "neutrophils.png", IMREAD_GRAYSCALE);
    Mat src, dst;
    
    threshold(img, dst, 180, 255, THRESH_BINARY);
    threshold(img, dst, 0, 255, THRESH_OTSU);

    imshow("img", img);
    imshow("dst", dst);
    
    waitKey(0);
    return 0;
}