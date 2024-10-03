# Arduino Servo Motor Sweep Project

This Arduino project demonstrates how to make a servo motor continuously sweep from 0 to 180 degrees and back. This is a basic servo motor control that does not require a breadboard, making it easy to implement.

## Project Setup

### Components Required:
- 1 Servo Motor
- Arduino Board (e.g., Uno, Nano, etc.)
- Jumper Wires

### Pin Assignments:
- **Servo Motor**: Connected to Digital Pin 9
- **Servo Motor's Power**: VCC connected to 5V, GND connected to GND on the Arduino

### Circuit Diagram:
- Connect the **control wire** (usually orange or white) of the servo motor to **pin 9** on the Arduino.
- Connect the **VCC** wire (usually red) to **5V** on the Arduino.
- Connect the **GND** wire (usually black or brown) to **GND** on the Arduino.
- ![image](https://github.com/user-attachments/assets/845398a3-c105-48ec-a596-605c84ec89f1)


### Code Explanation:
```cpp
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
//You can increse the  delay to decrese the sweep speed of the servo
  // Sweep from 180 back to 0 degrees
  for(pos = 180; pos >= 0; pos--) {
    myservo.write(pos);      // Set the servo position
    delay(15);               // Delay to allow the servo to reach the position
  }
}
