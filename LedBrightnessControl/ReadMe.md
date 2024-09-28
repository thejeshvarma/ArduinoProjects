# Arduino LED Brightness Control Using a Potentiometer

This project demonstrates how to control the brightness of an LED using a potentiometer with an Arduino. As you rotate the potentiometer, the brightness of the LED will change accordingly.

## Components Required

- 1 x Arduino (e.g., Arduino Uno)
- 1 x LED
- 1 x Potentiometer (e.g., 10kΩ)
- 1 x Resistor (220Ω for current-limiting the LED)
- Breadboard and jumper wires

## Circuit Diagram

![image](https://github.com/user-attachments/assets/7f6d7819-ee7d-4d29-8282-9b5dcc3236f2)


## Pin Configuration

- **LED Pin:** Connected to digital pin 9 on the Arduino.
- **Potentiometer Pin:** Connected to analog pin A0 on the Arduino.

## Code Explanation

This Arduino sketch reads the value of a potentiometer (variable resistor) connected to analog pin A0 and adjusts the brightness of an LED connected to digital pin 9 accordingly.

### Code Walkthrough

1. **Pin Initialization:**
   - `ledpin`: Represents the pin connected to the LED (set to 9).
   - `potpin`: Represents the analog pin connected to the potentiometer (set to A0).

2. **Setup Function:**
   - `pinMode(ledpin, OUTPUT)`: Sets the LED pin as an output to control the brightness.
   
   The potentiometer pin doesn't need to be initialized, as `analogRead()` will automatically configure it as an input.

3. **Loop Function:**
   - `analogRead(potpin)` reads the value from the potentiometer (0 to 1023).
   - `brightness = potval / 4` maps the potentiometer value to a range of 0 to 255 (suitable for controlling LED brightness via PWM).
   - `digitalWrite(ledpin, brightness)` sets the LED brightness according to the potentiometer position.

### Code

```cpp
int ledpin = 9;      // Pin for the LED
int potpin = A0;     // Pin for the potentiometer

void setup() {
  pinMode(ledpin, OUTPUT);   // Initialize the LED pin as an output
}

void loop() {
  int potval = analogRead(potpin);    // Read potentiometer value (0-1023)
  int brightness = potval / 4;        // Convert to a 0-255 range for brightness
  digitalWrite(ledpin, brightness);   // Set the LED brightness
}
