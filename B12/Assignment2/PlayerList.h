/*
Author:     Halpin, Sean
Group:      Hernandez, Andrea; Hernandez, Antonio; 
            Hernandez, Enrique;
Assignment: Programming Assignment 2
Course:     COMP B12
Instructor: Richard Miles
Date Sub.:  2016/10/15
*/
#include <iostream>
#include <vector>
#include <limits>

#ifndef PlayerList_H
#define PlayerList_H

class PlayerList {
  public:
    PlayerList(void);
    int GetValidNumber(int,int,char);
    int GetMemberJersey(int);
    int IsTeamFull();
    void PrintAboveRating(void);
    void PrintRoster(void);
    void InsertSortedJersey(int, int, int);
    void AddPlayer(void);
    void AddMultiPlayer(void);
    void RemovePlayer(void);
    void UpdatePlayer(void);
    void RunMenu(void);
    void PrintMenu(void);
    
  private:
    std::vector<int> jersey_numbers;
    std::vector<int> rating_values;
    int num_players;
};
#endif
