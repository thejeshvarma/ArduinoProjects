int green = 13;
int red = 11;
int yellow = 12;
void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(5000);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(5000);
  digitalWrite(red, LOW);
}
