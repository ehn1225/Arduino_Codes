int boozer = 12;

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i < 10; i++){
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(boozer, OUTPUT);

}

void loop() {
    if(!digitalRead(9)) //도
    tone(boozer, 1046, 100);
    else if(!digitalRead(8)) //시
    tone(boozer, 988, 100);
    else if(!digitalRead(7)) //라
    tone(boozer, 880, 100);
    else if(!digitalRead(6)) //솔
    tone(boozer, 784, 100);
    else if(!digitalRead(5)) //파
    tone(boozer, 698, 100);
    else if(!digitalRead(4)) //미
    tone(boozer, 659, 100);
    else if(!digitalRead(3)) //레
    tone(boozer, 587, 100);
    else if(!digitalRead(2)) //도
    tone(boozer, 524, 100);
}
