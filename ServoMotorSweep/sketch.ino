#include <Servo.h>   // Include the Servo library

int servopin = 9;    // Servo motor control pin connected to digital pin 9
int pos = 0;         // Variable to store the servo position
Servo myservo;       // Create a Servo object

void setup() {
  myservo.attach(servopin);  // Attach the servo to pin 9
}

void loop() {
  // Sweep from 0 to 180 degrees
  for(pos = 0; pos <= 180; pos++) {
    myservo.write(pos);      // Set the servo position
    delay(15);               // Delay to allow the servo to reach the position
  }

  // Sweep from 180 back to 0 degrees
  for(pos = 180; pos >= 0; pos--) {
    myservo.write(pos);      // Set the servo position
    delay(15);               // Delay to allow the servo to reach the position
  }
}
