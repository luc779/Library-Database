/**
 * @file MovieDatabase.h
 * @author Ryan Leveck
 * @brief This is a header file for MovieDatabase
 * @date 2022-11-13
 *
 */
#pragma once

#include <string>
#include "Inventory.h"
#include "CustomerDatabase.h"
#include "Action.h"

class MovieDatabase {

public:

  //////////////////////////////////////////////////
  // moviedatabase constructor/destructor
  //////////////////////////////////////////////////
  MovieDatabase();
  MovieDatabase(const std::string &file_name);
  ~MovieDatabase();

  //////////////////////////////////////////////////
  // functions to open and read txt files
  //////////////////////////////////////////////////
  void readInventoryFile(const std::string &file_name);
  void readCustomerActions(const std::string &file_name);
  void fileOpener(const std::string &file_name, const std::string &where_from);

  //////////////////////////////////////////////////
  // functions to add lines read from txt files to their respective class (i.e inventory, customerdatabase)
  //////////////////////////////////////////////////
  void customerLineAdding(std::string &line);
  void inventoryLineAdding(std::string &line);
  void actionLineAdding(std::string &line);

  //////////////////////////////////////////////////
  // helper function to aid actionlineadding function
  //////////////////////////////////////////////////
  static Action actionHelper(Action &newAction, std::string &title, std::string &director,
      std::string &string_month, std::string &string_year, std::string &actor, std::stringstream &ss);

private:
  Inventory inventory;
  CustomerDatabase customerDatabase;

  void createInventoryDatabase();
  void createCustomerDatabase();
};
