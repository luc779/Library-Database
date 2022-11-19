//
//  Action.h
//  HW5
//
//  Created by Luc Debaupte on 11/18/22.
//

#ifndef Action_h
#define Action_h

class Action {
public:
    void setType(char movieType) { movieType = movie_type; }
    char getType() { return movie_type; }
private:
    char movie_type;
};

#endif /* Action_h */
