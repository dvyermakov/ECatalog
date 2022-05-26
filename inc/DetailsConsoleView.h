#ifndef DETAILSCONSOLEVIEW_H
#define DETAILSCONSOLEVIEW_H

#include "Observer.h"
#include "DetailsModel.h"

class DetailsConsoleView : public Observer {
  private:
    DetailsModel *Model;   
    int LineLength;
    void checkMaximumLengths(const std::vector<std::string> &row, std::vector<int> &lengths);
    void print_(int count);
    void printHorizontalLine(int lineLength);
    void printLeftBorder();
    void printVerticalLine();
  public:
    DetailsConsoleView(DetailsModel *_model);
    virtual void update();

    
};

#endif