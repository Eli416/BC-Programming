#include <vector>
#include <iostream>
using namespace std;

/* DOC(Takes user input and checks to make surea valid input was provided
       and within the valid range, 0-99 inclusive. 
       Then returns the valid input) */
int getValidJersey(){
    int retJersey = -1;
    cin >> retJersey;
    while(retJersey > 99 || retJersey < 0){
        cout << "Enter a jersey number (00 - 99): ";
        cin >> retJersey;
    }
    return retJersey;
} 
/* DOC(Takes user input and checks to make sure valid input was provided
       and within the valid range, 1-9 inclusive.
       Then returns the valid input) */
int getValidRating(){
    int retRating = -1;
    cin >> retRating;
    while (retRating < 1 || retRating > 9){
        cout << "Enter a rating (1-9): ";
        cin >> retRating;
    }
    return retRating;
}
/* DOC(Prints out entire list of players
       @param playerJerseys vector of player's Jersey numbers
       @param playerRatings vector of player's ratings) */
void outputRoster(vector<int>& playerJerseys, vector<int>& playerRatings){
    for(int i = 0; i < playerJerseys.size(); ++i){
        cout << "Player " << i + 1 
            << "-- Jersey number: " << playerJerseys.at(i)
            << ", Rating: " << playerRatings.at(i) << endl;
    }
}
/* DOC(Prompts the user for a jersey number and rating to be added
       @param playerJerseys vector of player's Jersey numbers
       @param playerRatings vector of player's ratings) */
void addPlayer(vector<int>& playerJerseys, vector<int>& playerRatings){
    cout << "Enter a new player\'s jersey number: ";
    playerJerseys.push_back(getValidJersey());
    cout << "Enter a new player\'s rating: ";
    playerRatings.push_back(getValidRating());
}
/* DOC(prompts the user for a jersey number of the player to be
       removed from the list of players
       @param playerJerseys vector of player's Jersey numbers
       @param playerRatings vector of player's ratings) */
void removePlayer(vector<int>& playerJerseys, vector<int>& playerRatings){
    int tempJersey, indexAt;
    int isFound = 0;
    while(!isFound){
        cout << "Enter a jersey number to remove: ";
        cin >> tempJersey;
        while(tempJersey > 100 || tempJersey < 0){
            cout << "Enter a valid jersey number to remove: ";
            cin >> tempJersey;
        }
        for(int i = 0; i < playerJerseys.size(); ++i){
            if(playerJerseys.at(i) == tempJersey){
                indexAt = i;
                isFound = 1;
                break;
            }
        }
        if(!isFound){
            cout << "Player not found.\n";
        }
    }
    int j = indexAt;
    while(j < playerJerseys.size() - 1){
        playerJerseys.at(j) = playerJerseys.at(j + 1);
        playerRatings.at(j) = playerRatings.at(j + 1);
        ++j;
    }
    playerJerseys.pop_back();
    playerRatings.pop_back();
}
/* DOC(Prompts the user for the jersey number and new rating for
       a player to be assigned a new rating.
       @param playerJerseys vector of player's Jersey numbers
       @param playerRatings vector of player's ratings) */
void updateRating(vector<int>& playerJerseys, vector<int>& playerRatings){
    int tempJersey, tempRating;
    
    cout << "Enter a jersey number: ";
    tempJersey = getValidJersey();
    cout << "Enter a new rating for player: ";
    tempRating = getValidRating();
    for(int i = 0; i < playerJerseys.size(); ++i){
        if(tempJersey == playerJerseys.at(i)){
            playerRatings.at(i) = tempRating;
            break;
        }
    }
}
/* DOC(Prompts the user for a rating value then prints out the list
       of players with a rating above the user input
       @param playerJerseys vector of player's Jersey numbers
       @param playerRatings vector of player's ratings) */
