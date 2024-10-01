# Arduino LED Dance Project

This Arduino project controls 8 different LEDs, connected to digital pins, to create a sequential lighting pattern. The LEDs are lit one by one in a simple loop with short delays in between, simulating a "LED Dance."

## Project Setup

### Components Required:
- 8 LEDs (Red, Green, Blue, Pink, Yellow, Cyan, Violet, Orange)
- 8 Resistors (appropriate values for your LEDs, usually 220Ω)
- Arduino Board (e.g., Uno, Nano, etc.)
- Jumper Wires
- Breadboard (optional for prototyping)

### Pin Assignments:
Each LED is connected to a specific digital pin on the Arduino as follows:
- **Red LED**: Pin 8
- **Green LED**: Pin 7
- **Blue LED**: Pin 6
- **Pink LED**: Pin 5
- **Yellow LED**: Pin 4
- **Cyan LED**: Pin 3
- **Violet LED**: Pin 2
- **Orange LED**: Pin 1

### Circuit Diagram:
- Connect each LED’s anode (longer leg) to its corresponding digital pin.
- Connect the cathode (shorter leg) of each LED to a resistor and ground (GND) on the Arduino.
- Ensure that each LED has its own resistor to avoid damaging the Arduino or the LEDs.
  ![image](https://github.com/user-attachments/assets/428a286a-6022-4d6d-a33e-12b0a37352ea)


### Code Explanation:
```cpp
int red = 8;       // Assigning pin 8 to Red LED
int green = 7;     // Assigning pin 7 to Green LED
int blue = 6;      // Assigning pin 6 to Blue LED
int pink = 5;      // Assigning pin 5 to Pink LED
int yellow = 4;    // Assigning pin 4 to Yellow LED
int cyan = 3;      // Assigning pin 3 to Cyan LED
int violet = 2;    // Assigning pin 2 to Violet LED
int orange = 1;    // Assigning pin 1 to Orange LED

void setup() {
  // Setting each pin as output to control the LEDs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(pink, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(cyan, OUTPUT);
  pinMode(violet, OUTPUT);
  pinMode(orange, OUTPUT);
}

void loop() {
  // Call the ledDance function to cycle through the LEDs
  ledDance();
  delay(100);  // Delay between cycles
}

void ledDance() {
  // Turning each LED on and off in sequence with a 50ms delay
  digitalWrite(red, HIGH);
  delay(50);
  digitalWrite(red, LOW);
  
  digitalWrite(green, HIGH);
  delay(50);
  digitalWrite(green, LOW);
  
  digitalWrite(blue, HIGH);
  delay(50);
  digitalWrite(blue, LOW);
  
  digitalWrite(pink, HIGH);
  delay(50);
  digitalWrite(pink, LOW);
  
  digitalWrite(yellow, HIGH);
  delay(50);
  digitalWrite(yellow, LOW);
  
  digitalWrite(cyan, HIGH);
  delay(50);
  digitalWrite(cyan, LOW);
  
  digitalWrite(violet, HIGH);
  delay(50);
  digitalWrite(violet, LOW);
  
  digitalWrite(orange, HIGH);
  delay(50);
  digitalWrite(orange, LOW);
}
