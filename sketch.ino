int ledpin = 8;
int btnpin = 7 ;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
pinMode(btnpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// btnstate = digitalRead(btnpin)
if(digitalRead(btnpin)==HIGH){
  digitalWrite(ledpin,HIGH);
  // delay(5000);
}else{
  digitalWrite(ledpin,LOW);
}
}