void getAboveRating(vector<int>& playerJerseys, vector<int>& playerRatings){
    cout << "Enter a rating: ";
    int rating = getValidRating();
    vector<int> playerJerseysAbove(0);
    vector<int> playerRatingsAbove(0);
    cout << "ABOVE " << rating << endl;
    for(int i = 0; i < playerJerseys.size(); ++i){
        if(playerRatings.at(i) > rating){
            playerRatingsAbove.push_back(playerRatings.at(i));
            playerJerseysAbove.push_back(playerJerseys.at(i));
        }
    }
    outputRoster(playerJerseysAbove, playerRatingsAbove);
}

//Begin Single Parameter Implementation


/* DOC(prints out entire list of players with respective jersey
       number and rating
       @param players array of pointer to vectors of Jersey numbers
                      and ratings) */
void outputRoster(vector<int>* players[]){
    for(int i = 0; i < players[0]->size(); ++i){
        cout << "Player " << i + 1 
            << "-- Jersey number: " << players[0]->at(i)
            << ", Rating: " << players[1]->at(i) << endl;
    }
}
/* DOC(Prompts the user for a jersey number and rating to be added
       to the list of players
       @param players array of pointer to vectors of Jersey numbers
                      and ratings) */
void addPlayer(vector<int>* players[]){
    cout << "Enter a new player\'s jersey number: ";
    players[0]->push_back(getValidJersey());
    cout << "Enter a new player\'s rating: ";
    players[1]->push_back(getValidRating());
}
/* DOC(prompts the user for a jersey number of the player to be
       removed from the list of players
       @param players array of pointer to vectors of Jersey numbers
                      and ratings) */
void removePlayer(vector<int>* players[]){
    int tempJersey, indexAt;
    int isFound = 0;
    while(!isFound){
        cout << "Enter a jersey number to remove: ";
        cin >> tempJersey;
        while(tempJersey > 100 || tempJersey < 0){
            cout << "Enter a valid jersey number to remove: ";
            cin >> tempJersey;
        }
        for(int i = 0; i < players[0]->size(); ++i){
            if(players[0]->at(i) == tempJersey){
                indexAt = i;
                isFound = 1;
                break;
            }
        }
        if(!isFound){
            cout << "Player not found.\n";
        }
    }
    int j = indexAt;
    while(j < players[0]->size() - 1){
        players[0]->at(j) = players[0]->at(j + 1);
        players[1]->at(j) = players[1]->at(j + 1);
        ++j;
    }
    players[0]->pop_back();
    players[1]->pop_back();
}
/* DOC(Prompts the user for the jersey number and new rating for
       a player to be assigned a new rating.
       @param players array of pointer to vectors of Jersey numbers
                      and ratings) */
void updateRating(vector<int>* players[]){
    int tempJersey, tempRating;
    
    cout << "Enter a jersey number: ";
    tempJersey = getValidJersey();
    cout << "Enter a new rating for player: ";
    tempRating = getValidRating();
    for(int i = 0; i < players[0]->size(); ++i){
        if(tempJersey == players[0]->at(i)){
            players[1]->at(i) = tempRating;
            break;
        }
    }
}
/* DOC(Prompts the user for a rating value then prints out the list
       of players with a rating above the user input
       @param players array of pointer to vectors of Jersey numbers
                      and ratings) */
void getAboveRating(vector<int>* players[]){
    cout << "Enter a rating: ";
    int rating = getValidRating();
    vector<int> playerJerseysAbove(0);
    vector<int> playerRatingsAbove(0);
    vector<int>* playersAbove[] = {&playerJerseysAbove, &playerRatingsAbove};
    cout << "ABOVE " << rating << endl;
    for(int i = 0; i < players[0]->size(); ++i){
        if(players[1]->at(i) > rating){
            playersAbove[0]->push_back(players[1]->at(i));
            playersAbove[1]->push_back(players[0]->at(i));
        }
    }
    outputRoster(playersAbove);
}
