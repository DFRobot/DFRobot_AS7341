/*!
 * @file getFlicker.ino
 * @brief Read the flicker frequency of light source 
 * @details Can distinguish the light source flashing at 50HZ or 60HZ frequency
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2020-07-16
 * @url https://github.com/DFRobot/DFRobot_AS7341
 */
#include "DFRobot_AS7341.h"
/*!
 * @brief Construct the function
 * @param pWire IC bus pointer object and construction device, can both pass or not pass parameters, Wire in default.
 */
DFRobot_AS7341 as7341;


void setup(void)
{
  Serial.begin(115200);
  //Detect if IIC can communicate properly
  while (as7341.begin() != 0) {
    Serial.println("IIC init failed, please check if the wire connection is correct");
    delay(1000);
  }
}

void loop(void){
  uint8_t freq = 0;
  //Read the value of register flicker, through which the flicker frequency of the light source can be predicted
  freq = as7341.readFlickerData();
  if (freq == 1) {
    Serial.println("Unknown frequency");
  } else if (freq == 0) {
    Serial.println("No flicker");
  } else {
    Serial.print(freq);
    Serial.println("Hz");
  }
}
