#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string folder = "/home/jty6109/kdta_ROS2/opencv/data/";
int main()
{
    Mat img;
    img = imread(folder + "lenna.bmp");
    namedWindow("lenna");
    imshow("lenna", img);
    int key = waitKey(0);
    cout << key << endl;
    destroyWindow("lenna");
    imshow("lenna", img);
    waitKey(0);

    return 0;
}