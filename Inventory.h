/**
 * @file Inventory.h
 * @author Nathan Kolakaluri
 * @brief Header files for Inventory
 * @date 2022-11-13
 *
 */

#pragma once
#include "Movie.h"
#include "Action.h"
#include <map>
#include <string>

//////////////////////////////////////////////////
// class inventory deals with all the storing of movies
//////////////////////////////////////////////////
class Inventory {
public:
  friend std::ostream &operator<<(std::ostream &out, const Inventory);

  //////////////////////////////////////////////////
  // inventory constructor/destructor
  //////////////////////////////////////////////////
  Inventory();
  ~Inventory();

  //////////////////////////////////////////////////
  // function to get/display inventory based on customer id
  //////////////////////////////////////////////////
  void getInventory();
  void getInventory(std::string customerID);

  //////////////////////////////////////////////////
  // functions to add to inventory based on what type the movie is (i.e comedy, drama, classic)
  //////////////////////////////////////////////////
  void addToInventory(Comedy movie);
  void addToInventory(Drama movie);
  void addToInventory(Classics movie);

  //////////////////////////////////////////////////
  // function to borrow/return movie based on action read (i.e B, R)
  //////////////////////////////////////////////////
  void borrowOrReturnMovie(const Action &action, bool borrow);

  //////////////////////////////////////////////////
  // functions to print each map respective to the type of movie (i.e comedy, drama, classic)
  //////////////////////////////////////////////////
  static std::string printComedy(Comedy movie);
  static std::string printDrama(Drama movie);
  static std::string printClassics(Classics movie);

private:
  //////////////////////////////////////////////////
  // comedy/drama/classic ordered maps
  //////////////////////////////////////////////////
  std::map<std::string, std::map<std::string, Comedy> > comedyMap;
  std::map<std::string, std::map<std::string, Drama> > dramaMap;
  std::map<std::string, std::map<std::string, Classics> > classicMap;
};
