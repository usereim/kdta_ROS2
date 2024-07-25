#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Mat src = imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    vector<Mat> dsts;
    
    for (int alpha = 1; alpha <= 19; ++alpha) {
        Mat blurred, dst;
        GaussianBlur(src, dst, Size(0, 0), 3);
        dst = (1 + alpha) * src - alpha * blurred;
        dsts.push_back(dst);
    }
    
    imshow("src", src);
    int i = 1;
    for (auto dst : dsts) {
        imshow("dst" + to_string(i), dst);
        ++i;
    }

    waitKey(0);
    return 0;
}