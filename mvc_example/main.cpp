#include <iostream>
#include <string>

#include "TemperatureModel.h"
#include "ConsoleView.h"
#include "Controller.h"

int main(int argc, char *argv[]){
  TemperatureModel model(6);
  ConsoleView view(&model);
  Controller controller(&model);
  controller.start();
  return 0;
}