#include <iostream>
#include "TemperatureModel.h"

TemperatureModel::TemperatureModel(float tempF){
  _temperatureF = tempF;
}

float TemperatureModel::getF(){
  return _temperatureF;
}

float TemperatureModel::getC(){
  return (_temperatureF - 32.0) * 5.0 / 9.0;
}

void TemperatureModel::setF(float tempF){
  _temperatureF = tempF; 
  notifyUpdate();   
}

void TemperatureModel::setC(float tempC){
  _temperatureF = tempC * 9.0 / 5.0 + 32.0;
  notifyUpdate(); 
}