//
//  MovieDatabase.hpp
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#ifndef MovieDatabase_h
#define MovieDatabase_h

#include <string>
#include "Inventory.h"
#include "CustomerDatabase.h"

class MovieDatabase {

public:
    MovieDatabase();
    MovieDatabase(const std::string file_name);
    ~MovieDatabase();

    void readInventoryFile(const std::string file_name);
    void readCustomerActions(const std::string file_name);
    void fileOpener(const std::string file_name, const std::string where_from);

    void customerLineAdding(std::string line);
    void inventoryLineAdding(std::string line);
    void actionLineAdding(std::string line);

private:
    Inventory inventory;
    CustomerDatabase customerDatabase;

//    void createInventoryDatabase();
//    void createCustomerDatabase();
};

#endif /* MovieDatabase_h */
