# Arduino I2C 16x2 LCD Display Project

This Arduino project demonstrates how to interface a 16x2 LCD display with I2C communication (address 0x27) and display text. It prints static text in different positions and scrolls a message character by character on the screen.

## Project Setup

### Components Required:
- 16x2 I2C LCD Display (address 0x27)
- Arduino Board (e.g., Uno, Nano, etc.)
- Jumper Wires

### I2C LCD Display Pin Assignments:
The 16x2 LCD display uses I2C communication, meaning it only requires 4 connections:
- **GND**: Ground
- **VCC**: 5V power supply
- **SDA**: Data line (connect to A4 on Arduino Uno)
- **SCL**: Clock line (connect to A5 on Arduino Uno)

### Circuit :
![image](https://github.com/user-attachments/assets/eff64de9-eadf-49f6-b5b9-28b085f3316d)


### Circuit Diagram:
1. Connect the **GND** pin of the LCD to **GND** on the Arduino.
2. Connect the **VCC** pin of the LCD to **5V** on the Arduino.
3. Connect the **SDA** pin of the LCD to **A4** on the Arduino.
4. Connect the **SCL** pin of the LCD to **A5** on the Arduino.

### Code:
```cpp
#include <LiquidCrystal_I2C.h>  // Include the I2C LCD library
#include <Wire.h>               // Include the Wire library for I2C communication

// Initialize the LCD with I2C address 0x27 and screen size 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);  
char a[15] = "Hello_World";      // Define a character array to scroll
int i = 0;                       // Variable for iterating through the array

void setup() {
  Serial.begin(9600);            // Start serial communication at 9600 baud
  lcd.begin(16, 2);              // Initialize the LCD (16 columns and 2 rows)
  lcd.backlight();               // Turn on the LCD backlight
  lcd.setBacklight(HIGH);        // Ensure the backlight is at high brightness
}

void loop() {
  // Display static text on the first line
  lcd.setCursor(0, 0);           // Set cursor to the first row, first column
  lcd.blink();                   // Enable cursor blink
  lcd.print("Here is text");      // Print text on the LCD
  
  // Display static text on the second line
  lcd.setCursor(2, 1);           // Set cursor to the second row, third column
  lcd.print("its text again");    // Print text on the LCD
  delay(3000);                   // Delay to show the text for 3 seconds
  
  lcd.clear();                   // Clear the display
  delay(500);                    // Short delay before scrolling text
  
  // Scroll the "Hello_World" message across the screen
  for(i = 0; i < 11; i++) {
    lcd.setCursor(i, 0);         // Set cursor to the first row
    delay(500);                  // Short delay for smooth scrolling
    lcd.print(a[i]);             // Print each character from the array
  }
  
  delay(2000);                   // Wait 2 seconds after scrolling
  lcd.clear();                   // Clear the display before the next loop
}
```

### Explanation of the LCD 0x27 I2C Display:
The **LiquidCrystal_I2C** library simplifies communication with the 16x2 LCD over the I2C bus. The LCD display has the following characteristics:

- **I2C Address (0x27)**: This address defines the specific device on the I2C bus. It can vary between displays (usually 0x27 or 0x3F).
- **Screen Size (16x2)**: The display has 16 columns and 2 rows, meaning it can show 16 characters per row.

### Main Functions:
- **`lcd.begin(16,2)`**: Initializes the display with 16 columns and 2 rows.
- **`lcd.backlight()`**: Turns on the backlight.
- **`lcd.setBacklight(HIGH)`**: Ensures the backlight brightness is set to high.
- **`lcd.setCursor(col, row)`**: Moves the cursor to the specified position (`col` and `row`).
- **`lcd.print()`**: Prints text to the LCD at the current cursor position.
- **`lcd.clear()`**: Clears the display, removing all characters.
- **`lcd.blink()`**: Enables the cursor to blink, indicating text input.

### How the Code Works:
1. **Setup**: In the `setup()` function, the LCD is initialized and the backlight is turned on.
2. **Static Text Display**: The `loop()` function begins by setting the cursor at `(0,0)` (first row, first column) and displaying "Here is text." Then it moves to `(2,1)` (second row, third column) to display "its text again."
3. **Clearing and Scrolling Text**: After displaying static text for 3 seconds, the screen is cleared. The `for` loop scrolls the message "Hello_World" character by character across the first row. Each character is printed at a new position with a 500ms delay between characters for smooth scrolling.
4. **Delays and Repeats**: After scrolling the text, a 2-second delay is added before clearing the display and starting over.

### How to use:
1. Upload the code to your Arduino using the Arduino IDE.
2. Connect the LCD display to the correct pins as described in the circuit diagram.
3. The LCD will first display static text on both lines, then scroll "Hello_World" across the screen.

