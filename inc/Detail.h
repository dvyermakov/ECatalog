#ifndef DETAIL_H
#define DETAIL_H

#include <string>

#include "Component.h"
#include "Place.h"

class Detail {
  private:
    uint Id;
    Component component;
    double Count;
    double Price;
    Place place;
        
  public:
    Detail();
    Detail (uint _Id, Component _component, double _Count, double _Price, Place _place);
    ~Detail();
    int getId();
    std::string getTypeName();
    std::string getComponentName();
    std::string getPackageName();
    double getPrice();
    double getCount();
    std::string getPlaceName();
};

#endif