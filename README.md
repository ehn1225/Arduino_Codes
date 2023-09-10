# Arduino_Codes
### 교육부 교육봉사 프로그램에서 사용한 아두이노 코드 모음
- 아두이노를 이용한 프로그래밍 교육 및 자동차 만들기에 사용한 소스 코드입니다.
- 개발 일자 : 2018.11(함성소리), 2019.07(쏙쏙캠프)
- 개발 환경 : Arduino IDE
    - Arduino uno R3
    - HC-SR04 : 초음파센서
    - HC-06 : 블루투스 모듈
    - ALP 1205 : 피에조 부저
    - L298P : 아두이노 모터 쉴드

## 코드 설명
### Ultrasonic.h, Ultrasonic.cpp
- 초음파 센서를 쉽게 사용하기 위해 만든 라이브러리
- ```getDistance()``` 함수를 사용하여 거리를 측정할 수 있음
- long getDistance(int trigPin, int echoPin)
    - 리턴 타입 : long
    - 함수명 : getDistance
    - 매개변수 : int trigPin, int echoPin

### BTTest
- 블루투스 모듈(HC-06) 테스트 코드
- 시리얼 모니터를 통해 블루투스 모듈과 통신할 수 있음

### BTCar
- 블루투스를 이용하여 스마트폰으로 자동차 제어
- HC-06 블루투스 모듈을 이용하여 블루투스 통신 수행
- AFMotor 라이브러리를 이용하여 모터 제어

### BTCar_final_ITS
- BTCar 코드를 기반으로 수정한 코드
- 초음파 센서를 이용한 전방 추돌 방지, 크락션, 전조등 기능 추가

### curve_switch
- 자동차의 회전 방법(포인트턴, 스윙턴, 커브턴)을 학습하기 위한 코드
- 스위치를 이용하여 회전 방법을 선택할 수 있음

### piano
- 버튼 8개와 피에조 부저를 이용하여 만든 피아노

### domisol
- 초음파 센서를 이용하여 거리에 따라 도, 레, 미, 파, 솔, 라 소리를 내는 코드
- 초음파센서와 피에조 부저가 필요함

### OnlyGO
- 모터 쉴드 및 모터 연결 상태를 확인하기 위해 양 바퀴가 직진만 하는 코드

### GOandSTOP
- 초음파 센서를 이용하여 앞에 장애물이 없다면 직진하고, 장애물이 있을 경우 정지합니다.

### led-112
- ```delay()``` 함수를 이용하여 LED를 깜빡이는 코드
- 경찰차의 경광등처럼 깜빡이는 효과를 내기 위해 만든 코드

### led-112-panel
- 위와 동일한 기능 수행
- 연결된 LED의 수량을 늘리고, 반복문을 사용하여 구현

### microwave_senser
- 초음파 센서를 이용하여 거리를 측정하고, 거리를 시리얼 모니터에 출력하는 코드

### sonic1
- 초음파 센서를 이용하여 거리를 측정하고, 거리를 시리얼 모니터에 출력하는 코드
- 위와 동일하나, 초음파센서를 쉽게 사용하기 위해 ```Ultrasonic``` 라이브러리를 만듦으로써, ```getDistance()``` 함수를 사용하여 거리를 측정함
- 함수를 하나만 호출함으로써 쉽게 거리를 알 수 있음

### sonic2
- 초음파 센서를 이용한 아두이노 프로그래밍 교육 자료
- 직접 조건문과 함수 호출하는 것을 실습해보도록 공란을 만들어 놓음

## Images
<img src="https://github.com/ehn1225/Arduino_Codes/assets/5174517/4814b5f7-9ff9-4954-89b2-c86ac5ac0f24"  width="700"/>
<img src="https://github.com/ehn1225/Arduino_Codes/assets/5174517/49a1fb49-80c5-47a5-9956-5c695ebbbbb0"  width="700"/>
<img src="https://github.com/ehn1225/Arduino_Codes/assets/5174517/c0869619-cb21-465b-8884-10cc25685b2e"  width="700"/>

## Reference
- [AFMotor 라이브러리](https://learn.adafruit.com/adafruit-motor-shield/library-install)