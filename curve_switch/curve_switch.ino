#include <AFMotor.h>

AF_DCMotor motor1(3); //Left motor (뒤에서 봤을때 기준입니다.) 실드에서 M3에 연결.
AF_DCMotor motor2(4); //Right motor (뒤에서 봤을때 기준입니다.) 실드에서 M4에 연결.

#define Speed 230  //기본 구동속도
int mode = 0;
void setup() {
  pinMode(1, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  
  
  if(mode == 0){
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
  }
  else if(mode == 1){//포인트턴
    motor1.setSpeed(Speed);
    motor1.run(FORWARD);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
  }
   else if(mode == 2){//스윙턴
    motor1.setSpeed(Speed);
    motor1.run(BACKWARD);
    motor2.setSpeed(Speed);
    motor2.run(FORWARD);
  }
   else if(mode == 3){//커브턴
    motor1.setSpeed(Speed);
    motor1.run(FORWARD);
    motor2.setSpeed(Speed/2);
    motor2.run(FORWARD);
  }

  if(!digitalRead(1)){
    if(mode == 3){
      mode = 0;
    }
    else{
      mode++;
    }
    Serial.println(mode);
    delay(200);
  }
}
