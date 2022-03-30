#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Controller.h"
#include "TemperatureModel.h"

class Controller {
  private:
      TemperatureModel *_model;;         
  public:
    Controller(TemperatureModel *model);
    void start();
};

#endif