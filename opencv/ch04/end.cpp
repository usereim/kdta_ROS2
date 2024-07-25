#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

void onMouse(int event, int x, int y, int flags, void *data);
struct Mydata {
    Point ptOld;
    Point ptNew;
    Mat img;
    bool flag = false;
};

int main()
{
    Mydata myData;
    myData.img = imread(folder + "lena.bmp");
    //rectangle(myData.img, Rect(0, 0, 50, 50), Scalar(0, 255, 255), 2);

    namedWindow("img");
    setMouseCallback("img", onMouse, (void *)&myData);

    imshow("img", myData.img);
    waitKey(0);
    destroyAllWindows();

    return 0;
}

void onMouse(int event, int x, int y, int flags, void *data)
{
    Mydata *ptr = (Mydata *)data;
    switch(event) {
        case EVENT_LBUTTONDOWN:
            cout << "BGR data : ";
            break;
        case EVENT_MOUSEMOVE:
            rectangle(ptr->img, Rect(x, y, 50, 50), Scalar(0, 255, 255), 2);
            imshow("img", ptr->img);
            break;
    }
}