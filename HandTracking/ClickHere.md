# Hand Gesture Controlled Arduino Brightness Control

This project combines Python, OpenCV, Mediapipe, and Arduino to create a hand gesture-based brightness controller. The Python script tracks the distance between the thumb and index finger using a webcam and sends the calculated distance to an Arduino board via serial communication. The Arduino then maps the distance to control the brightness of an LED.

## Features
- Real-time hand tracking using Mediapipe and OpenCV.
- Distance measurement between thumb and index finger.
- Serial communication between Python and Arduino.
- LED brightness control based on finger distance.

---

## Requirements
### Hardware
- Arduino board (e.g., Arduino Uno).
- LED.
- Resistor (220Ω recommended).
- USB cable for Arduino.
- A computer with a webcam.

### Software
- Python 3.x.
- Arduino IDE.
- Python libraries: 
  - `opencv-python`
  - `mediapipe`
  - `pyserial`

---

## Setup Instructions

### 1. Arduino Setup
- Connect the LED to pin 11 of the Arduino through a 220Ω resistor.
- Upload the following Arduino code to your Arduino board:

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    int d = data.toInt();

    if (d < 30) d = 30;
    if (d > 150) d = 150;

    int brightness = map(d, 30, 150, 0, 255);
    analogWrite(11, brightness);
    Serial.print("Distance: ");
    Serial.print(d);
    Serial.print(" | Brightness: ");
    Serial.println(brightness);

    delay(100);
  }
}
```
## Setup

### Python Environment Setup:
Install the required Python libraries:
```bash
pip install opencv-python mediapipe pyserial
```
### Python Code: 
Save the following Python code and run it on your computer:

```python
import cv2
import mediapipe as mp
import math
import serial
import time

arduino = serial.Serial(port='COM7', baudrate=9600, timeout=1)

cap = cv2.VideoCapture(0)
mphands = mp.solutions.hands
hands = mphands.Hands()
mpdraw = mp.solutions.drawing_utils

x1, y1, x2, y2 = 0, 0, 0, 0

while True:
    success, img = cap.read()
    if not success:
        print("Error reading frame from camera.")
        break

    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(imgRGB)

    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            mpdraw.draw_landmarks(img, handLms, mphands.HAND_CONNECTIONS)
            for id, lm in enumerate(handLms.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x * w), int(lm.y * h)

                if id == 4:  # Tip Thumb finger
                    x1, y1 = cx, cy
                if id == 8:  # Tip of index finger
                    x2, y2 = cx, cy

            dist = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
            if 30 <= dist <= 180:
                arduino.write(f"{int(dist)}\n".encode())
                print(f"Sent Distance: {int(dist)}")
            time.sleep(0.1)

    cv2.imshow("Hand Tracking", img)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        arduino.close()
        break

cap.release()
cv2.destroyAllWindows()
```
### How It Works
- Hand Tracking:
The Python script uses Mediapipe to track the hand and calculates the distance between the thumb and index finger.
- Data Transmission:
The distance is sent to the Arduino via serial communication.
- LED Brightness Control:
The Arduino maps the distance to an LED brightness value and adjusts the LED accordingly.
### Usage
Run the Python script.
Show your hand to the webcam, adjusting the distance between your thumb and index finger.
Observe the LED brightness change based on the distance.
### Author
Thejesh Varma
B.Tech in Electronics and Communication Engineering
Rajiv Gandhi University of Knowledge Technologies, Nuzvid
Feel free to contribute and share your feedback!
