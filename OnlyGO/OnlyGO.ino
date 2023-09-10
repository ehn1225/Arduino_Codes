#include <AFMotor.h>

AF_DCMotor motor1(3); //Left motor (뒤에서 봤을때 기준입니다.) 실드에서 M3에 연결.
AF_DCMotor motor2(4); //Right motor (뒤에서 봤을때 기준입니다.) 실드에서 M4에 연결.
void setup() {
  // put your setup code here, to run once:

}

void loop() {
 motor1.setSpeed(200);
  motor1.run(FORWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
}
