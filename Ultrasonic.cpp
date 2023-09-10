#include "Arduino.h"
#include "Ultrasonic.h"

long getDistance(int trigPin, int echoPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	long duration = pulseIn(echoPin, HIGH);
	long distance = duration / 29 / 2;

	return distance;
}
