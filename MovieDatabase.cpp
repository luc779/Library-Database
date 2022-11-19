//
//  MovieDatabase.cpp
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Movie.h"
#include "MovieDatabase.h"

// void HashTable::insertItem(int key, int data)
// {
//   int index = hashFunction(key);
//   table[index].push_back(data);
// }

MovieDatabase::MovieDatabase() {}

// constructor for MovieDatabase
MovieDatabase::MovieDatabase(const std::string file_name) {
    
    std::string where_from = "customer";
    fileOpener(file_name, where_from);
}

// function to add lines
void MovieDatabase::customerLineAdding(std::string line) {
    
    Customer newCustomer;
    
    int customerID;
    std::string first_name;
    std::string last_name;
    
    std::istringstream iss(line);
    iss >> customerID >> last_name >> first_name;
    
    newCustomer.setCustomer(customerID, first_name, last_name);
    
}

MovieDatabase::~MovieDatabase() {}

// method to read file for Inventory
void MovieDatabase::readInventoryFile(const std::string file_name) {
    std::string where_from = "inventory";
    fileOpener(file_name, where_from);
}

void MovieDatabase::inventoryLineAdding(std::string line) {
    
}

// method to read customer actions (B, H, R)
void MovieDatabase::readCustomerActions(const std::string file_name) {
    std::string where_from = "action";
    fileOpener(file_name, where_from);
}

void MovieDatabase::actionLineAdding(std::string line) {
}

// helper function to open and read file
void MovieDatabase::fileOpener(const std::string file_name, const std::string where_from) {
    
    std::ifstream myfile(file_name);
    if (!myfile.is_open())  {
        std::cout << "Failed to open " << file_name << std::endl;
    }

    std::string line;
    while(getline(myfile,line)) {

        if (where_from == "customer")  {
            customerLineAdding(line);
        } else if (where_from  == "inventory") {
            inventoryLineAdding(line);
        } else if (where_from == "action") {
            actionLineAdding(line);
        }
    }
    myfile.close();
}
