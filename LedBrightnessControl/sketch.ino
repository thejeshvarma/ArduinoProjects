int ledpin = 9;
int potpin = A0;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int potval = analogRead(potpin);
 int brightness = potval/4;
 digitalWrite(ledpin,brightness);
}
