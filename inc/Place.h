#ifndef PLACE_H
#define PLACE_H

#include <string>

class Place {
  private:
    uint Id;
    std::string Name;
    uint ParentId;
        
  public:
    Place();
    Place(uint _Id, std::string _Name, uint _ParentId);
    Place& operator=(const Place &rhs);
    ~Place();

    void PrintPlace();
    std::string getName();
};

#endif