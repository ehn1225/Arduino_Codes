#include <Wire.h>
//초음파 센서 참고자료 : http://dokkodai.tistory.com/104

int trigPin = 3;
int echoPin = 2;

void setup()
{
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT); // 센서 Trig 핀
	pinMode(echoPin, INPUT);  // 센서 Echo 핀
}

void loop()
{
	digitalWrite(trigPin, HIGH);  // 센서에 Trig 신호 입력
	delayMicroseconds(10);  // 10us 정도 유지
	digitalWrite(trigPin, LOW);   // Trig 신호 off

	long duration = pulseIn(echoPin, HIGH);    // Echo pin: HIGH->Low 간격을 측정
	long distance = duration / 29 / 2;  // 거리(cm)로 변환
	
	//초음파센서가 2000cm 이상 거리를 측정할 경우 오류로 판단
	if(distance >= 2000)
	{
		distance = 0;
	}
	
	//시리얼 모니터에 초음파 센서로 측정한 거리를 cm 단위로 표시
	Serial.print(distance);
	Serial.println(" cm");
	delay(1000);
}
