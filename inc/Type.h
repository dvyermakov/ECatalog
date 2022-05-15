#ifndef TYPE_H
#define TYPE_H

#include <string>

class Type {
  private:
    uint Id;
    std::string Name;
    uint ParentId;
        
  public:
    Type();
    Type(uint _Id, std::string _Name, uint _ParentId);
    Type& operator=(const Type &rhs);
    ~Type();
};

#endif