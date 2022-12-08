//
//  Inventory.cpp
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#include "Inventory.h"
#include <iostream>

//////////////////////////////////////////////////
// inventory constructor/destructor
//////////////////////////////////////////////////
Inventory::Inventory() = default;

Inventory::~Inventory() = default;

//////////////////////////////////////////////////
// functions to print each map respective to the type of movie (i.e comedy, drama, classic)
//////////////////////////////////////////////////
std::string Inventory::printComedy(Comedy movie) {
    std::string out = "  ";
    out.push_back(movie.getType());
    out += ", " + std::to_string(movie.getStock()) + ", " + movie.getDirector() + ", " +  movie.getTitle() + ", " + movie.getYearRelease();
    return out;
}

std::string Inventory::printDrama(Drama movie) {
    std::string out = "  ";
    out.push_back(movie.getType());
    out += ", " + std::to_string(movie.getStock()) + ", " + movie.getDirector() + ", " +  movie.getTitle() + ", " + movie.getYearRelease();
    return out;
}

std::string Inventory::printClassics(Classics movie) {
    std::string out = "  ";
    std::string reverse_release_date = movie.getReleaseDate();
    std::string s2 = reverse_release_date;
    reverse_release_date.erase(0,5);
    reverse_release_date += " " + s2.substr(0,5);
    out.push_back(movie.getType());
    out +=  ", " + std::to_string(movie.getStock()) + ", " + movie.getDirector() + ", " +  movie.getTitle() + ", " + movie.getMajorActor() + ", " + reverse_release_date;
    return out;
}

//////////////////////////////////////////////////
// function to get/display inventory
//////////////////////////////////////////////////
void Inventory::getInventory() {

    std::cout << "======================" << std::endl;
    std::cout << "| Printing Inventory |" << std::endl;
    std::cout << "======================"<< std::endl;
    
    std::cout << "=======================================" << std::endl;
    std::cout << "Comedies Section: " << std::endl;
    std::cout << "======================================="<< std::endl;
    for (const auto &comedy : comedyMap) {
        for (const auto &comedy_inside : comedy.second) {
            std::cout << printComedy(comedy_inside.second) << std::endl;
        }
    }
    
    std::cout << "=======================================" << std::endl;
    std::cout << "Dramas Section: " << std::endl;
    std::cout << "======================================="<< std::endl;
    for (const auto &drama : dramaMap) {
        for (const auto &contents : drama.second) {
            std::cout << printDrama(contents.second) << std::endl;
        }
    }

std::cout << "=======================================" << std::endl;
    std::cout << "Classics Section: " << std::endl;
    std::cout << "======================================="<< std::endl;
    for (const auto &classic : classicMap) {
        for (const auto &contents : classic.second) {
            std::cout << printClassics(contents.second) << std::endl;
        }
    }
}

//////////////////////////////////////////////////
// functions to add to inventory based on what type the movie is (i.e comedy, drama, classic)
//////////////////////////////////////////////////
void Inventory::addToInventory(Comedy movie) {
    comedyMap[movie.getTitle()].insert({movie.getYearRelease(), movie});
}

void Inventory::addToInventory(Classics movie) {
    classicMap[movie.getReleaseDate()].insert({movie.getMajorActor(), movie});
}

void Inventory::addToInventory(Drama movie) {
    dramaMap[movie.getDirector()].insert({movie.getTitle(), movie});
}

//////////////////////////////////////////////////
// function to borrow/return movie based on action read (i.e B, R),
// decrement stock if boolean variable borrow is true, otherwise increment
//////////////////////////////////////////////////
void Inventory::borrowOrReturnMovie(const Action &action, bool borrow) {

    if (action.getMovieType() == "C") {
        std::string release_date = action.getYear() + " " + action.getMonth();
        for (auto& it: classicMap) {
            if(it.first == release_date) {
                for (auto& movie: it.second) {
                    if (movie.first == action.getMajorActor()) {
                        if (borrow) {
                            if (movie.second.getStock() == 0) {
                                std::cout << "\nOut of Stock:\n    " << action << std::endl;
                                return;
                            }
                            movie.second.decrementStock();
                            return;
                        }
                        movie.second.incrementStock();
                        return;
                    }
                }
            }
        }
        
    } else if (action.getMovieType() == "F") {
        for (auto& it: comedyMap) {
            if(it.first == action.getTitle()) {
                for (auto& movie: it.second) {
                    if (movie.first == action.getYear()) {
                        if (borrow) {
                            if (movie.second.getStock() == 0) {
                                std::cout << "\nOut of Stock:\n    " << action << std::endl;
                                return;
                            }
                            movie.second.decrementStock();
                            return;
                        }
                        movie.second.incrementStock();
                        return;
                    }
                }
            }
        }

    } else if (action.getMovieType() == "D") {
        for (auto& it : dramaMap) {
            if(it.first == action.getDirector()) {
                for (auto& movie: it.second) {
                    if(movie.first == action.getTitle()) {
                        if (borrow) {
                            if (movie.second.getStock() == 0) {
                                std::cout << "\nOut of Stock:\n    " << action << std::endl;
                                return;
                            }
                            movie.second.decrementStock();
                            return;
                        }
                        movie.second.incrementStock();
                        return;
                    }
                }
            }
        }
    }
    std::cout << "\nMovie Not In Database:\n    " << action << std::endl;
}
