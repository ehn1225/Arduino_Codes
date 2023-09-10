int term = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i = 0; i < 2; i++){
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(term);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(term);
 }

  for(int i = 0; i < 2; i++){
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(term);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(term);
 }
}
