#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
  private:
    uint Id;
    std::string Name;
        
  public:
    Package();
    Package(uint _Id, std::string _Name);
    Package& operator=(const Package &rhs);
    ~Package();
};

#endif