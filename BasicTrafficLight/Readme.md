# Arduino Traffic Light Simulation

This project simulates a basic traffic light system using an Arduino. The system cycles through green, yellow, and red LEDs, mimicking the behavior of a real traffic signal. Each light stays on for 5 seconds before switching to the next.

## Components Required

- 1 x Arduino (e.g., Arduino Uno)
- 1 x Green LED
- 1 x Yellow LED
- 1 x Red LED
- 3 x Resistors (typically 220Ω for current-limiting each LED)
- Breadboard and jumper wires

## Circuit Diagram

![image](https://github.com/user-attachments/assets/d3e25ca9-0c14-4280-8acf-7722c786470c)


## Pin Configuration

- **Green LED:** Connected to digital pin 13 on the Arduino.
- **Yellow LED:** Connected to digital pin 12 on the Arduino.
- **Red LED:** Connected to digital pin 11 on the Arduino.

## Code Explanation

This Arduino sketch controls three LEDs (green, yellow, and red) to simulate a traffic light system. Each LED turns on and off in sequence with a 5-second delay between each transition.

### Code Walkthrough

1. **Pin Initialization:**
   - `green`: Represents the pin connected to the green LED (set to 13).
   - `yellow`: Represents the pin connected to the yellow LED (set to 12).
   - `red`: Represents the pin connected to the red LED (set to 11).

2. **Setup Function:**
   - `pinMode(green, OUTPUT)`: Sets the green LED pin as an output.
   - `pinMode(yellow, OUTPUT)`: Sets the yellow LED pin as an output.
   - `pinMode(red, OUTPUT)`: Sets the red LED pin as an output.
   
   This function configures the three pins as output pins, which will allow the Arduino to control the LEDs.

3. **Loop Function:**
   - The program continuously cycles through turning each LED on and off in a specific order:
     - First, the **green LED** is turned on (`HIGH`) for 5 seconds, then turned off (`LOW`).
     - Next, the **yellow LED** is turned on for 5 seconds, then turned off.
     - Finally, the **red LED** is turned on for 5 seconds, then turned off.
   - This sequence repeats indefinitely, creating a traffic light simulation.

### Code

```cpp
int green = 13;
int red = 11;
int yellow = 12;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  // Turn on the green LED for 5 seconds
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);
  
  // Turn on the yellow LED for 5 seconds
  digitalWrite(yellow, HIGH);
  delay(5000);
  digitalWrite(yellow, LOW);
  
  // Turn on the red LED for 5 seconds
  digitalWrite(red, HIGH);
  delay(5000);
  digitalWrite(red, LOW);
}
