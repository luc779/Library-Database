//
//  CustomerHistory.hpp
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#ifndef CustomerHistory_h
#define CustomerHistory_h

#include <vector>
#include <string>
#include "Action.h"

class CustomerHistory {
private:
  std::vector<Action> action_vector;

public:
  bool addToHistory(std::string action, char movie_type, std::string director, std::string title, int year);
  bool addToHistory(std::string action, char movie_type, std::string director, std::string title, std::string major_actor, int release_date);
};

#endif /* CustomerHistory_h */
