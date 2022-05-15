#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

#include "Type.h"
#include "Package.h"

class Component {
  private:
    uint Id;
    std::string Name;
    Type type;
    Package package;
        
  public:
    Component();
    Component(uint _Id, std::string _Name, Type _type, Package _package);
    Component& operator=(const Component &rhs);
    ~Component();
};

#endif