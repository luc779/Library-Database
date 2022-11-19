//
//  CustomerDatabase.hpp
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#ifndef CustomerDatabase_h
#define CustomerDatabase_h

#include <string>
#include <unordered_map>
#include <vector>
#include "Movie.h"
#include "Customer.h"
#include "CustomerHistory.h"

class CustomerDatabase {
  friend std::ostream &operator<<(std::ostream &, const CustomerDatabase);
private:
//   std::unordered_map<Customer, int,  CustomerHistory> customerMap;

public:
  int getCustomerHistory(int customer_id);
  bool addCustomer(int customer_id, std::string first_name, std::string last_name);
  
};

#endif /* CustomerDatabase_h */
