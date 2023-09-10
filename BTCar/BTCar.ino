#include <AFMotor.h>
#include <SoftwareSerial.h> //HC-06을 디지털 핀에 사용하기 위해 사용합니다.
 
bool is_on = false;
char command; 

AF_DCMotor motor1(3); //Left motor (뒤에서 봤을때 기준입니다.) 실드에서 M3에 연결
AF_DCMotor motor2(4); //Right motor (뒤에서 봤을때 기준입니다.) 실드에서 M4에 연결

SoftwareSerial MyBT(3,2); //HC-06의 RX는 uno의 디지털 5번에 TX는 uno의 디지털 6번에 연결합니다.


void setup() 
{       
  
  Serial.begin(9600);
  MyBT.begin(9600);
  
    pinMode(4, OUTPUT); //부저 사용을 위한 연결 부분
    pinMode(9, OUTPUT); 
    pinMode(10, OUTPUT); 
}

/*어플에서 값이 전송될 경우에 입력되는 내용에 따라서 구동하도록 되어있습니다.
 * 예로 어플에서 전진을 누르면 실제 보드에서는 F라는 문자가 입력되므로
 * F가 입력될 경우에 전진하도록 되어있습니다.
 */
void loop(){
  if(is_on){
    digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
    }
  else {
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
  }
  if(MyBT.available() > 0){ 
    command = MyBT.read(); 
    switch(command){
    case 'F':  
      forward(); // F가 입력될 경우 forward를 실행합니다. forward는 아래에서 지정했습니다.
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
   case 'W':  
      if(is_on){
         is_on = false;
       }
      else {
         is_on = true;
       }
      break;
   case 'C':
      tone(4, 600, 600);
      break;
    }
   
   delay(100);
   Stop();
   command = "";
  } 
 
  
}


/*forward가 실행될 때는 양쪽 모터가 모두 전진하도록 입력되어 있습니다.
 * 속도를 조절하고 싶다면 아래의 setSpeed에서 () 괄호안의 값을 0~255까지
 * 입력해서 조절가능합니다.
 */
void forward() 
{
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  motor2.setSpeed(200);
  motor2.run(FORWARD);
}

//후진시에는 run뒤의 괄호에 BACKWARD로 입력을 하면 모터가 반대방향으로 회전합니다.
void back()
{
  motor1.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.setSpeed(200);
  motor2.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(210);
  motor2.run(FORWARD);
;
}

void right()
{
  motor1.setSpeed(200);
  motor1.run(FORWARD);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}
