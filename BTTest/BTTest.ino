#include<SoftwareSerial.h>

SoftwareSerial mySerial(3,2);//(tx,rx)

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available())
  {
    Serial.write(mySerial.read());
  }
  if(Serial.available())
  {
    mySerial.write(Serial.read());
  }
}
