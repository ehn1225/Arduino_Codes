#include <SoftwareSerial.h> //HC-06을 디지털 핀에 사용하기 위해 사용합니다.
#include<Ultrasonic.h>

bool is_on = false;
bool safe_on = false;
bool siren_led = false;
char command;
int speedvalue = 250;
long interval = 150; 

int boozer = 4;
int E1 = 10;
int M1 = 12; // 배터리 기준 왼쪽
int E2 =11;
int M2 = 13; // 배터리 기준 오른족
SoftwareSerial MyBT(2,3); //HC-06의 TX는 uno의 디지털 2번에. RX는 디지털 3번에 연결합니다

void setup()
{
  
  pinMode(boozer, OUTPUT); 
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  MyBT.begin(9600);
}

void loop(){
  
  if(is_on){ //전조등
      siren();
  }
  else if(!digitalRead(7) || !digitalRead(8)){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  int distance = getDistance(6,5);
  //getDistance(trig_pin,echo_pin)
  if(distance < 20 && safe_on){
    back();
  }
  
  if(MyBT.available()){ 
    command = MyBT.read(); 
    switch(command){
    case 'F'://직진
      forward();
      break;
    case 'B'://후진
       back();
      break;
    case 'L'://좌회전
      left();
      break;
    case 'R'://우회전
      right();
      break;
   case 'W'://전조등
      if(is_on){
         is_on = false;
       }
      else {
         is_on = true;
       }
      break;
   case 'S'://전조등
      if(safe_on){
        safe_on = false;
       }
      else {
        safe_on = true;
       }
      break;
case 'w'://전조등
      if(digitalRead(7)){
         digitalWrite(7, LOW);
          digitalWrite(8, LOW);
       }
      else {
digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
       }
      break;      
   case 'C'://크락션
      tone(boozer, 600, 300);
      break;
    }
  }
  delay(interval);
  Stop();
}
void forward() 
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speedvalue);
  analogWrite(E2, speedvalue);
}

void back()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, speedvalue);
  analogWrite(E2, speedvalue);
}

void left()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);
  analogWrite(E2, speedvalue);
}
void right()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speedvalue);
  analogWrite(E2, 0);
}
void Stop()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

void siren(){
        if(siren_led){
          digitalWrite(7, LOW);
          digitalWrite(8, HIGH);
          siren_led = false;
        }
        else{
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
          siren_led = true;
        }
        for(int i = 600; i < 1200; i+=10){
             tone(boozer, i, 50);
        }
}
