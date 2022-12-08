/**
 * @file CustomerDatabase.h
 * @author Benjamin Nguyen
 * @brief Header files for CustomerDatabase, CustomerHistory, Action, and
 * Customer
 * @date 2022-11-13
 *
 */

#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "Movie.h"
#include "Customer.h"
#include "CustomerHistory.h"
#include "MyHashFunction.h"
#include "Action.h"

//////////////////////////////////////////////////
// class Customer Database deals with the storage 
// of customer and their history
//////////////////////////////////////////////////
class CustomerDatabase {

  //overload of operator<<
  friend std::ostream &operator<<(std::ostream &, const CustomerDatabase);
private:

  // map to keep track of customer, includes MyHashFunction as hashtable
  std::unordered_map<Customer, CustomerHistory, MyHashFunction> customerMap;

public:
  //////////////////////////////////////////////////
  // function to get history of customer
  //////////////////////////////////////////////////
  int getCustomerHistory(int customerID);

  //////////////////////////////////////////////////
  // function to add to customer history
  //////////////////////////////////////////////////
  void addCustomerHistory(int customerID, const Action &argAction);

  //////////////////////////////////////////////////
  // function to add customer 
  //////////////////////////////////////////////////
  void addCustomer(const Customer &argCustomer);

  //////////////////////////////////////////////////
  // function to check if customer exists
  //////////////////////////////////////////////////
  bool customerExists(int customerID);
};
