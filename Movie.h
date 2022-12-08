/**
 * @file Movie.h
 * @author Luc Debaupte
 * @brief Header files for Movie, and its subclasses (including Comedy, Drama,
 * Classic)
 * @date 2022-11-13
 *
 */

#pragma once
#include <stdio.h>
#include <string>
//#include "Type.h"

class Movie {
// protected:
// virtual std::string& output(std::string out) const;
public:

  //////////////////////////////////////////////////
  // functions to increment/decrement stock
  //////////////////////////////////////////////////
  void incrementStock() { stock++; };
  void decrementStock() { stock--; };

  //////////////////////////////////////////////////
  // setters for stock, director, title, and type
  //////////////////////////////////////////////////
  void setStock(int argStock) { stock = argStock; }
  void setDirector(std::string argDirector) { director = argDirector; }
  void setTitle(std::string argTitle) { title = argTitle; }
  void setType(char argType) { movie_type = argType; }

  //////////////////////////////////////////////////
  // getters for type, stock, director, and title
  //////////////////////////////////////////////////
  char getType() { return movie_type; }
  int getStock() { return stock; }
  std::string getDirector() { return director; }
  std::string getTitle() { return title; }

private:
  char movie_type;
  int stock;
  std::string director;
  std::string title;
};

class Comedy : public Movie {
  // friend std::ostream& operator<<(std::ostream& out, Comedy& comedy);
public:

  //////////////////////////////////////////////////
  // function to create comedy movie with movie type, stock, director, title, year release
  //////////////////////////////////////////////////
  void createMovie(char &movie_type, int stock, std::string director, std::string title,
                   std::string yearRelease) {
    setType(movie_type);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearRelease(yearRelease);
  };

  void setYearRelease(std::string argYearRelease) { year_release = argYearRelease; }
  std::string getYearRelease() { return year_release; }

private:
  std::string year_release;
};

class Drama : public Movie {
  // friend std::ostream& operator<<(std::ostream& out, Drama& drama);
public:

  //////////////////////////////////////////////////
  // function to create drama movie with movie type, stock, director, title, year release
  //////////////////////////////////////////////////
  void createMovie(char &movie_type, int stock, std::string director, std::string title,
                   std::string yearRelease) {
    setType(movie_type);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearRelease(yearRelease);
  };

  void setYearRelease(std::string argYearRelease) { year_release = argYearRelease; }
  std::string getYearRelease() { return year_release; }

private:
  std::string year_release;
};

class Classics : public Movie {
  // friend std::ostream& operator<<(std::ostream& out, Classics& classic);
public:

  //////////////////////////////////////////////////
  // function to create classics movie with movie type, stock, director, title, major actor, and release date
  //////////////////////////////////////////////////
  void createMovie(char &movie_type, int stock, std::string director, std::string title,
                   std::string majorActor, std::string releaseDate) {
    setType(movie_type);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseDate(releaseDate);
  }

  void setMajorActor(std::string majorActor) { major_actor = majorActor; }
  void setReleaseDate(std::string releaseDate) { release_date = releaseDate; }

  std::string getMajorActor() { return major_actor; }
  std::string getReleaseDate() { return release_date; }

private:
  std::string major_actor;
  std::string release_date;
};
