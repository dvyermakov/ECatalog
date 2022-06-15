#include <iostream>
#include "../inc/DetailsController.h"

DetailsController::DetailsController(DetailsModel *model){
  _model = model;
}

void DetailsController::start(){
  int command = 0;
  do{
    system("clear");
    std::cout << "\tВведите команду:" << std::endl;
    std::cout << "\t\t1 - Поиск детали по названию" << std::endl;
    std::cout << "\t\tn - не реализовано" << std::endl;
    std::cout << "\t\t0 - Вернутся к выбору таблиц" << std::endl;
    scanf("%d", &command);
    switch (command) {
      case (1):{
        system("clear");
        std::cout << "\tВведите название компонента или его начало:" << std::endl;
        std::string nameLike;
        std::cin >> nameLike;
        _model->select(nameLike);
        std::cout << "\tНажмите 0 для продолжения..." << std::endl;
        int tmp;
        scanf("%d", &tmp);
        break;
      }
      default:{
        break;
      }
    }
  }
  while (command != 0);
}