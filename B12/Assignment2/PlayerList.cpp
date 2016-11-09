/*
Author:     Halpin, Sean
Group:      Hernandez, Andrea; Hernandez, Antonio;
            Hernandez, Enrique;
Assignment: Programming Assignment 2
Course:     COMP B12
Instructor: Richard Miles
Date Sub.:  2016/10/15
*/

#include "PlayerList.h"

/* Constructs a PlayerList with empty jersey_numbers and
   size 100 rating_values filled with 0's */
PlayerList::PlayerList() {
    jersey_numbers.reserve(0);
    rating_values.assign(100, 0);
    num_players = 0;
}

/* Takes user input and prompts if invalid
   @param  min    Mininum acceptable value
   @param  max    Maximum acceptable value
   @param  option Alters prompt, 'j' for jersey, 'r' for rating,
                  and 'n' for number of players
   @return valid number  */
int PlayerList::GetValidNumber(int min, int max, char option) {
    int index_num = -1;
    char has_run = 0;
    do{
        if (has_run) { 
            /*checks if loop has run once and clears input
              without, program holds here waiting for input */
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            has_run = !has_run;
        }
        switch(option) {
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
        std::cin >> index_num;
    } while(std::cin.fail() || (index_num < min || index_num > max));
    return index_num;
}

/* finds and returns the index of the jersey number given
   @param jersey the jersey number to search for
   @return index of searched jersey or -1 if not found */
int PlayerList::GetMemberJersey(int jersey) {
    int index = -1;
    int min = 0;
    int max = num_players - 1;
    int mid = 0;
    while (min <= max) {
        mid = (min + max) / 2;
        if (jersey_numbers.at(mid) < jersey) {
            min = mid + 1;
        } else if(jersey_numbers.at(mid) > jersey) {
            max = mid - 1;
        } else {
            index = mid;
            break;
        }
    }
    return index;
}

/* Prints out the main menu */
void PlayerList::PrintMenu() {
    std::cout << std::endl
        << "    ====MENU====" << std::endl
        << " a - Add player"  << (num_players >= 100 ? " (Team is full)": "") << std::endl
        << " m - Add multiple players"  << (num_players >= 100 ? " (Team is full)": "") << std::endl
        << " d - Remove player" << std::endl
        << " u - Update player rating" << std::endl
        << " r - Output players above a rating" << std::endl
        << " o - Output roster" << std::endl
        << " q - Quit" << std::endl
        << "Choose an option:";
}

/* Prompts the user for a rating then Prints the roster of those
   players with rating above the input */
void PlayerList::PrintAboveRating() {
    int rating_above = GetValidNumber(1,9,'r');
    std::cout << std::endl << "=== ABOVE " << rating_above << " ===" << std::endl;
    for (int i = 0; i < num_players; ++i) {
        int jersey = jersey_numbers.at(i);
        int rating = rating_values.at(jersey);
        if (rating > rating_above) {
            std::cout << "Player " << i + 1<< "'s jersey: "
                << (jersey < 10 ? "0": "")
                << jersey << "  rating: " << rating << std::endl;
        }
    }
}

/* Prints out the roster */
void PlayerList::PrintRoster() {
    std::cout << std::endl << "   === ROSTER === " << std::endl;
    for (int i = 0; i < num_players; ++i) {
        int jersey = jersey_numbers.at(i);
        int rating = rating_values.at(jersey);
        std::cout << " Player " << i + 1<< "'s jersey: "
            << (jersey < 10 ? "0": "")
            << jersey << "  rating: " << rating << std::endl;
    }
}

/* Recursively adds jerseys in ascending order */
void PlayerList::InsertSortedJersey(int min_index, int max_index, int jersey) {
    int mid_index = (min_index + max_index) / 2;
    if (num_players == 0 || (num_players > 0 && jersey > jersey_numbers.at(num_players - 1))) {
        jersey_numbers.push_back(jersey);   
    } else if (min_index == max_index) {
        jersey_numbers.insert(jersey_numbers.begin() + min_index, jersey);
    } else if (jersey < jersey_numbers.at(mid_index)) {
        InsertSortedJersey(min_index, mid_index, jersey);
    } else {
        InsertSortedJersey(mid_index + 1, max_index, jersey);
    }
}

/* Prompts the user for a jersey and rating then adds the player
   to the list if the jersey number doesn't already exist */
void PlayerList::AddPlayer() {
    if (num_players < 100) {
        int jersey = GetValidNumber(0,99,'j');
        int rating = GetValidNumber(1,9,'r');
        if (rating_values.at(jersey) < 1 || rating_values.at(jersey) > 9) {
            InsertSortedJersey(0 , num_players - 1, jersey);
            rating_values.at(jersey) = rating;
            ++num_players;
        } else {
            std::cout << "Jersey " << jersey
                << " already exists. Player not added." << std::endl;
            std::cout << "Try another jersey (y/n)? ";
            char in;
            std::cin >> in;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (in == 'y') {
                AddPlayer();
            }
        }
    } else {
        std::cout << std::endl << "       --- WARNING---";
        std::cout << "The team is full, please remove a player if you" 
            << " wish to add another." << std::endl;
    }
}

/* Prompts the user for the number of players to add,
   then adds that number of players */
void PlayerList::AddMultiPlayer() {
    int num_players_add = GetValidNumber(0,20,'n');
    for (int i = 0; i < num_players_add; ++i) {
        if (num_players < 100) {
            AddPlayer();
        } else {
            std::cout << std::endl << "       --- WARNING---" << std::endl;
            std::cout << "The team is full, please remove a player if you" 
                << " wish to add another." << std::endl;
            break;
        } 
    }
}

/* Prompts the user for a jersey number then removes that
   jersey number from the list if it exists */
void PlayerList::RemovePlayer() {
    int jersey = GetValidNumber(0,99, 'j');
    int index = GetMemberJersey(jersey);
    if (index < 0) {
        std::cout << "Jersey " << jersey
            << " is invalid. No player removed." << std::endl;
    } else {
        jersey_numbers.erase(jersey_numbers.begin() + index);
        rating_values.at(jersey) = 0;
        --num_players;
    }
}

/* Prompts the user for a jersey number to update, then
   prompts the user for a new rating */
void PlayerList::UpdatePlayer() {
    if (jersey_numbers.size() > 0) {
        int jersey = GetValidNumber(0, 99, 'j');
        while (rating_values.at(jersey) < 1) {
            std::cout << "Invalid jersey number" << std::endl;
            PrintRoster();
            jersey = GetValidNumber(0,99,'j');
        }
        int rating = GetValidNumber(1, 9, 'r');
        rating_values.at(jersey) = rating;
        std::cout << "Player "<< jersey << "'s rating was updated to: "
            << rating  << std::endl;;
    } else {
        std::cout << "There are no players." << std::endl;
    }
}

/* Adds a number of players, prints roster, then prints main menu
   and processes user choice */
void PlayerList::RunMenu() {
    AddMultiPlayer();
    PrintRoster();
    char choice;
    do {
        PrintMenu();
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(choice) {
            case 'A':
            case 'a':
                AddPlayer();
                break;
            case 'D':
            case 'd':
                RemovePlayer();
                break;
            case 'U':
            case 'u':
                UpdatePlayer();
                break;
            case 'R':
            case 'r':
                PrintAboveRating();
                break;
            case 'O':
            case 'o':
                PrintRoster();
                break;
            case 'M':
            case 'm':
                AddMultiPlayer();
                break;
            case 'Q':
            case 'q':
                std::cout << "Thank you, Have a nice day!" << std::endl;
                break;
            default:
                std::cout << "Enter a valid choice, please." << std::endl;
                break;
        }
    } while(choice != 'q' && choice != 'Q' && !std::cin.fail());
}