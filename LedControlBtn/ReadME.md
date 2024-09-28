# Arduino LED Control with Button

This project demonstrates a simple setup to control an LED using a push button with an Arduino. When the button is pressed, the LED turns on; when the button is released, the LED turns off.

## Components Required

- 1 x Arduino (e.g., Arduino Uno)
- 1 x LED
- 1 x Push Button
- 2 x Resistors (appropriate values for LED and button, typically 220Ω for LED and 10kΩ for button pull-down)
- Breadboard and jumper wires

## Circuit Diagram

![image](https://github.com/user-attachments/assets/351a4449-1e01-4eee-b5f1-6ac70bb14ec7)


## Pin Configuration

- **LED Pin:** Connected to digital pin 8 on the Arduino.
- **Button Pin:** Connected to digital pin 7 on the Arduino.

## Code Explanation

This Arduino sketch reads the state of a button connected to pin 7 and uses it to control an LED connected to pin 8.

### Code Walkthrough

1. **Pin Initialization:**
   - `ledpin`: Represents the pin connected to the LED (set to 8).
   - `btnpin`: Represents the pin connected to the button (set to 7).

2. **Setup Function:**
   - `pinMode(ledpin, OUTPUT)`: Sets the LED pin as an output so the Arduino can control it.
   - `pinMode(btnpin, INPUT)`: Sets the button pin as an input to detect button presses.

3. **Loop Function:**
   - Continuously checks if the button is pressed using `digitalRead(btnpin)`.
   - If the button is pressed (`HIGH`), the LED is turned on.
   - If the button is not pressed (`LOW`), the LED is turned off.

### Code

```cpp
int ledpin = 8;  // Pin for the LED
int btnpin = 7;  // Pin for the button

void setup() {
  // Initialize LED pin as OUTPUT and button pin as INPUT
  pinMode(ledpin, OUTPUT);
  pinMode(btnpin, INPUT);
}

void loop() {
  // Check the button state
  if (digitalRead(btnpin) == HIGH) {
    // If button is pressed, turn on the LED
    digitalWrite(ledpin, HIGH);
  } else {
    // If button is not pressed, turn off the LED
    digitalWrite(ledpin, LOW);
  }
}
