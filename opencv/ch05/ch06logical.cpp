#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void *data);

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{ 
    Mat src = imread(folder + "lenna256.bmp", IMREAD_GRAYSCALE);
    Mat src2 = imread(folder + "square.bmp", IMREAD_GRAYSCALE);

    Mat dst1, dst2, dst3, dst4;

    bitwise_and(src, src2, dst1);
    bitwise_or(src, src2, dst2);
    bitwise_xor(src, src2, dst3);
    bitwise_not(src, dst4);

    imshow("src", src);
    imshow("src2", src2);
    imshow("dst1", dst1);
    imshow("dst2", dst2);
    imshow("dst3", dst3);
    imshow("dst4", dst4);

    waitKey(0);
    return 0;
}
