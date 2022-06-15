#ifndef DETAILSCONTROLLER_H
#define DETAILSCONTROLLER_H

#include "DetailsModel.h"

class DetailsController {
  private:
      DetailsModel *_model;         
  public:
    DetailsController(DetailsModel *model);
    void start();
};

#endif