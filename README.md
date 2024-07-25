# kdta_ROS2
---
## 2024 - 07 - 25

1. 마우스 이벤트 처리
> setMouseCallback() 함수를 이용하여 이벤트를 처리할 콜백 함수 등록
> ex) setMouseCallback("img", onMouse, (void *)&mydata);
> EVENT_MOUSEMOVE, EVENT_LBUTTONDOWN등 마우스 이벤트 상수를 사용하여 발생한 이벤트에 대한 처리 가능

2. 트랙바
> createTrackbar() 함수를 사용하여 트랙바 생성
> ex) createTrackbar("level", "img", &a, 255, on_level_change, &img);
> 트랙바 콜백 함수를 사용하여 트랙바의 위치가 변경될 때마다 영상에 변화를 줄 수 있다.

3. FileStorage 클래스
- 데이터 파일 저장
> 1. FileStorage fs; // 파일 객체 생성
> 2. fs.open(folder + "myData.json", FileStorage::WRITE); // 파일을 쓰기 모드로 오픈
> 3. fs.isOpened() // 파일이 열렸는지 확인 열렸으면 true
> 4. fs << "name" << name; //파일 저장
> 5. fs.release(); // 사용한 파일 닫기

- 파일 데이터 읽기
> 1. fs.open(folder + "myData.json", FileStorage::READ); // 읽기 모드로 파일 열기
> 2. 키워드로 json파일의 데이터에 접근하여 데이터 저장
>   fs["키워드"] >> 저장할 데이터 변수;
>   fs["name"] >> name;
>   fs["mat1"] >> img;
>   fs["age"] >> age;
>   fs["point"] >> pt;
>   fs["vector"] >> v;

4. Mask 연산
> 마스크를 사용하여 영상의 특정부분의 값을 변경 할 수 있다.
> setTo(), copyTo() 함수를 이용하여 마스크 값을 영상에 적용한다.
> ex) lennaimg.setTo(yellow, maskSmile);

---
## 2024 - 07 - 24

1. Mat
>   >1) Mat::copyTo(OutputArray m) : 인자로 전달된 행렬에 자기 자신을 복사
>   >2) Mat::setTo(value) : 행렬 전체 원소를 value 값으로 설정
>   >3) ~Mat : Mat타입 객체 앞에 ~연산자를 사용하여 영상에 반전효과를 적용

---
## 2024 - 07 - 23

vmware install
terminator install
git install

## opencv install
---







