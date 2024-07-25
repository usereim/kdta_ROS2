//파일 읽어오기
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

String folder = "/home/jty6109/kdta_ROS2/opencv/data/";

int main()
{
    FileStorage fs; //파일 객체 생성
    String name;
    int age;
    Point pt;
    vector<float> v;
    Mat img;

    fs.open(folder + "myData.json", FileStorage::READ); // 읽기 모드로 파일 열기
    if (!fs.isOpened()) { 
        cerr << "file open failed" << endl;
        return -1;
    }

    //.json 파일에 키워드로 접근하여 데이터 저장
    fs["name"] >> name;
    fs["mat1"] >> img;
    fs["age"] >> age;
    fs["point"] >> pt;
    fs["vector"] >> v;

    fs.release(); //사용한 파일 닫기
    
    cout << name << endl;
    cout << age << endl;
    cout << pt << endl;
    cout << v[0] << v[1] << endl;

    imshow("img", img);
    waitKey(0);

    return 0;
}