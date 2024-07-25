#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Mat src = imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    vector<Mat> dsts;
    int ksize = 5;
    
    for (int ksize = 3; ksize <= 19; ksize += 2) {
        Mat dst;
        blur(src, dst, Size(ksize, ksize));
        dsts.push_back(dst);
    }
    

    imshow("src", src);
    int i = 0;
    for (auto dst : dsts) {
        imshow("dst" + to_string(i), dst);
        ++i;
    }

    waitKey(0);
    return 0;
}