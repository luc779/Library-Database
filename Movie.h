/**
 * @file Movie.h
 * @author Luc Debaupte
 * @brief Header files for Movie, and its subclasses (including Comedy, Drama,
 * Classic)
 * @date 2022-11-13
 *
 */
#pragma
#include <stdio.h>
#include <string>

class Movie {

public:
  void incrementStock() { stock++; };
  void decrementStock() { stock--; };

  void setStock(int argStock) { argStock = stock; }
  void setDirector(std::string argDirector) { argDirector = director; }
  void setTitle(std::string argTitle) { argTitle = title; }

  int getStock() { return stock; }
  std::string getDirector() { return director; }
  std::string getTitle() { return title; }

private:
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
  void createMovie(int stock, std::string director, std::string title,
                   int yearRelease) {
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
