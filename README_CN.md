# DFRobot_AS7341
您对颜色了解多少？您想了解真正的颜色吗？眼睛可能会欺骗您，但是传感器不会。AS7341可见光传感器可以告诉您最真实的颜色。<br>
AS7341可见光传感器采用业内知名的ams公司推出的新一代AS7341光谱传感IC。该传感器有8个可见光通道、1个闪烁通道、1个NIR通道和1个未加滤光片的通道。该传感器拥有6个独立的16位ADC通道，可以并行的处理数据。该传感器板载了两颗高亮LED，可在暗光环境下进行补光。<br>

![Product Image](./resources/images/SEN0365.png)

## Product Link (https://www.dfrobot.com.cn/goods-2931.html)
    SEN0365: Fermion: AS7341可见光谱传感器
	
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
   * @brief 读取传感器的ID
   * @return 读取到的传感器ID,一个字节数据.
   */
  uint8_t readID();
  
  /**
   * @brief 设置寄存器ATIME的值，通过该值可计算Integration time的值，该值表示读取数据过程中必须要消耗的时间
   * @param ATIME寄存器的值.
   */
  void setAtime(uint8_t value);
  void setAstep(uint16_t value);
  /**
   * @brief 设置增益值(0~10对应 X0.5,X1,X2,X4,X8,X16,X32,X64,X128,X256,X512)
   * @param CFG1寄存器的值.
   */
  void setAGAIN(uint8_t value);

  /**
   * @brief 设置WTIME值，通过该值可计算 wite time，该值表示读取数据过程中必须要消耗的时间
   * @param WTIME的值.
   */
  void setWtime(uint8_t value);
  
  /**
   * @brief 开始光谱的测量.
   * @param 通道映射的模式 :1.eF1F4ClearNIR,2.eF5F8ClearNIR
   */
  void startMeasure(eChChoose_t mode);
  /**
   * @brief 读取传感器数据通道0~5的值，eF1F4ClearNIR模式下.
   * @return sModeOneData_t 的数据
   */
  sModeOneData_t readSpectralDataOne();
  
  /**
   * @brief 读取传感器数据通道0~5的值,eF5F8ClearNIR模式下.
   * @return sModeTwoData_t 的数据
   */
  sModeTwoData_t readSpectralDataTwo();
  
  /**
   * @brief 读取flicker寄存器的值，可据此预计光源的闪烁频率
   * @return flicker寄存器的数据.
   */
  uint8_t readFlickerData();
  
  /**
   * @brief 打开或关闭LED
   * @param true or false
   */
  void enableLed(bool on);

  /**
   * @brief 设置引脚电流控制亮度(1~20对应电流 4mA,6mA,8mA,10mA,12mA,......,42mA)
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

- 2020/07/31  - Version 1.0.0 released.

## Credits

Written by fengli(li.feng@dfrobot.com), 2020.7.31 (Welcome to our [website](https://www.dfrobot.com/))

