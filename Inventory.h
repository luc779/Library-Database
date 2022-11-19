//
//  Inventory.hpp
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#ifndef Inventory_h
#define Inventory_h

#include "Movie.h"
#include <map>
#include <string>
#include <unordered_map>

class Inventory {
public:
  friend std::ostream &operator<<(std::ostream &out, const Inventory);

  Inventory();
  ~Inventory();

  void getInventory();
  void getInventory(std::string customerID, Movie movie);

  bool addToInventory(char movieType, int stock, std::string director);
  bool borrowMovie(std::string customerID, Movie movie);
  bool returnMovie(Movie movie);


private:
  std::map<std::string, std::unordered_map<int, Movie>> comedyMap;
  std::map<std::string, std::unordered_map<std::string, Movie>> dramaMap;
  std::map<std::string, std::unordered_map<std::string, Movie>> classicMap;
};

#endif /* Inventory_h */
