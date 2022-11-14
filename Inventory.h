/**
 * @file Inventory.h
 * @author Nathan Kolakaluri
 * @brief Header files for Inventory
 * @date 2022-11-13
 *
 */

#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include "Movie.h"

class Inventory
{
public:
    friend std::ostream &operator<<(std::ostream &out, const Inventory);

    Inventory();
    ~Inventory();

    Inventory getInventory();
    Inventory getInventory(std::string customerID, Movie movie);

    bool addToInventory(char movieType, int stock, std::string director);
    bool borrowMovie(std::string customerID, Movie movie);
    bool returnMovie(Movie movie);

    void displayInventory();

private:
    std::map<std::string, std::unordered_map<int, Movie>> comedyMap;
    std::map<std::string, std::unordered_map<std::string, Movie>> dramaMap;
    std::map<std::string, std::unordered_map<std::string, Movie>> classicMap;
};
