//
//  Customer.h
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#ifndef Customer_h
#define Customer_h

class Customer {
private:
  int customer_id;
  std::string first_name;
  std::string last_name;

public:
  void setCustomer(int customer_id, std::string first_name, std::string last_name);
  int getID() const;
};

#endif /* Customer_h */
