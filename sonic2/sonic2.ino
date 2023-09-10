#include<Ultrasonic.h>
//초음파 센서를 쓰려면 필요

void setup() {
  Serial.begin(9600);
  /시리얼통신을 시작한다는 뜻
}

void loop() {
  //초음파 센서가 알려주는 거리가 50cm이하면 
  //소리를 내기 시작해서 가까워질수록 소리사이
  //간격이 짧아 지도록하자
  
  int distance = getDistance(2,3);
  //숫자형 변수 distance에 getDistacne(trigPin,echoPin)이 알려주는 숫자를 저장
  
  if( distance < ??? )//거리가 50cm미만이면 { }안의 내용이 실행
  {
    tone(8, 500, 100);//8번 핀에 연결된 부저에서 500Hz로 0.1초간 소리를 냄
    delay( ??? );         //delay(숫자) 숫자/1000 초 만큼 쉼
  }
  Serial.println(distance);//distance에 저장된 숫자를 시리얼모니터에 출력
}
