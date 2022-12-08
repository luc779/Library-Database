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
#include "Inventory.h"
#include "Action.h"

// destructor
MovieDatabase::~MovieDatabase() = default;

// constructor for MovieDatabase
MovieDatabase::MovieDatabase(const std::string &file_name) {
    
    std::cout << "=========================" << std::endl;
    std::cout << "| Reading Customer File |" << std::endl;
    std::cout << "========================="<< std::endl;
    
    std::string where_from = "customer";
    fileOpener(file_name, where_from);
}

//////////////////////////////////////////////////
// function to add line from customer text file
//////////////////////////////////////////////////
void MovieDatabase::customerLineAdding(std::string &line) {
    
    Customer new_customer;

    int customer_id;
    std::string first_name;
    std::string last_name;
    
    std::istringstream iss(line);
    iss >> customer_id >> last_name >> first_name;
    
    new_customer.setCustomer(customer_id, first_name, last_name);
    customerDatabase.addCustomer(new_customer);
}


//////////////////////////////////////////////////
// function to open and read inventory text file
//////////////////////////////////////////////////
void MovieDatabase::readInventoryFile(const std::string &file_name) {
    
    std::cout << "==========================" << std::endl;
    std::cout << "| Reading Inventory File |" << std::endl;
    std::cout << "=========================="<< std::endl;
    
    std::string where_from = "inventory";
    fileOpener(file_name, where_from);
}

//////////////////////////////////////////////////
// function to add line from inventory text file
//////////////////////////////////////////////////
void MovieDatabase::inventoryLineAdding(std::string &line) {

    char movie_type;
    movie_type = line[0];
    line.erase(0,3);

    std::istringstream ss(line);

    std::string stock_string;
    std::string year_string;
    std::string director;
    std::string title;
    int stock;
    
    // C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
    // C, Stock, Director, Title, Major actor Release date 
    if( movie_type == 'C') {

        std::string major_actor_first;
        std::string major_actor_last;

        std::string month_string;
        std::string useless;

        std::getline(ss, stock_string, ',');
        stock = std::stoi(stock_string);
        std::getline(ss, director, ',');
        director.erase(0,1);
        std::getline(ss, title, ',');
        title.erase(0,1);
        std::getline(ss, useless, ' ');
        std::getline(ss, major_actor_first, ' ');
        std::getline(ss, major_actor_last, ' ');
        major_actor_first += " " + major_actor_last;
        std::getline(ss, month_string, ' ');
        std::getline(ss, year_string);

        std::string release_date = year_string + " " + month_string;

        Classics new_classic;
        new_classic.createMovie(movie_type, stock, director, title, major_actor_first, release_date);

        inventory.addToInventory(new_classic);

    // D, 10, Clint Eastwood, Unforgiven, 1992
    // D, Stock, Director, Title, Year it released
    } else if (movie_type == 'D') {
        
        std::getline(ss, stock_string, ',');
        stock = std::stoi(stock_string);
        std::getline(ss, director, ',');
        director.erase(0,1);
        std::getline(ss, title, ',');
        title.erase(0,1);
        std::getline(ss, year_string);

        Drama new_drama;
        new_drama.createMovie(movie_type, stock, director, title, year_string);
        inventory.addToInventory(new_drama);

    // F, 10, John Landis, National Lampoon's Animal House, 1978
    // F, Stock, Director, Title, Year it released
    } else if (movie_type == 'F') {
        
        std::getline(ss, stock_string, ',');
        stock = stoi(stock_string);
        std::getline(ss, director, ',');
        director.erase(0, 1);
        std::getline(ss, title, ',');
        title.erase(0, 1);
        std::getline(ss, year_string);

        Comedy new_comedy;
        new_comedy.createMovie(movie_type, stock, director, title, year_string);
        inventory.addToInventory(new_comedy);
        
    } else {
        std::cout << "Invalid Movie Type:\n" << "     " << movie_type << std::endl;
    }
}

