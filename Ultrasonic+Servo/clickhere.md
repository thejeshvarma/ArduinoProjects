# **Arduino Distance Measurement with Servo and LCD**

This Arduino project combines an ultrasonic distance sensor, an LCD display, a servo motor, and a buzzer. The system measures the distance of an object using an ultrasonic sensor, displays the measured distance on an LCD screen, and moves a servo motor back and forth continuously.

---

## **Components Required**
1. Arduino Board
2. Ultrasonic Sensor (HC-SR04)
3. LCD Display with I2C Module
4. Servo Motor
5. Piezo Buzzer
6. Jumper Wires
7. Breadboard (Optional)

---

## **Code Explanation**

### **Libraries Used**
- `LiquidCrystal_I2C.h`: Handles the I2C communication with the LCD display.
- `Servo.h`: Controls the movement of the servo motor.

### **Pin Configuration**
- **TRIG_PIN (13)**: Trigger pin of the ultrasonic sensor.
- **ECHO_PIN (12)**: Echo pin of the ultrasonic sensor.
- **BUZZER_PIN (7)**: Pin connected to the piezo buzzer.
- **Servo Motor (9)**: Control pin for the servo motor.

---

### **Setup Function**
1. Initializes the servo motor and moves it to position 0°.
2. Configures the ultrasonic sensor pins (`TRIG_PIN` as OUTPUT and `ECHO_PIN` as INPUT).
3. Sets up the LCD display and turns on the backlight.

---

### **Distance Measurement Function**
The `dist()` function calculates the distance in centimeters by:
1. Sending a 10-microsecond pulse to the TRIG pin of the ultrasonic sensor.
2. Measuring the pulse duration from the ECHO pin.
3. Using the formula `distance = 0.017 * duration` to compute the distance.

---

### **Loop Function**
1. **Servo Sweep and Distance Display**:
   - The servo motor sweeps from 0° to 180° and back.
   - During each step, the distance is measured and displayed on the LCD.
   - Distance values are also printed to the Serial Monitor for debugging.

2. **LCD Display**:
   - Displays a fixed label `--Distance--` on the first line.
   - Continuously updates the second line with the latest distance in centimeters.

---

### **Working Mechanism**
1. **Servo Movement**: The servo motor moves between 0° and 180° with a delay of 20 ms for smooth operation.
2. **Distance Measurement**: The ultrasonic sensor measures the distance of the object in its path.
3. **LCD Display**: The distance value is updated on the LCD in real time.
4. **Serial Monitor**: Outputs the distance values for debugging and monitoring.

---

## **Future Improvements**
1. **Add Buzzer Alerts**: Activate the buzzer for objects closer than a threshold distance.
2. **Optimize Performance**: Reduce the delay for smoother servo motion and quicker updates.
3. **Enhance Readability**: Format the LCD display output for better clarity.

---

## **Schematic**
Connect the components as follows:
- **Ultrasonic Sensor**:
  - VCC → 5V
  - GND → GND
  - TRIG → Digital Pin 13
  - ECHO → Digital Pin 12
- **Servo Motor**:
  - Signal → Digital Pin 9
  - VCC → 5V
  - GND → GND
- **Buzzer**:
  - Positive → Digital Pin 7
  - Negative → GND
- **LCD Display**:
  - Connect via I2C (SDA and SCL pins).

---

## **Code**
```cpp
#include "LiquidCrystal_I2C.h"
#include <Servo.h>
Servo myservo;
const int TRIG_PIN   = 13; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN   = 12; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int BUZZER_PIN = 7; // Arduino pin connected to Piezo Buzzer's pin

// variables will change:
float duration_us, distance_cm;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin (9600);         // initialize serial port
  myservo.attach(9);
  myservo.write(0);
  pinMode(TRIG_PIN, OUTPUT);   // set Arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);    // set Arduino pin to input mode
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setBacklight(1);
}

float dist() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  return 0.017 * duration_us;
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  int pos = 0, i;
  for (pos = 0; pos <= 180; pos++) {
    myservo.write(pos);
    delay(20);
    distance_cm = dist();
    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    lcd.setCursor(0, 0);
    lcd.print("--Distance--");
    lcd.setCursor(0, 1);
    lcd.print(distance_cm);
    delay(50);
  }

  for (pos = 180; pos >= 0; pos--) {
    myservo.write(pos);
    delay(20);
    distance_cm = dist();
    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    lcd.setCursor(0, 0);
    lcd.print("--Distance--");
    lcd.setCursor(0, 1);
    lcd.print(distance_cm);
    delay(50);
  }

  delay(500);
}
