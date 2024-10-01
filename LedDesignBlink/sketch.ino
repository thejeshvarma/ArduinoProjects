int red = 8;
int green = 7;
int blue = 6;
int pink = 5;
int yellow = 4;
int cyan = 3;
int violet = 2;
int orange = 1;

void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
ledDance();
delay(100);
}
void ledDance(){
digitalWrite(red, HIGH);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
digitalWrite(pink, LOW);
digitalWrite(yellow, LOW);
digitalWrite(cyan, LOW);
digitalWrite(violet, LOW);
digitalWrite(orange, LOW);
delay(50);
digitalWrite(red, LOW);
digitalWrite(green, HIGH);
digitalWrite(blue, LOW);
digitalWrite(pink, LOW);
digitalWrite(yellow, LOW);
digitalWrite(cyan, LOW);
digitalWrite(violet, LOW);
digitalWrite(orange, LOW);
delay(50);
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, HIGH);
digitalWrite(pink, LOW);
digitalWrite(yellow, LOW);
digitalWrite(cyan, LOW);
digitalWrite(violet, LOW);
digitalWrite(orange, LOW);
delay(50);
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
digitalWrite(pink, HIGH);
digitalWrite(yellow, LOW);
digitalWrite(cyan, LOW);
digitalWrite(violet, LOW);
digitalWrite(orange, LOW);
delay(50);
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
digitalWrite(pink, LOW);
digitalWrite(yellow, HIGH);
digitalWrite(cyan, LOW);
digitalWrite(violet, LOW);
digitalWrite(orange, LOW);
delay(50);
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
digitalWrite(pink, LOW);
digitalWrite(yellow, LOW);
digitalWrite(cyan, HIGH);
digitalWrite(violet, LOW);
digitalWrite(orange, LOW);
delay(50);
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
digitalWrite(pink, LOW);
digitalWrite(yellow, LOW);
digitalWrite(cyan, LOW);
digitalWrite(violet, HIGH);
digitalWrite(orange, LOW);
delay(50);
digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
digitalWrite(pink, LOW);
digitalWrite(yellow, LOW);
digitalWrite(cyan, LOW);
digitalWrite(violet, LOW);
digitalWrite(orange, HIGH);
delay(50);
}
