#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void *data);

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{ 
    Mat src = imread(folder + "lena.bmp", IMREAD_GRAYSCALE);
    Mat add, center, minmaxDst, dst;
    double gmin, gmax;

    add = src + 50;
    center = src + (src - 125) * 1.0;
    minMaxLoc(src, &gmin, &gmax);
    minmaxDst = (src - gmin) *255 / (gmax - gmin);

    equalizeHist(src, dst);

    imshow("src", src);
    imshow("dst", dst);
    imshow("add", add);
    imshow("center", center);
    imshow("minmax", minmaxDst);
    
    waitKey(0);
    return 0;
}
