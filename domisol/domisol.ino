#include<Ultrasonic.h>
//초음파를 쓰려면 필요합니다.
#define A 540

void setup() {
  Serial.begin(9600);
  pinMode(10,INPUT_PULLUP);
}

void loop() {
  int distance = getDistance(3,2);

    Serial.println(distance);
    if(distance >= 33) //라
    tone(8, 880, 100);
    else if(distance >= 30) //솔
    tone(8, 784, 100);
    else if(distance >= 27) //파
    tone(8, 698, 100);
    else if(distance >= 24) //미
    tone(8, 659, 100);
    else if(distance >= 21) //레
    tone(8, 587, 100);
    else if(distance >= 16) //도
    tone(8, 524, 100);

  delay(50);
}