//////////////////////////////////////////////////
// function to read customer actions
//////////////////////////////////////////////////
void MovieDatabase::readCustomerActions(const std::string &file_name) {
    
    std::cout << "==================================" << std::endl;
    std::cout << "| Reading Customer Commands File |" << std::endl;
    std::cout << "=================================="<< std::endl;
    
    std::string where_from = "action";
    fileOpener(file_name, where_from);
}

//////////////////////////////////////////////////
// function to add line from action text file
//////////////////////////////////////////////////
void MovieDatabase::actionLineAdding(std::string &line) {

    Action new_action;
    std::string action_type(1, line[0]);
    new_action.setType(action_type);
    line.erase(0,2);

    std::stringstream ss(line);
    std::string string_customer_id;
    int customer_id;
    std::string director;
    std::string media_type;
    std::string movie_type;
    std::string title;
    std::string string_year;
    std::string string_month;
    std::string actor;

    // H 8000
    if (new_action.getActionType() == "H") {
        std::getline(ss,string_customer_id);
        customer_id = stoi(string_customer_id);
        
        if(!customerDatabase.customerExists(customer_id)) {
            return;
        }

    // B 8000 D F You've Got Mail, 1998
    // B 2000 D D Phillippe De Broca, King of Hearts,
    // B 8000 D C 3 1971 Ruth Gordon
    // R 5000 D C 3 1971 Ruth Gordon
    } else if (new_action.getActionType() == "B" || new_action.getActionType() == "R") {
        
        std::getline(ss,string_customer_id, ' ');
       customer_id = stoi(string_customer_id);
        std::getline(ss, media_type, ' ');
        std::getline(ss, movie_type, ' ');
        new_action.setMediaType(media_type);
        new_action.setMovieType(movie_type);

        if (new_action.getMediaType() == "D" && ((new_action.getMovieType() == "C" || new_action.getMovieType() == "D") || new_action.getMovieType() == "F")) {
            new_action = actionHelper(new_action, title, director, string_month, string_year, actor, ss);

        } else {
            std::cout << "\nInvalid media type\n    " << new_action << std::endl;
            return;
        }
        
        if (!customerDatabase.customerExists(customer_id)) {
            return;
        }

        if (new_action.getActionType() == "R") {
            inventory.borrowOrReturnMovie(new_action, false);
        } else {
            inventory.borrowOrReturnMovie(new_action, true);
        }
        
    // get inventory returns because it is not a customer command
    } else if (new_action.getActionType() == "I") {
        inventory.getInventory();
        return;
    } else {
        std::cout << "\nInvalid Command\n    " << new_action << std::endl;
        return;
    }

    customerDatabase.addCustomerHistory(customer_id, new_action);
        
}

Action MovieDatabase::actionHelper(Action &newAction, std::string &title, std::string &director,
    std::string &string_month, std::string &string_year, std::string &actor, std::stringstream &ss) {

    if (newAction.getMovieType() == "F") {
        std::getline(ss, title, ',');
        std::getline(ss, string_year);

    } else if (newAction.getMovieType() == "D") {
        std::getline(ss, director, ',');
        std::getline(ss, title, ',');
        title.erase(0,1);
                
    } else if (newAction.getMovieType() == "C") {
        std::getline(ss, string_month, ' ');
        std::getline(ss, string_year, ' ');
        std::getline(ss, actor);
    }

    newAction.setDirector(director);
    newAction.setMajorActor(actor);
    newAction.setMonth(string_month);
    newAction.setYear(string_year);
    newAction.setTitle(title);

    return newAction;
}

//////////////////////////////////////////////////
// function to open and read text file
//////////////////////////////////////////////////
void MovieDatabase::fileOpener(const std::string &file_name, const std::string &where_from) {
    
    std::ifstream myfile(file_name);
    if (!myfile.is_open())  {
        std::cout << "Failed to open\n " << file_name << "\n" << std::endl;
    }

    std::string line;
    while(getline(myfile,line)) {
        
        if (where_from == "customer")  {
            customerLineAdding(line);
        }
        if (where_from == "inventory") {
            inventoryLineAdding(line);
        }
        if (where_from == "action") {
            actionLineAdding(line);
        }
    }
    myfile.close();
}
