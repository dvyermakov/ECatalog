#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <functional>

#include "../inc/DetailsConsoleView.h"
#include "../inc/functions.h"

DetailsConsoleView::DetailsConsoleView(DetailsModel *model){
  Model = model;
  Model->addObserver(this);
}

void DetailsConsoleView::update(){
  system("clear");
  std::vector<std::string> captions = Model->getCaptions();
  std::vector<std::vector<std::string>> table = Model->getTable();
  std::vector<int> MaximumLengths = {0, 0, 0, 0, 0, 0, 0};
  checkMaximumLengths(captions, MaximumLengths);
  for (int i = 0; i < table.size(); ++i){
    std::vector<std::string> row = table[i];
    checkMaximumLengths(row, MaximumLengths);
  }
  LineLength = std::accumulate(MaximumLengths.begin(), MaximumLengths.end(), 0) + 22;
  printHorizontalLine(LineLength);
  printLeftBorder();
  for (int i = 0; i < captions.size(); ++i){
    std::cout << captions[i];
    print_(MaximumLengths[i] - strlen(captions[i]));
    printVerticalLine();
  }
  std::cout << std::endl;
  printHorizontalLine(LineLength);
  for (int i = 0; i < table.size(); ++i){
    std::vector<std::string> row = table[i];
    printLeftBorder();
    for (int j = 0; j < row.size(); ++j){
      std::cout << row[j];
      print_(MaximumLengths[j] - strlen(row[j]));
      printVerticalLine();
    }
    std::cout << std::endl;
  }
  printHorizontalLine(LineLength);
}

void DetailsConsoleView::print_(int count){
  for (int i = 0; i < count; ++i){
    std::cout << " ";
  }
}

void DetailsConsoleView::printHorizontalLine(int lineLength){
  std::cout << "\t";
  for (int i = 0; i < lineLength; ++i){
    std::cout << "-";
  }
  std::cout << std::endl;
}

void DetailsConsoleView::printLeftBorder(){
  std::cout << "\t| ";
}

void DetailsConsoleView::printVerticalLine(){
  std::cout << " | ";
}

void DetailsConsoleView::checkMaximumLengths(const std::vector<std::string> &row, std::vector<int> &lengths){
  for (int i = 0; i < row.size(); ++i){
    if (lengths[i] < strlen(row[i])){
      lengths[i] = strlen(row[i]);
    }
  }
}
