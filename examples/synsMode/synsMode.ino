/*!
 * @file synsMode.ino
 * @brief Read spectrum data by syns mode. The chip's measurement function needs to be activated by a level pulse for each measurement.
    The chip will enter idle mode when the measurement is done, which could save power.
 * 
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2020-07-16
 * @get from https://www.dfrobot.com
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
  while (as7341.begin(as7341.eSyns) != 0) {
    Serial.println("IIC init failed, please check if the wire connection is correct");
    delay(1000);
  }
  //Integration time = (ATIME + 1) x (ASTEP + 1) x 2.78µs
  //Set the value of register ATIME, through which the value of Integration time can be calculated. The value represents the time that must be spent during data reading.
  as7341.setAtime(29);
  //Set the value of register ASTEP, through which the value of Integration time can be calculated. The value represents the time that must be spent during data reading.
  as7341.setAstep(599);
  //Set gain value(0~10 corresponds to X0.5,X1,X2,X4,X8,X16,X32,X64,X128,X256,X512)
  as7341.setAGAIN(7);
}

void loop(void)
{
  DFRobot_AS7341::sModeOneData_t data1;
  as7341.startMeasure(as7341.eF1F4ClearNIR);
  //Put the sensor into measurement mode by gpio pulse 
  while(!as7341.measureComplete());
  //Read the value of sensor data channel 0~5, under eF1F4ClearNIR
  data1 = as7341.readSpectralDataOne();
  Serial.print("F1(405-425nm):");
  Serial.println(data1.ADF1);
  Serial.print("F2(435-455nm):");
  Serial.println(data1.ADF2);
  Serial.print("F3(470-490nm):");
  Serial.println(data1.ADF3);
  Serial.print("F4(505-525nm):");   
  Serial.println(data1.ADF4);
  Serial.print("Clear:");
  Serial.println(data1.ADCLEAR);
  Serial.print("NIR:");
  Serial.println(data1.ADNIR);
  /*
  DFRobot_AS7341::sModeTwoData_t data2;
  as7341.startMeasure(as7341.eF5F8ClearNIR);
  //Put the sensor into measurement mode by gpio pulse 
  while(!as7341.measureComplete());
  //Read the value of sensor data channel 0~5, under eF5F8ClearNIR
  data2 = as7341.readSpectralDataTwo();
  Serial.print("F5(545-565nm):");
  Serial.println(data2.ADF5);
  Serial.print("F6(580-600nm):");
  Serial.println(data2.ADF6);
  Serial.print("F7(620-640nm):");
  Serial.println(data2.ADF7);
  Serial.print("F8(670-690nm):");
  Serial.println(data2.ADF8);
  Serial.print("Clear:");
  Serial.println(data2.ADCLEAR);
  Serial.print("NIR:");
  Serial.println(data2.ADNIR);
  delay(1000);
  */
}