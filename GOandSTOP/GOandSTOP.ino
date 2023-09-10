// AFMotor.h 라이브러리가 기본적으로 설치되어 있어야 합니다. https://github.com/adafruit/Adafruit-Motor-Shield-library
#include <AFMotor.h>

AF_DCMotor motor1(3); //Left motor (뒤에서 봤을때 기준입니다.) 실드에서 M3에 연결.
AF_DCMotor motor2(4); //Right motor (뒤에서 봤을때 기준입니다.) 실드에서 M4에 연결.

/* 초음파 센서를 어디에 연결할지 정의합니다.
 * 뒤에서 봤을때를 기준으로 오른쪽은 R 왼쪽은 L입니다.
 * 초음파센서는 TRIG와 ECHO 두개의 핀이 있으며, 잘못 연결 할 경우 오작동합니다.(중요!!)
 */
#define R_TRIG 13  //Right sensor Trig는 디지털 핀 13번
#define R_ECHO 2  //Right sensor Echo는 디지털 핀 2번

//각각의 핀에 대해서 어떻게 사용할지 셋업합니다.
void setup() {
  pinMode(R_TRIG, OUTPUT);
  pinMode(R_ECHO, INPUT);
}

//초음파 센서로 거리를 감지 한 뒤 어떻게 행동할지 지정합니다.
void loop() {

 float duration1, duration2, distance1, distance2;
  digitalWrite(R_TRIG, LOW);
  delay(2);
  digitalWrite(R_TRIG, HIGH);
  delay(10);
  digitalWrite(R_TRIG, LOW);
  duration1 = pulseIn(R_ECHO, HIGH);
  distance1 = ((float)(340 * duration1) / 1000) / 2;
  
//10cm 이내에 장애물이 존재할 경우 멈춤
 if (distance1 < 10){
     stop();
   }
//아무것도 감지되지 않거나 장애물과의 거리가 10cm 이상일 경우에는 직진
  else{
     forward();
   }
}

/* forward 상태일때 모터를 전진시킵니다.
 * 속도는 상황에 맞게 조절가능하지만 변경하지 않는 것을 권장합니다.
 * 속도는 setSpeed()에서 괄호안의 값을 0~255까지 변경가능합니다.
 */
void forward()
{
  motor1.setSpeed(140);
  motor1.run(FORWARD);
  motor2.setSpeed(155);
  motor2.run(FORWARD);
}

void stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  delay(100);
}
