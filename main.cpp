#include <iostream>
#include <string>

#include "inc/DetailsModel.h"
#include "inc/DetailsConsoleView.h"
#include "inc/DetailsController.h"
#include "inc/dbg.h"


int main(int argc, char *argv[]){
  DetailsModel model;
  DetailsConsoleView consoleView(&model);
  DetailsController controller(&model);
  int command = 0;
  do {
    system("clear");
    std::cout << "\tВведите код таблицы:" << std::endl;
    std::cout << "\t\t1 - Details" << std::endl;
    std::cout << "\t\tn - Не реализовано" << std::endl;
    std::cout << "\t\t0 - Выход" << std::endl;
    scanf("%d", &command);
    switch (command){
      case 1:{
          controller.start();
          break;
      }
      default:{
        break;
      }
    }
  } while (command != 0);
  system("clear");
  return 0;
}