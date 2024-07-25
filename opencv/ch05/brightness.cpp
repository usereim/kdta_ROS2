#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void *data);

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat img = imread(folder + "lena.bmp", IMREAD_COLOR);
    Mat imgGray = imread(folder + "lena.bmp", IMREAD_GRAYSCALE);

    Mat imgCvtGray;
    cvtColor(img, imgCvtGray, COLOR_RGB2GRAY);
    Mat imgAdd = imgGray + 50;
    Mat imgAddCenter = imgGray + (imgGray - 125) * 1.0;

    imshow("img", img);
    imshow("gray", imgGray);
    imshow("cvtgray", imgCvtGray);
    imshow("imgAdd", imgAdd);
    imshow("imgAddCenter", imgAddCenter);

    waitKey(0);
    return 0;
}
