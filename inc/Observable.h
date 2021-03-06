#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observer.h"

class Observable {
  public:
    void addObserver(Observer *observer);
    void notifyUpdate();
  private:
    std::vector<Observer*> _observers;
};

#endif