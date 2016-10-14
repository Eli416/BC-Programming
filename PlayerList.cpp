#include <vector>
#include "PlayerList.h"
#include <limits>



/* 
   DOC(Takes user input and prompts if invalid
       @param  min    Mininum acceptable value
       @param  max    Maximum acceptable value
       @param  option Alters prompt, 'j' for jersey, 'r' for rating,
                      and 'n' for number of players
       @return valid number) 
*/
int PlayerList::getValidNumber(int min, int max, char option){
    int retInt = -1;
    int hasRun = 0;
    do{
        if(hasRun){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{
            hasRun = 2;
        }
        switch(option){
            case 'j':
            std::cout << "Please enter a jersey number ";
            break;
            case 'r':
            std::cout << "Please enter a rating ";
            break;
            case 'n':
            std::cout << "Please enter how many players you would like to add ";
            break;
        }
        std::cout << "(" << min << "-" << max << "): ";
        std::cin >> retInt;
        
    }while(std::cin.fail() || (retInt < min || retInt > max));
    return retInt;
}
/* 
   DOC(Constructs a PlayerList with empty jerseyNumbers and 
       size 100 ratingValues filled with 0's) 
*/
PlayerList::PlayerList(){
    jerseyNumbers.reserve(0);
    ratingValues.assign(100, 0);
}

/* 
   DOC(finds and returns the index of the jersey number given
       @param jersey the jersey number to search for
       @return index of searched jersey or -1 if not find) 
*/
int PlayerList::getMemberJersey(int jersey){
    int index = -1;
    for(int i = 0; i < jerseyNumbers.size(); ++i){
        if(jerseyNumbers.at(i) == jersey)
            index = i;
    }
    return index;
}
/* 
   DOC(Prints out the main menu) 
*/
void PlayerList::printMenu(){
    std::cout << std::endl 
        << "    ====MENU====" << std::endl
        << " a - Add player" << std::endl
        << " m - Add multiple players" << std::endl
        << " d - Remove player" << std::endl 
        << " u - Update player rating" << std::endl
        << " r - Output players above a rating" << std::endl 
        << " o - Output roster" << std::endl
        << " q - Quit" << std::endl
        << "Choose an option:";
}
/* 
   DOC(Prompts the user for a rating then prints the roster of those
       players with rating above the input) 
*/
void PlayerList::printAboveRating(){
    int ratingAbove = getValidNumber(1,9,'r');
    std::cout << std::endl << "=== ABOVE " << ratingAbove << " ===" << std::endl;
    for(int i = 0; i < jerseyNumbers.size(); ++i){
        int jersey = jerseyNumbers.at(i);
        int rating = ratingValues.at(jersey);
        if(rating > ratingAbove){
            std::cout << "Player " << i + 1<< "'s jersey: " 
                << (jersey < 10 ? "0": "") 
                << jersey << "  rating: " << rating << std::endl;
        }
    }
}
/* 
   DOC(Prints out the roster) 
*/
void PlayerList::printRoster(){
    std::cout << std::endl << "=== ROSTER === " << std::endl;
    for(int i = 0; i < jerseyNumbers.size(); ++i){
        int jersey = jerseyNumbers.at(i);
        int rating = ratingValues.at(jersey);
        std::cout << "Player " << i + 1<< "'s jersey: " 
            << (jersey < 10 ? "0": "") 
            << jersey << "  rating: " << rating << std::endl;
    }
}
/*
   DOC(Prompts the user for a jersey and rating then adds the player
       to the list if the jersey number doesn't already exist)
*/
void PlayerList::addPlayer(){
    int jersey = getValidNumber(0,99,'j');
    int rating = getValidNumber(1,9,'r');
    if(ratingValues.at(jersey) < 1 || ratingValues.at(jersey) > 9){
        jerseyNumbers.push_back(jersey);
        ratingValues.at(jersey) = rating;
    }
    else{
        std::cout << "Jersey " << jersey 
            << " already exists. Player not added." << std::endl;
        std::cout << "Try another jersey (y/n)? ";
        char in;
        std::cin >> in;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(in == 'y'){
            addPlayer();
        }
    }
}
/*
   DOC(Prompts the user for the number of players to add,
       then adds that number of players)
*/
void PlayerList::addMultiPlayer(){
    int numPlayers = getValidNumber(0,20,'n');
    for(int i = 0; i < numPlayers; ++i){
        addPlayer();
    }
}
/*
   DOC(Prompts the user for a jersey number then removes that 
       jersey number from the list if it exists)
*/
void PlayerList::removePlayer(){
    int jersey = getValidNumber(0,99, 'j');
    int index = getMemberJersey(jersey);
    if(index < 0){
        std::cout << "Jersey " << jersey 
            << " is invalid. No player removed." << std::endl;
    }
    else {
        jerseyNumbers.erase(jerseyNumbers.begin() + index);
        ratingValues.at(jersey) = 0;
    }
}
/* 
   DOC(Prompts the user for a jersey number to update, then
       prompts the user for a new rating)
*/

void PlayerList::updatePlayer(){
    if(jerseyNumbers.size() > 0){
        int jersey = getValidNumber(0, 99, 'j');
        while (ratingValues.at(jersey) < 1){
            std::cout << "Invalid jersey number" << std::endl;
            printRoster();
            jersey = getValidNumber(0,99,'j');
        }
        int rating = getValidNumber(1, 9, 'r');
        ratingValues.at(jersey) = rating;
        std::cout << "Player "<< jersey << "'s rating was updated to: " 
            << rating  << std::endl;;
    }
    else{
        std::cout << "There are no players." << std::endl;
    }
}
/*
   DOC(Adds a number of players, prints roster, then prints main menu
       and processes user choice)
*/
void PlayerList::runMenu(){
    addMultiPlayer();
    printRoster();
    char inChoice;
    do{
        printMenu();
        std::cin >> inChoice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(inChoice){
            case 'A':
            case 'a':
                addPlayer();
                break;
            case 'D':
            case 'd':
                removePlayer(); 
                break;
            case 'U':
            case 'u':
                updatePlayer(); 
                break;
            case 'R':
            case 'r':
                printAboveRating(); 
                break;
            case 'O':
            case 'o':
                printRoster(); 
                break;
            case 'M':
            case 'm':
                addMultiPlayer(); 
                break;
            case 'Q':
            case 'q':
                std::cout << "Thank you, Have a nice day!" << std::endl;
                break;
            default:
                std::cout << "Enter a valid choice, please." << std::endl; 
                break;
        }
    }while(inChoice != 'q' && inChoice != 'Q' && !std::cin.fail());
}


