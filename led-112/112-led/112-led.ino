int term = 100;
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(term);
  digitalWrite(8, LOW);
  delay(term);
  digitalWrite(8, HIGH);
  delay(term);
  digitalWrite(8, LOW);
  delay(term);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(term);
  digitalWrite(9, LOW);
  delay(term);
  digitalWrite(9, HIGH);
  delay(term);
  digitalWrite(9, LOW);
  delay(term);  
}
