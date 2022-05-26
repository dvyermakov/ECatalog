#include <iostream>
#include <string>

#include "inc/DetailsModel.h"
#include "inc/DetailsConsoleView.h"
#include "inc/dbg.h"


int main(int argc, char *argv[]){
  DetailsModel model;
  DetailsConsoleView consoleView(&model);
  model.select();
  return 0;
}