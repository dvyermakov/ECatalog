#ifndef DETAILSMODEL_H
#define DETAILSMODEL_H

#include <vector>
#include <string>

#include "Observable.h"
#include "Detail.h"

class DetailsModel : public Observable{
  private:
    std::vector<Detail*> Details;
    std::vector<std::string> Captions = {"Id", "Тип", "Название", "Корпус", "Цена", "Количество", "Место хранения"};
        
  public:
    DetailsModel();
    ~DetailsModel();
    
    void select();
    std::vector<std::string> getCaptions();
    std::vector<std::vector<std::string>> getTable();

};

#endif