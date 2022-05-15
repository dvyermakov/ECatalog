#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>

#include "Detail.h"

class Model {
  private:
    std::vector<Detail> Details;

        
  public:
    Model();
    ~Model();
    
};

#endif