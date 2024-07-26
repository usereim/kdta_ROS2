#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Mat img = imread(folder + "lena.bmp");
    Mat dst1, dst2;

    Canny(img, dst1, 50, 100);
    Canny(img, dst2, 100, 150);

    imshow("img", img);
    imshow("dst1", dst1);
    imshow("dst2", dst2);
    
    waitKey(0);

    return 0;
}