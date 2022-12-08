//
//  Customer.h
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#pragma once
#include "CustomerHistory.h"

//////////////////////////////////////////////////
// class Customer acts as an object for keeping 
// store of each customer in the program
//////////////////////////////////////////////////
class Customer {
  
private:
  // instance variables of Customer
  int customer_id;
  std::string first_name;
  std::string last_name;

public:
  //////////////////////////////////////////////////
  // setting customer id, first name and last name
  //////////////////////////////////////////////////
  void setCustomer(int argCustomerId, std::string argFirstName, std::string argLastName) {
    customer_id = argCustomerId;
    first_name = argFirstName;
    last_name = argLastName;
  };

  //////////////////////////////////////////////////
  // overload for == operator
  //////////////////////////////////////////////////
  bool operator==(const Customer& cust) const {
    return (customer_id == cust.customer_id && first_name == cust.first_name)
     && last_name == cust.last_name;
  }

  //////////////////////////////////////////////////
  // getter for customerID
  //////////////////////////////////////////////////
  int getID() const { return customer_id; }
};
