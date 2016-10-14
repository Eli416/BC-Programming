#include <iostream>
#include <vector>
#include <limits>

#ifndef PlayerList_H
#define PlayerList_H

class PlayerList {
    public:
        PlayerList(void);
        int getValidNumber(int,int,char);
        int getMemberJersey(int);
        void printAboveRating(void);
        void printRoster(void);
        void addPlayer(void);
        void addMultiPlayer(void);
        void removePlayer(void);
        void updatePlayer(void);
        void runMenu(void);
        void printMenu(void);
    
    private:
        std::vector<int> jerseyNumbers;
        std::vector<int> ratingValues;
};
#endif
