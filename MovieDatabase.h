/**
 * @file MovieDatabase.h
 * @author Ryan Leveck
 * @brief This is a header file for MovieDatabase
 * @date 2022-11-13
 *
 */
#ifndef MOVIE_DATABASE
#define MOVIE_DATABASE

#include <string>

class MovieDatabase {

public:
  MovieDatabase();
  MovieDatabase(std::string file_name);
  ~MovieDatabase();

  void readInventoryFile(std::string file_name);
  void readCustomerActions(std::string file_name);

private:
  void createInventoryDatabase();
  void createCustomerDatabase();
};

#endif
