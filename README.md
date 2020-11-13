# DFRobot_AS7341

We live in a colorful world, but how much do you really know about color? You eyes may deceive you, while the sensors don’t lie. This AS7341sensor can tell you the truth about color. <br> 
AS7341 Visible Light Sensor employs the new generation of AS7341 spectral sensor IC launched by the well-known AMS company. The sensor features eight channels for the visible light, one channel for near-IR, and one channel without a filter. Also it integrates a dedicated channel to detect ambient light flicker. Besides that, this sensor comes with 6 independent 16-bit ADC channels for data processing in parallel. The two on-board extra-bright LEDs can supply light in dark environment.

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
1.Read the value of each channel<br>
2.Detect whether the frequency of light source flickering is 50HZ or 60HZ


## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods
```C++
 /**
   * @brief init function
   * @return Return 0 if the initialization succeeds, otherwise return non-zero and error code.
   */
  int begin();

  /**
   * @brief Read sensor ID 
   * @return The read sensor ID, one byte 
   */
  uint8_t readID();
  
  /** 
   * @brief Set the value of register ATIME, through which the value of integration time can be calculated. The value represents
   * @ the time that must be spent during data reading.
   * @param The value of register ATIME
   */
  void setAtime(uint8_t value);
  void setAstep(uint16_t value);
  /**
   * @brief Set gain value (0~10 corresponds to X0.5,X1,X2,X4,X8,X16,X32,X64,X128,X256,X512)
   * @param The value of register CFG1
   */
  void setAGAIN(uint8_t value);

  /**
   * @brief Set the value of WTIME, through which wite time can be calculated. The value represents the time that
   * @ must be spent during data reading.
   * @param The value of WTIME
   */
  void setWtime(uint8_t value);
  
  /**
   * @brief Start spectrum measurement 
   * @param Channel mapping mode:1.eF1F4ClearNIR,2.eF5F8ClearNIR
   */
  void startMeasure(eChChoose_t mode);
  /**
   * @brief Read the value of sensor data channel 0~5, under eF1F4ClearNIR
   * @return The data of sModeOneData_t
   */
  sModeOneData_t readSpectralDataOne();
  
  /**
   * @brief Read the value of sensor data channel 0~5, under eF5F8ClearNIR
   * @return The data of sModeTwoData_t
   */
  sModeTwoData_t readSpectralDataTwo();
  
  /**
   * @brief Read the value of register flicker, through which the flicker frequency of the light source can be predicted
   * @return The data of register flicker
   */
  uint8_t readFlickerData();
  
  /**
   * @brief Turn the LED on or off
   * @param true or false
   */
  void enableLed(bool on);

  /**
   * @brief Set pin current to control brightness (1~20 corresponds to current 4mA,6mA,8mA,10mA,12mA,......,42mA)
   * @param 1~20
   */
  void controlLed(uint8_t current);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 
ESP8266        |      √       |              |             | 
M0        |      √       |              |             | 


## History

- Date 2020-7-31
- Version V0.1


## Credits

Written by fengli(li.feng@dfrobot.com), 2020.7.31 (Welcome to our [website](https://www.dfrobot.com/))





