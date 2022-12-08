//#include "MediaType.h"
#include <string>
#include <iostream>
#pragma once

/////////////////////////////////////////////////////////////
// class Action deals with all the actions customers can use 
//such as borrow, return, inventory and history
////////////////////////////////////////////////////////////
class Action {
public:

    // overload the operator << for the Action class
    // depending on what the Action is it will output different variations
    friend std::ostream& operator<<(std::ostream& out, const Action& action) {  

        if (action.getActionType() == "H") {
            out << action.getActionType() << "\r";

        } else if (action.getActionType() == "R" || action.getActionType() == "B") {
            out << action.getActionType() << " " <<  action.getMediaType()<< " " << action.getMovieType() << " ";

            if (action.getMovieType() == "C") {
                out << action.getMonth() << " " << action.getYear() << " " << action.getMajorActor() << "\r";

            } else if (action.getMovieType() == "D") {
                out << action.getDirector() << "," << action.getTitle() << "\r";

            } else if (action.getMovieType() == "F") {
                out << action.getTitle() << "," << action.getYear() << "\r";
            }
        } else {
            out << action.getActionType() << "\r";
        }

        return out;
    }

    //////////////////////////////////////////////////
    // setters for action class (type, movie type, media type, director, major actor, month, year, title)
    //////////////////////////////////////////////////
    void setType (std::string actionType) { action_type = actionType; }
    void setMovieType (std::string movieType) { movie_type = movieType; }
    void setMediaType (std::string mediaType) { media_type = mediaType; }
    void setDirector (std::string argDirector) { director = argDirector; }
    void setMajorActor (std::string argMajorActor) { majorActor = argMajorActor; }
    void setMonth (std::string argMonth) { month = argMonth; }
    void setYear (std::string argYear) { year = argYear; }
    void setTitle (std::string argTitle) { title = argTitle; }

    //////////////////////////////////////////////////
    // getters for action class (type, movie type, media type, director, major actor, month, year, title)
    //////////////////////////////////////////////////
    std::string getActionType() const { return action_type; }
    std::string getMovieType() const { return movie_type; }
    std::string getMediaType() const { return media_type; }
    std::string getDirector() const { return director; }
    std::string getMajorActor() const { return majorActor; }
    std::string getMonth() const { return month; }
    std::string getYear() const { return year; }
    std::string getTitle() const {return title; }

    
    
private:

    //////////////////////////////////////////////////
    // instance variables of Action
    //////////////////////////////////////////////////
    std::string action_type;
    std::string media_type;
    std::string movie_type;
    std::string director;
    std::string majorActor;
    std::string month;
    std::string year;
    std::string title;
};
