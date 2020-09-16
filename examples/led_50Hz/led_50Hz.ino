//50HZ
//Burn the codes to another main-controller, and connect an LED onto the Digital pin 10 to provide 50Hz ambient light for getFlicker.ino. 

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5);
  digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(5);
}
