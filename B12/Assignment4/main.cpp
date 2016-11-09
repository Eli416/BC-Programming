#include "Playlist.h"
#include <iostream>
struct LinkedPlaylist {
    PlaylistNode* head; 
    PlaylistNode* tail; 
    string title;
};

void PrintMenu(string title) {
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
}

void AddSong(LinkedPlaylist* list) {
    string id, name, artist;
    int length;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID: ";
    getline(cin,id, '\n');
    cout << "Enter song's name: ";
    getline(cin,name, '\n');
    cout << "Enter artist's name: ";
    getline(cin,artist, '\n');
    cout << "Enter song's length (in seconds):";
    cin >> length;
    
    PlaylistNode added(id,name,artist,length);
    
    if (list->head == 0) {
        list->head = &added;
        list->tail = &added;
    }
    else {
        list->tail->InsertAfter(&added);
    }
}

void RemoveSong(LinkedPlaylist* list) {
    
}

void ChangePosition(LinkedPlaylist* list) {
    
}

void OutputBy(LinkedPlaylist* list) {
    
}

void OutputTotalTime(LinkedPlaylist* list) {
    
}

void OutputPlaylist(LinkedPlaylist* list) {
    PlaylistNode* curr = list->head;
    int counter = 1;
    while (curr) {
        cout << counter << "." << endl;
        curr->PrintPlaylistNode();
        curr = curr->GetNext();
        ++counter;
    }
}

int main() {
    LinkedPlaylist my_playlist;
    my_playlist.head = 0;
    my_playlist.tail = 0;
    cout << "Enter playlist's title: ";
    cin >> my_playlist.title;
    char selection = 0;
    char previous = 0;
    // TODO(sean): Make switch statemtent and input a function to clean up
    //             previous shenanigans.
    do {
        PrintMenu(my_playlist.title);
        if (previous) {
            cout << previous 
                << " Is an Invalid Option, Please choose another." << endl;
        }
        cin >> selection;
        switch (selection) {
            case 'A':
            case 'a': AddSong(&my_playlist); previous = 0; break;
            case 'D':
            case 'd': RemoveSong(&my_playlist); previous = 0; break;
            case 'C':
            case 'c': ChangePosition(&my_playlist); previous = 0; break;
            case 'S':
            case 's': OutputBy(&my_playlist); previous = 0; break;
            case 'T':
            case 't': OutputTotalTime(&my_playlist); previous = 0; break;
            case 'O':
            case 'o': OutputPlaylist(&my_playlist); previous = 0; break;
            case 'Q':
            case 'q': cout << "Thanks for using B12 Player!" << endl; break;
            default: 
                previous = selection;
                break; 
        
        }
    } while (selection != 'q' && selection != 'Q');
    
    return 0;
}