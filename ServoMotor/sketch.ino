#include <Servo.h>
int potpin = A0;
int servopin = 9;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
int val = analogRead(potpin);
val = map(val, 0, 1023, 0, 180);
myservo.write(val);
delay(15);
}
