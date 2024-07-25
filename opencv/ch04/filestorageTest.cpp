//파일에 데이터 저장하기
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255));
    FileStorage fs; //파일 객체 생성

    fs.open(folder + "myData.json", FileStorage::WRITE); // 파일 열기
    if (!fs.isOpened()) { 
        cerr << "file open failed" << endl;
        return -1;
    }

    String name = "name";
    int age = 24;
    Point pt1(30, 40);
    vector<float> v = {1.2, 4.5, 3.14};
    Mat mat1 = imread(folder + "lenna.bmp");

    fs << "name" << name; //파일 저장
    fs << "age" << age;
    fs << "point" << pt1;
    fs << "vertor" << v;
    fs << "mat1" << mat1;

    fs.release(); //사용한 파일 닫기

    return 0;
}