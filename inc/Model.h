#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "../inc/Detail.h"

class Model {
  private:
    std::vector<Detail> Details;

        
  public:
    Model();
    ~Model();
    void getAllDetails();
    void printDetails();
    void select();
};

#endif