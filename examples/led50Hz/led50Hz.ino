/*!
 * @file led50Hz.ino
 * @brief provide 50Hz ambient light
 * @details Burn the codes to another main-controller, and connect an LED 
 * @n onto the Digital pin 10 to provide 50Hz ambient light for getFlicker.ino. 
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2020-07-16
 * @url https://github.com/DFRobot/DFRobot_AS7341
 */
void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5);
  digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(5);
}
