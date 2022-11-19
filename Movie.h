//
//  Movie.h
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#ifndef Movie_h
#define Movie_h

#include <string>
#include "Type.h"

class Movie {
  
public:
  void incrementStock() { stock++; };
  void decrementStock() { stock--; };

  void setStock(int argStock) { argStock = stock; }
  void setDirector(std::string argDirector) { argDirector = director; }
  void setTitle(std::string argTitle) { argTitle = title; }
  void setType(char argType) { Type movieType; movie_type.setType(argType); movieType = movie_type; }

  Type getType() { return movie_type; }
  int getStock() { return stock; }
  std::string getDirector() { return director; }
  std::string getTitle() { return title; }

private:
  Type movie_type;
  int stock;
  std::string director;
  std::string title;
};

class Comedy : public Movie {
public:
  void createMovie(int stock, std::string director, std::string title,
                   int yearRelease) {
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearRelease(yearRelease);
  };

  void setYearRelease(int argYearRelease) { argYearRelease = year_release; }
  int getYear() { return year_release; }

private:
  int year_release;
};

class Drama : public Movie {
public:
  void createMovie(char type, int stock, std::string director, std::string title,
                   int yearRelease) {
    setType(type);
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setYearRelease(yearRelease);
  };

  void setYearRelease(int argYearRelease) { argYearRelease = year_release; }
  int getYearRelease() { return year_release; }

private:
  int year_release;
};

class Classics : public Movie {
public:
  void createMovie(int stock, std::string director, std::string title,
                   std::string majorActor, std::string releaseDate) {
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setMajorActor(majorActor);
    setReleaseDate(releaseDate);
  }

  void setMajorActor(std::string majorActor) { majorActor = major_actor; }
  void setReleaseDate(std::string releaseDate) { releaseDate = release_date; }

  std::string getMajorActor() { return major_actor; }
  std::string getReleaseDate() { return release_date; }

private:
  std::string major_actor;
  std::string release_date;
};

#endif /* Movie_h */
