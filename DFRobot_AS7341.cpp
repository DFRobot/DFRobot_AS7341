
/*!
 * @file DFRobot_AS7341.h
 * @brief Define the infrastructure and the implementation of the underlying method of the DFRobot_AS7341 class, 
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


DFRobot_AS7341::DFRobot_AS7341(TwoWire *pWire)
{
  _pWire = pWire;
  _address = 0x39;
} 
int DFRobot_AS7341::begin(eMode_t mode) 
{
  uint8_t buffer[2];
  _pWire->begin();
  _pWire->beginTransmission(_address);
  if(_pWire->endTransmission() != 0){
    DBG("");
    DBG("bus data access error"); DBG("");
    return ERR_DATA_BUS;
  }
  enableAS7341(true);
  measureMode = mode;
  return ERR_OK;
}

uint8_t DFRobot_AS7341::readID()
{
  uint8_t id;
  if(readReg(REG_AS7341_ID,&id,1) == 0){
    DBG("id read error");
    return 0;
  }
  else{
    return id;
  }
}

void DFRobot_AS7341::enableAS7341(bool on)
{
  uint8_t data;
  readReg(REG_AS7341_ENABLE,&data,1);
  if(on == true){
    data = data | (1<<0);
  } else {
    data = data & (~1);
  }
  writeReg(REG_AS7341_ENABLE,&data,1);
}

void DFRobot_AS7341::enableSpectralMeasure(bool on)
{
  uint8_t data;
  readReg(REG_AS7341_ENABLE,&data,1);
  if(on == true){
    data = data | (1<<1);
  } else {
    data = data & (~(1<<1));
  }
  writeReg(REG_AS7341_ENABLE,&data,1);
}

void DFRobot_AS7341::enableWait(bool on){

  uint8_t data;
  readReg(REG_AS7341_ENABLE,&data,1);
  if(on == true){
    data = data | (1<<3);
  } else {
    data = data & (~(1<<3));
  }
  writeReg(REG_AS7341_ENABLE,&data,1);
}

void DFRobot_AS7341::enableSMUX(bool on){
  uint8_t data;
  readReg(REG_AS7341_ENABLE,&data,1);
  if(on == true){
    data = data | (1<<4);
  } else {
    data = data & (~(1<<4));
  }
  writeReg(REG_AS7341_ENABLE,&data,1);
}

void DFRobot_AS7341::enableFlickerDetection(bool on){

  uint8_t data;
  readReg(REG_AS7341_ENABLE,&data,1);
  if(on == true){
    data = data | (1<<6);
  } else {
    data = data & (~(1<<6));
  }
  writeReg(REG_AS7341_ENABLE,&data,1);
}

void DFRobot_AS7341::config(eMode_t mode)
{
  uint8_t data;
  setBank(1);
  readReg(REG_AS7341_CONFIG,&data,1);
  switch(mode){
    case eSpm : {
      data = (data & (~3)) | eSpm;
    };
	break;
    case eSyns : {
      data = (data & (~3)) | eSyns;
    };
	break;
    case eSynd : {
      data = (data & (~3)) | eSynd;
    };
	break;
    default : break;
  }
  writeReg(REG_AS7341_CONFIG,&data,1);
  setBank(0);
}

void DFRobot_AS7341::F1F4_Clear_NIR() {
  writeReg(0x00, 0x30); 
  writeReg(0x01, 0x01); 
  writeReg(0x02, 0x00); 
  writeReg(0x03, 0x00); 
  writeReg(0x04, 0x00); 
  writeReg(0x05, 0x42); 
  writeReg(0x06, 0x00); 
  writeReg(0x07, 0x00); 
  writeReg(0x08, 0x50); 
  writeReg(0x09, 0x00); 
  writeReg(0x0A, 0x00); 
  writeReg(0x0B, 0x00); 
  writeReg(0x0C, 0x20); 
  writeReg(0x0D, 0x04); 
  writeReg(0x0E, 0x00); 
  writeReg(0x0F, 0x30); 
  writeReg(0x10, 0x01); 
  writeReg(0x11, 0x50); 
  writeReg(0x12, 0x00); 
  writeReg(0x13, 0x06); 
}

void DFRobot_AS7341::F5F8_Clear_NIR() {
  writeReg(byte(0x00), byte(0x00)); 
  writeReg(byte(0x01), byte(0x00)); 
  writeReg(byte(0x02), byte(0x00)); 
  writeReg(byte(0x03), byte(0x40)); 
  writeReg(byte(0x04), byte(0x02)); 
  writeReg(byte(0x05), byte(0x00)); 
  writeReg(byte(0x06), byte(0x10)); 
  writeReg(byte(0x07), byte(0x03)); 
  writeReg(byte(0x08), byte(0x50)); 
  writeReg(byte(0x09), byte(0x10)); 
  writeReg(byte(0x0A), byte(0x03)); 
  writeReg(byte(0x0B), byte(0x00)); 
  writeReg(byte(0x0C), byte(0x00)); 
  writeReg(byte(0x0D), byte(0x00)); 
  writeReg(byte(0x0E), byte(0x24)); 
  writeReg(byte(0x0F), byte(0x00)); 
  writeReg(byte(0x10), byte(0x00)); 
  writeReg(byte(0x11), byte(0x50)); 
  writeReg(byte(0x12), byte(0x00)); 
  writeReg(byte(0x13), byte(0x06)); 
}

void DFRobot_AS7341::FDConfig() {

  writeReg(byte(0x00), byte(0x00)); 
  writeReg(byte(0x01), byte(0x00)); 
  writeReg(byte(0x02), byte(0x00)); 
  writeReg(byte(0x03), byte(0x00)); 
  writeReg(byte(0x04), byte(0x00)); 
  writeReg(byte(0x05), byte(0x00)); 
  writeReg(byte(0x06), byte(0x00)); 
  writeReg(byte(0x07), byte(0x00)); 
  writeReg(byte(0x08), byte(0x00)); 
  writeReg(byte(0x09), byte(0x00)); 
  writeReg(byte(0x0A), byte(0x00)); 
  writeReg(byte(0x0B), byte(0x00)); 
  writeReg(byte(0x0C), byte(0x00)); 
  writeReg(byte(0x0D), byte(0x00)); 
  writeReg(byte(0x0E), byte(0x00)); 
  writeReg(byte(0x0F), byte(0x00)); 
  writeReg(byte(0x10), byte(0x00)); 
  writeReg(byte(0x11), byte(0x00)); 
  writeReg(byte(0x12), byte(0x00)); 
  writeReg(byte(0x13), byte(0x60)); 
}

void DFRobot_AS7341::startMeasure(eChChoose_t mode)
{
  uint8_t data=0;
  
  readReg(REG_AS7341_CFG_0,&data,1);
  data = data & (~(1<<4));
  writeReg(REG_AS7341_CFG_0,&data,1);
  
  enableSpectralMeasure(false);
  writeReg(0xAF,0x10);
  if(mode  == eF1F4ClearNIR)
    F1F4_Clear_NIR();
  else if(mode  == eF5F8ClearNIR)
    F5F8_Clear_NIR();
  enableSMUX(true);
  if(measureMode == eSyns){
    setGpioMode(INPUT);
    config(eSyns);
    //writeReg(byte(0xA9), byte(0)); 
  }
  else if(measureMode == eSpm){
    config(eSpm);
  }
  enableSpectralMeasure(true);
  if(measureMode == eSpm){
  while(!measureComplete()){
    delay(1);
  }
  }
}
uint8_t DFRobot_AS7341::readFlickerData(){
  uint8_t flicker;
  uint8_t data=0;
  readReg(REG_AS7341_CFG_0,&data,1);
  data = data & (~(1<<4));
  writeReg(REG_AS7341_CFG_0,&data,1);
  enableSpectralMeasure(false);
  writeReg(0xAF,0x10);
  FDConfig();
  enableSMUX(true);
  enableSpectralMeasure(true);
  uint8_t retry = 100;

  if(retry == 0) DBG(" data access error");
  enableFlickerDetection(true);
  delay(600);
  readReg(REG_AS7341_STATUS,&flicker,1);
  enableFlickerDetection(false);
  switch(flicker){
    case 44:
      flicker = 1;
      break;
    case 45:
      flicker = 50;
      break;
    case 46:
      flicker = 60;
      break;
    default:
      flicker = 0;
  }
  return flicker;
}

bool DFRobot_AS7341::measureComplete(){
  uint8_t status;
  readReg(REG_AS7341_STATUS_2,&status,1);
  if((status & (1<<6))){
    return true;
  }
  else{
    return false;
  }
}

uint16_t DFRobot_AS7341::getChannelData(uint8_t channel){
  uint8_t data[2];
  uint16_t channelData = 0x0000;
  readReg(REG_AS7341_CH0_DATA_L + channel*2,data,1);
  readReg(REG_AS7341_CH0_DATA_H + channel*2,data+1,1);
  channelData = data[1];
  channelData = (channelData<<8) | data[0];
  delay(50);
  return channelData;
}

DFRobot_AS7341::sModeOneData_t DFRobot_AS7341::readSpectralDataOne()
{
  sModeOneData_t data;
  data.ADF1 = getChannelData(0);
  data.ADF2 = getChannelData(1);
  data.ADF3 = getChannelData(2);
  data.ADF4 = getChannelData(3);
  data.ADCLEAR = getChannelData(4);
  data.ADNIR = getChannelData(5);
  return data;
}

DFRobot_AS7341::sModeTwoData_t DFRobot_AS7341::readSpectralDataTwo()
{
  sModeTwoData_t data;
  data.ADF5 = getChannelData(0);
  data.ADF6 = getChannelData(1);
  data.ADF7 = getChannelData(2);
  data.ADF8 = getChannelData(3);
  data.ADCLEAR = getChannelData(4);
  data.ADNIR = getChannelData(5);
  return data;
}

void DFRobot_AS7341::setGpio(bool connect){
  uint8_t data;
  readReg(REG_AS7341_CPIO,&data,1);
  if(connect == true){
    data = data | (1<<0);
  } else {
    data = data & (~(1<<0));
  }
  writeReg(REG_AS7341_CPIO,&data,1);
}

void DFRobot_AS7341::setGpioMode(uint8_t mode)
{
  uint8_t data;

  readReg(REG_AS7341_GPIO_2,&data,1);
  
  if(mode == INPUT){
     data = data | (1<<2);
  }
  
  if(mode == OUTPUT){
     data = data & (~(1<<2));
  }
  writeReg(REG_AS7341_GPIO_2,&data,1);
}

void DFRobot_AS7341::enableLed(bool on){
  uint8_t data=0;
  uint8_t data1=0;
setBank(1);
  
  readReg(REG_AS7341_CONFIG,&data,1);
  readReg(REG_AS7341_LED,&data1,1);
  if(on == true){
    data = data | (1<<3);
    data1 = data1 | (1<<7);
  } else {
    data = data & (~(1<<3));
    data1 = data1 & (~(1<<7));
  }
  writeReg(REG_AS7341_CONFIG,&data,1);
  writeReg(REG_AS7341_LED,&data1,1);
  setBank(0);
}

void DFRobot_AS7341::setBank(uint8_t addr){
	uint8_t data=0;
  readReg(REG_AS7341_CFG_0,&data,1);
  if(addr == 1){
  
    data = data | (1<<4);
  }
  
  if(addr == 0){
  
    data = data & (~(1<<4));
  }
  writeReg(REG_AS7341_CFG_0,&data,1);
}
void DFRobot_AS7341::controlLed(uint8_t current){
  uint8_t data=0;
  if(current < 1) current = 1;
    current--;
  if(current > 19) current = 19;
  

setBank(1);
  
  data = 0;
 // readReg(REG_AS7341_LED,&data,1);
  data = data | (1<<7);
  data = data | (current & 0x7f);
  writeReg(REG_AS7341_LED,&data,1);
  delay(100);
  //readReg(REG_AS7341_CFG_0,&data,1);
  //data = data & (~(1<<4));
  //writeReg(REG_AS7341_CFG_0,&data,1);
  setBank(0);
}

void DFRobot_AS7341::setInt(bool connect){
  uint8_t data;
  readReg(REG_AS7341_CPIO,&data,1);
  if(connect == true){
    data = data | (1<<1);
  } else {
    data = data & (~(1<<1));
  }
  writeReg(REG_AS7341_CPIO,&data,1);
}

void DFRobot_AS7341::enableSysInt(bool on)
{
  uint8_t data;
  readReg(REG_AS7341_INTENAB,&data,1);
  if(on == true){
    data = data | (1<<0);
  } else {
    data = data & (~(1<<0));
  }
  writeReg(REG_AS7341_INTENAB,&data,1);
}

void DFRobot_AS7341::enableFIFOInt(bool on)
{
  uint8_t data;
  readReg(REG_AS7341_INTENAB,&data,1);
  if(on == true){
    data = data | (1<<2);
  } else {
    data = data & (~(1<<2));
  }
  writeReg(REG_AS7341_INTENAB,&data,1);
}

void DFRobot_AS7341::enableSpectralInt(bool on)
{
  uint8_t data;
  readReg(REG_AS7341_INTENAB,&data,1);
  if(on == true){
    data = data | (1<<3);
  } else {
    data = data & (~(1<<3));
  }
  writeReg(REG_AS7341_INTENAB,&data,1);
}

void DFRobot_AS7341::endSleep()
{
  uint8_t data;
  readReg(REG_AS7341_INTENAB,&data,1);
  data = data | (1<<3);
  writeReg(REG_AS7341_INTENAB,&data,1);

}

void DFRobot_AS7341::clearFIFO()
{
  uint8_t data;
  readReg(REG_AS7341_CONTROL,&data,1);
  data = data | (1<<0);
  data = data & (~(1<<0));
  writeReg(REG_AS7341_CONTROL,&data,1);
}

void DFRobot_AS7341::spectralAutozero()
{
  uint8_t data;
  readReg(REG_AS7341_CONTROL,&data,1);
  data = data | (1<<1);
  writeReg(REG_AS7341_CONTROL,&data,1);
}

void DFRobot_AS7341::enableFlickerInt(bool on)
{
  uint8_t data;
  readReg(REG_AS7341_INTENAB,&data,1);
  if(on == true){
    data = data | (1<<2);
  } else {
    data = data & (~(1<<2));
  }
  writeReg(REG_AS7341_INTENAB,&data,1);
}

void DFRobot_AS7341::setAtime(uint8_t value)
{
  writeReg(REG_AS7341_ATIME,&value,1);
}

void DFRobot_AS7341::setAGAIN(uint8_t value)
{
  if(value > 10) value = 10;
  writeReg(REG_AS7341_CFG_1,&value,1);
}

void DFRobot_AS7341::setAstep(uint16_t value){
  uint8_t highValue,lowValue;
  lowValue = value & 0x00ff;
  highValue = value >> 8 ;
  writeReg(REG_AS7341_ASTEP_L,&lowValue,1);

  writeReg(REG_AS7341_ASTEP_H,&highValue,1);
}

float DFRobot_AS7341::getIntegrationTime(){

  uint8_t data;
  uint8_t astepData[2]={0};
  uint16_t astep;
  readReg(REG_AS7341_ATIME,&data,1);
  readReg(REG_AS7341_ASTEP_L,astepData,1);
  readReg(REG_AS7341_ASTEP_L,astepData+1,1);
  astep = astepData[1];
  astep = (astep << 8) | astepData[0];
  if(data == 0){

  }
  else if(data >0 && data <255){
    
  }
  else if(data == 255){
    
  }
}

void DFRobot_AS7341::setWtime(uint8_t value)
{
  writeReg(REG_AS7341_WTIME,&value,1);
}
float DFRobot_AS7341::getWtime(){
  float value;
  uint8_t data;
  readReg(REG_AS7341_WTIME,&data,1);
  if(data == 0){
    value = 2.78;
  }
  else if(data == 1){
    value = 5.56;
  }
  else if(data >1 && data <255){
    value = 2.78*(data+1);
  }
  else if(data == 255){
    value = 711;
  }
  return value;
}

void DFRobot_AS7341::setThreshold(uint16_t lowTh,uint16_t highTh){
  if(lowTh >= highTh) return;
  
  writeReg(REG_AS7341_SP_TH_H_MSB,highTh>>8);
  writeReg(REG_AS7341_SP_TH_H_LSB,highTh);


  writeReg(REG_AS7341_SP_TH_L_MSB,lowTh>>8);
  writeReg(REG_AS7341_SP_TH_L_LSB,lowTh);


  
delay(10);

  
  delay(10);
}
uint16_t DFRobot_AS7341::getLowThreshold(){
  uint16_t data;
  data = readReg(REG_AS7341_SP_TH_L_MSB);
   //Serial.println(data);
  data = readReg(REG_AS7341_SP_TH_L_LSB) | (data<<8);
   //Serial.println(readReg(REG_AS7341_SP_TH_L_LSB));
  return data ;
}
uint16_t DFRobot_AS7341::getHighThreshold(){

  uint16_t data;
  data = readReg(REG_AS7341_SP_TH_H_MSB);
  data = readReg(REG_AS7341_SP_TH_H_LSB) | (data<<8);
  return data ;

}

void DFRobot_AS7341::clearInterrupt(){
  writeReg(REG_AS7341_STATUS_1,0xff);


}
void DFRobot_AS7341::enableSpectralInterrupt(bool on){
  uint8_t data;
  data = readReg(REG_AS7341_INTENAB);
  if(on == true){
    data = data | (1<<3);
    writeReg(REG_AS7341_INTENAB,data);
  }
  else{
    data = data & (~(1<<3));
    writeReg(REG_AS7341_INTENAB,data);
  }
  
}
void DFRobot_AS7341::setIntChannel(uint8_t channel){
  if(channel >= 5) return;
  
  uint8_t data;
  data = readReg(REG_AS7341_CFG_12);
  data = data & (~(7));
  data = data | (channel);
  writeReg(REG_AS7341_CFG_12,data);
}

void DFRobot_AS7341::setAPERS(uint8_t num)
{

  uint8_t data;
  data = readReg(REG_AS7341_PERS);
  data = data & (~(15));
  data = data | (num);
  writeReg(REG_AS7341_PERS,data);
}
uint8_t DFRobot_AS7341::getIntSource()
{
  return readReg(REG_AS7341_STATUS_3);
}

bool DFRobot_AS7341::interrupt(){
  
  uint8_t data = readReg(REG_AS7341_STATUS_1);
  if(data & 0x80){
    return true;
  } else {
    return false;
  }
}
bool DFRobot_AS7341::checkWtime()
{
  uint8_t status;
  uint8_t value;
  readReg(REG_AS7341_STATUS_6,&status,1);
  value = status & (1<<2);
  if(value > 0){
    return false;
  } else {
    return  true;
  }
}

void DFRobot_AS7341::writeReg(uint8_t reg, uint8_t data){
  writeReg(reg,&data,1);
}
void DFRobot_AS7341::writeReg(uint8_t reg, void* pBuf, size_t size) 
{
  if (pBuf == NULL) {
    DBG("pBuf ERROR!! : null pointer");
  }
  uint8_t * _pBuf = (uint8_t *)pBuf;
  _pWire->beginTransmission(_address);
  _pWire->write(reg);
  for (uint16_t i = 0; i < size; i++) {
    _pWire->write(_pBuf[i]);
  }
  _pWire->endTransmission();
}
uint8_t DFRobot_AS7341::readReg(uint8_t reg){
  
  uint8_t data;
  readReg(reg,&data,1);
  return data;
}
uint8_t DFRobot_AS7341::readReg(uint8_t reg, void* pBuf, size_t size) 
{
  if (pBuf == NULL) {
    DBG("pBuf ERROR!! : null pointer");
  }
  uint8_t * _pBuf = (uint8_t *)pBuf;
  _pWire->beginTransmission(_address);
  _pWire->write(reg);
  if ( _pWire->endTransmission() != 0) {
    return 0;
  }
  delay(10);
  _pWire->requestFrom(_address, size);
  for (uint16_t i = 0; i < size; i++) {
    _pBuf[i] = _pWire->read();
  }
  return size;
}
