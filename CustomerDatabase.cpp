#include "CustomerDatabase.h"
#include <algorithm>
#include <iostream>
#include <list>

//////////////////////////////////////////////////
// void method to add customer to the storage 
// of the customerDatabase
//////////////////////////////////////////////////
void CustomerDatabase::addCustomer(const Customer &argCustomer) {
    CustomerHistory new_customer_history;
    customerMap[argCustomer] = new_customer_history;
}

//////////////////////////////////////////////////
// get customer history based on ID
//////////////////////////////////////////////////
int CustomerDatabase::getCustomerHistory(int argCustomerID) {
    for (const auto& i : customerMap) {
        if (i.first.getID() == argCustomerID) {
            i.second.getHistory();
        }
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
// addCustomerHistory method checks what type of Action is passed,
// throught if its a History check, uses customerID to show that persons history,
// then adds that history check to the history, if not a history check just adds,
// it to customerHistory object
/////////////////////////////////////////////////////////////////////////////////
void CustomerDatabase::addCustomerHistory(int customerID, const Action &argAction) {

    if (argAction.getActionType() == "H") {
        std::cout << "\nChecking History of, " << customerID << ": " << std::endl;
        getCustomerHistory(customerID);
    } 

    for (auto& i : customerMap) {
        if (i.first.getID() == customerID) {
            i.second.addToHistory(argAction);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
// customerExist returns true if customerId is in database
/////////////////////////////////////////////////////////////////////////////////
bool CustomerDatabase::customerExists(int customerID) {
    for (const auto &i : customerMap) {
        if (i.first.getID() == customerID) {
            return true;
        }
    }
    std::cout << "\nCustomer not in Database: \n" << "     " << customerID << std::endl;
    return false;
}

