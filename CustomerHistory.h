#pragma once
#include <list>
#include <string>
#include <iostream>
#include "Action.h"

//////////////////////////////////////////////////
// class CustomerHistory deals stores the, 
// customers history in a list
//////////////////////////////////////////////////
class CustomerHistory {
private:
  std::list<Action> action_list;

public:
  //////////////////////////////////////////////////
  // function to add action to action_list list
  //////////////////////////////////////////////////
  void addToHistory(Action argAction) { 
    action_list.push_front(argAction);
  }

  //////////////////////////////////////////////////
  // function to print/display history
  //////////////////////////////////////////////////
  void getHistory() const {
    if (action_list.empty()) {
      std::cout << "     No History" << std::endl;
    }

    for (const auto action : action_list) {
      std::cout << "     " << action << std::endl;
    }
  }
};
