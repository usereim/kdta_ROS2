#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    //Mat roi ex
    Mat img1 = imread(folder + "lenna.bmp");
    Rect rc(100, 50, 50, 50);
    Mat img2 = img1(rc);
    Mat img3 = img1(rc).clone();

    img2 = ~img2;
    //img2.setTo(Scalar(0, 255, 255));

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    waitKey(0);

    return 0;
}