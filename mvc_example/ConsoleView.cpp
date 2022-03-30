#include <iostream>
#include "ConsoleView.h"

ConsoleView::ConsoleView(TemperatureModel *model){
  _model = model;
  _model->addObserver(this);
}

void ConsoleView::update(){
  system("clear");
  printf("Temperature in Celsius: %.2f\n", _model->getC());
  printf("Temperature in Farenheit: %.2f\n", _model->getF());
  printf("Input temperature in Celsius: ");
}