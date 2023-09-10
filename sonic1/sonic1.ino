#include<Ultrasonic.h>
//초음파를 쓰려면 필요합니다.

void setup() {
  // '//'이거 뒤에는 주석입니다. 
  //프로그램에 영향을 미치지않습니다.
  Serial.begin(9600);
  //Serial.begin(숫자)는 시리얼 통신을
  //시작한다는 뜻입니다.
}

void loop() {
  Serial.println(getDistance(3,2));
  //getDistance(trig_pin,echo_pin)
  //초음파센서로 측정한 거리를 cm단위로 알려줍니다.
  //Serial.end();
  //시리얼 통신을 종료한다는 뜻입니다.
  delay(200);
}
