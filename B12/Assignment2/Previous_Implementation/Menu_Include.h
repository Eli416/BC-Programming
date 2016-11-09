#include <vector>
#include <iostream>
#include "Methods_Include.h"
using namespace std;

/* DOC(displays a list of options and will call designated function 
       depending upon the character input given by user. Will print 
       an "invalid" statement if input is not recognized and will 
       print menu again. Entering 'q' or 'Q' will end function.
       @param playerJerseys
       @param playerRatings )*/
void runMenu(vector<int>& playerJerseys, vector<int>& playerRatings){
    char menuChoice;
    do{
        cout << "\t  ====MENU====\n\t"
            <<  "a - Add player\n\t"
            <<  "d - Remove player\n\t" 
            <<  "u - Update player rating\n\t"
            <<  "r - Output players above a rating\n\t" 
            <<  "o - Output roster\n\t"
            <<  "q - Quit\n\n"
            <<  "Choose an option:";
        
        cin >> menuChoice;    

        if(menuChoice == 'a' || menuChoice == 'A'){
            addPlayer(playerJerseys, playerRatings);
        }
        else if(menuChoice == 'd' || menuChoice == 'D'){
            removePlayer(playerJerseys, playerRatings);
        }
        else if(menuChoice == 'u' || menuChoice == 'U'){
            updateRating(playerJerseys, playerRatings);
        }
        else if(menuChoice == 'r' || menuChoice == 'R'){
            getAboveRating(playerJerseys, playerRatings);
        }
        else if(menuChoice == 'o' || menuChoice == 'O'){
            outputRoster(playerJerseys, playerRatings);
        }
        else if(menuChoice == 'q' || menuChoice == 'Q'){
            break;
        }
        else {
            cout << "Please enter a valid option.\n";
        }
        cout << endl;
    }while (menuChoice != 'q' && menuChoice != 'Q');
}

/* DOC(Prompts the user for the number of player structs to be added to 
       players vector then prompts the user to enter a jersey number and 
       rating. Gets a valid number for each and assigns those values to 
       player struct to be pushed onto the players vector.
       @param playerJerseys
       @param playerRatings )*/
void runInit(vector<int>& playerJerseys, vector<int>& playerRatings){
    cout << "How many players would you like to enter?\n";
    int initNumber;
    cin >> initNumber;
    for(int i = 0; i < initNumber; ++i){
        cout << "Enter player " << i + 1 << "\'s jersey: ";
        playerJerseys.push_back(getValidJersey());
        cout << "Enter player " << i + 1 << "\'s rating: ";
        playerRatings.push_back(getValidRating());
        cout << endl;
    }
    outputRoster(playerJerseys, playerRatings);
    runMenu(playerJerseys, playerRatings);
}
//Begin Single Parameter Implementation

/* DOC(displays a list of options and will call designated function 
       depending upon the character input given by user. Will print 
       an "invalid" statement if input is not recognized and will 
       print menu again. Entering 'q' or 'Q' will end function.
       @param players )*/
void runMenu(vector<int>* players[]){
    char menuChoice;
    do{
        cout << "\t  ====MENU====\n\t"
            <<  "a - Add player\n\t"
            <<  "d - Remove player\n\t" 
            <<  "u - Update player rating\n\t"
            <<  "r - Output players above a rating\n\t" 
            <<  "o - Output roster\n\t"
            <<  "q - Quit\n\n"
            <<  "Choose an option:";
        
        cin >> menuChoice;    

        if(menuChoice == 'a' || menuChoice == 'A'){
            addPlayer(players);
        }
        else if(menuChoice == 'd' || menuChoice == 'D'){
            removePlayer(players);
        }
        else if(menuChoice == 'u' || menuChoice == 'U'){
            updateRating(players);
        }
        else if(menuChoice == 'r' || menuChoice == 'R'){
            getAboveRating(players);
        }
        else if(menuChoice == 'o' || menuChoice == 'O'){
            outputRoster(players);
        }
        else if(menuChoice == 'q' || menuChoice == 'Q'){
            break;
        }
        else {
            cout << "Please enter a valid option.\n";
        }
        cout << endl;
    }while (menuChoice != 'q' && menuChoice != 'Q');
}

/* DOC(Prompts the user for the number of player structs to be added to 
       players vector then prompts the user to enter a jersey number and 
       rating. Gets a valid number for each and assigns those values to 
       player struct to be pushed onto the players vector.
       @param players )*/
void runInit(vector<int>* players[]){
    cout << "How many players would you like to enter?\n";
    int initNumber;
    cin >> initNumber;
    for(int i = 0; i < initNumber; ++i){
        cout << "Enter player " << i + 1 << "\'s jersey: ";
        players[0]->push_back(getValidJersey());
        cout << "Enter player " << i + 1 << "\'s rating: ";
        players[1]->push_back(getValidRating());
        cout << endl;
    }
    outputRoster(players);
    runMenu(players);
}
