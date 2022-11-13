/**
 * @file CustomerDatabase.h
 * @author Benjamin Nguyen
 * @brief Header files for CustomerDatabase, CustomerHistory, Action, and Customer
 * @date 2022-11-13
 *
 */

#pragma

#include <unordered_map>
#include <string>
#include <vector>
#include "Movie.h"

class CustomerDatabase
{
private:
    Customer customer;
    std::unordered_map<Customer, CustomerHistory> customerMap;

public:
    int getCustomerHistory(int customer_id);
    bool addCustomer(int customer_id, std::string first_name, std::string last_name);
    friend std::ostream &operator<<(std::ostream &, const CustomerDatabase);
};

class CustomerHistory : public CustomerDatabase
{
private:
    std::vector<Action> action_vector;

public:
    bool addToHistory(std::string action, char movie_type, std::string director, std::string title, int year);

    bool addToHistory(std::string action, char movie_type, std::string director, std::string title, std::string major_actor, int release_date);
};

class Action
{
private:
    char action;
    Movie movie;

public:
    void setAction(Action action);
    void setMovie(Movie movie);
    char getAction() const;
    char getMovie() const;
};

class Customer : public CustomerDatabase
{
private:
    int customer_id;
    std::string first_name;
    std::string last_name;

public:
    void setCustomer(int customer_id, std::string first_name, std::string last_name);
    int getID() const;
};
