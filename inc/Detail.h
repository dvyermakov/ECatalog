#ifndef DETAIL_H
#define DETAIL_H

#include <vector>
#include <string>

class Detail {
  private:
    int Id;
    int ComponentId;
    double Count;
    double Price;
    int PlaceId;
        
  public:
    Detail(int id, int componentId, float count, float price, int placeId);
};

#endif