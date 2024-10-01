# Arduino Servo Motor Control Project

This Arduino project demonstrates how to control a servo motor using a potentiometer. The position of the potentiometer is read as an analog input and mapped to the corresponding angle for the servo motor.

## Project Setup

### Components Required:
- 1 Servo Motor
- 1 Potentiometer
- Arduino Board (e.g., Uno, Nano, etc.)
- Jumper Wires
- Breadboard (optional for prototyping)

### Pin Assignments:
- **Potentiometer**: Connected to Analog Pin A0
- **Servo Motor**: Connected to Digital Pin 9
- **Potentiometer's Other Pins**: One to 5V and one to GND

### Circuit Diagram:
- Connect the middle pin of the potentiometer to **A0** on the Arduino.
- Connect one of the outer pins of the potentiometer to **5V** and the other outer pin to **GND**.
- Connect the servo motor's control wire (usually the orange or white wire) to **pin 9**.
- Connect the servo motor’s **VCC** (usually red wire) to **5V** and **GND** (usually black or brown wire) to **GND**.
- ![image](https://github.com/user-attachments/assets/664183a7-2806-42cf-bac0-8d98c10b9d03)


### Code Explanation:
```cpp
#include <Servo.h>   // Include the Servo library

int potpin = A0;     // Potentiometer is connected to analog pin A0
int servopin = 9;    // Servo motor control pin connected to digital pin 9
Servo myservo;       // Create a Servo object

void setup() {
  myservo.attach(servopin);  // Attach the servo to pin 9
}

void loop() {
  int val = analogRead(potpin);      // Read the potentiometer value (0 to 1023)
  val = map(val, 0, 1023, 0, 180);   // Map the potentiometer value to a range of 0 to 180 degrees
  myservo.write(val);                // Set the servo position based on the mapped value
  delay(15);                         // Delay for smooth movement
}
