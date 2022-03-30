#include <iostream>
#include "Controller.h"

Controller::Controller(TemperatureModel *model){
  _model = model;
}

void Controller::start(){
  _model->setC(0);
  float temp;
  do{
    scanf("%f", &temp);
    _model->setC(temp);
  }
  while (temp != 0);
}