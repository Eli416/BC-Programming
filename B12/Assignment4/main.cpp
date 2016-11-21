/**
 *    Name: Sean Halpin
 *    Class: COMP B12 8AM MW
 *    Created On: 2016/11/11
 *    Instructor: RIchard Miles
 *    Assignment: Linked Playlist #(4 + 5)
 */

#include "Playlist.h"
#include <iostream>
#include <limits>

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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    PlaylistNode* added = new PlaylistNode(id, name, artist, length);
    
    if (list->head) {
        list->tail->InsertAfter(added);
    } else {
        list->head = added;
    }
    list->tail = added;
}

void RemoveSong(LinkedPlaylist* list) {
    cout << "REMOVE SONG" << endl 
        << "Enter song's unique ID: ";
    string remove;
    getline(cin, remove, '\n');
    PlaylistNode* curr = list->head;
    PlaylistNode* prev = 0;
    char found = 0;
    while (curr && !found) {
        if (curr->GetID().compare(remove) == 0) {
            found = !found;
            if (prev) {
                if (list->tail == curr) {
                    list->tail = prev;
                }
                prev->SetNext(curr->GetNext());
            } else {
                list->head = curr->GetNext();
            }
            cout << curr->GetSongName() << " remomved" << endl;
            delete curr;
        } else {
            prev = curr;
            curr = curr->GetNext();
        }
    }
    if (!found) {
        cout << "Song not found and removed." << endl;
    }
}

void ChangePosition(LinkedPlaylist* list) {
    cout << "CHANGE POSITION OF SONG" << endl 
        << "Enter song's current position: ";
    int cur_pos, new_pos;
    cin >> cur_pos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter song's new position: ";
    cin >> new_pos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int i = 1;
    PlaylistNode* curr = list->head;
    PlaylistNode* prev = 0;
    while (i < cur_pos && curr) {
        i++;
        prev = curr;
        curr = curr->GetNext();
    }
    
    PlaylistNode* trav = 0;
    if (curr) {
        if(new_pos == 1 && curr == list->tail) {
            curr->SetNext(list->head);
            list->tail = prev;
            prev->SetNext(0);
            list->head = curr;
        } else if (new_pos == 1) {
            prev->SetNext(curr->GetNext());
            curr->SetNext(list->head);
            list->head = curr;
        } else {
            trav = list->head;
            i = 1;
            if(new_pos < cur_pos) {
                new_pos--;
            }
            while (i < new_pos && trav) {
                i++;
                trav = trav->GetNext();
            } 
            if (trav == list->tail && curr == list->head) {
                list->head = curr->GetNext();
                list->tail = curr;
                trav->InsertAfter(curr);
            } else if (trav == list->tail) {
                list->tail = curr;
                prev->SetNext(curr->GetNext());
                trav->InsertAfter(curr);
            } else if (curr == list->tail) {
                list->tail = prev;
                prev->SetNext(curr->GetNext());
                trav->InsertAfter(curr);
            } else if (curr == list->head) {
                list->head = curr->GetNext();
                trav->InsertAfter(curr);
            } else {
                prev->SetNext(curr->GetNext());
                trav->InsertAfter(curr);
            }
        }
        cout <<'"' << curr->GetSongName() << "\" was moved to position " << new_pos << endl; 
    } else {
        cout << cur_pos << " is an invalid position. No songs moved." << endl;
    }
    
}

void OutputBy(LinkedPlaylist* list) {
    cout << endl << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl 
        << "Enter artist's name: ";
    string artist;
    getline(cin, artist, '\n');
    PlaylistNode* curr = list->head;
    int i = 1;
    while (curr) {
        if (curr->GetArtistName().compare(artist) == 0) {
            cout << i << "." << endl;
            curr->PrintPlaylistNode();
        }
        i++;
        curr = curr->GetNext();
    }
    cout << endl;
}

void OutputTotalTime(LinkedPlaylist* list) {
    cout << endl << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl 
        << "Total time: ";
    int time = 0;
    PlaylistNode* curr = list->head;
    while (curr) {
        time += curr->GetSongLength();
        curr = curr->GetNext();
    }
    cout << time << endl;
    
}
void FillList(LinkedPlaylist* list) {
    int num_vals = 12;
    string ids[] = {"ABC","DEF","GHI","JKL","MNO","PQR","STU","VWX", 
                    "YZ0", "123", "456", "789"};
    string names[] = {"It's the End of the World","Sandblast","Hero",
                      "Ocean Man","Escape","The Sounds of Silence",
                      "House of the Rising Sun","Carry On Wayward Sun",
                      "Bohemian Rhapsody","Another Brick in the Wall",
                      "RaggaBomb with Ragg Twins","BabaYetu"};
    string artists[] = {"R.E.M.","Fox Stevenson","Pegboard Nerds",
                        "Ween","Craig Armstrong","Simon & Garfunkel",
                        "The Animals","Kansas","Queen","Pink Floyd",
                        "Skrillex","Christopher Tin"};
    int lengths[] = {243,327,330,128,186,187,249,324,367,361,268,215};
    PlaylistNode* curr = 0;
    for (int i = 0; i < num_vals; ++i) {
        curr = new PlaylistNode(ids[i], names[i], artists[i], lengths[i]);
        if (list->head) {
            list->tail->InsertAfter(curr);
            list->tail = curr;
        } else {
            list->head = curr;
            list->tail = curr;
        }
    }
}

void OutputPlaylist(LinkedPlaylist* list) {
    cout << endl << list->title << " - OUTPUT FULL PLAYLIST" << endl;
    if (list->head == 0) {
        cout << "The playlist is empty." << endl;
    } else {
        PlaylistNode* curr = list->head;
        int counter = 1;
        while (curr) {
            cout << counter << "." << endl;
            curr->PrintPlaylistNode();
            ++counter;
            curr = curr->GetNext();
            cout << endl;
        }
    }
}

void RunMenu(LinkedPlaylist* list) {
    char selection = 0;
    char previous = 0;
    do {
        PrintMenu(list->title);
        if (previous) {
            cout << previous 
                << " Is an Invalid Option, Please choose another." << endl;
        }
        cin >> selection;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (tolower(selection)) {
            case 'a': AddSong(list); previous = 0; break;
            case 'd': RemoveSong(list); previous = 0; break;
            case 'c': ChangePosition(list); previous = 0; break;
            case 's': OutputBy(list); previous = 0; break;
            case 't': OutputTotalTime(list); previous = 0; break;
            case 'o': OutputPlaylist(list); previous = 0; break;
            case 'q': cout << "Thanks for using B12 Player!" << endl; break;
            default: 
                previous = selection;
                break; 
        
        }
    } while (selection != 'q' && selection != 'Q');
    
}

void SetUpList(LinkedPlaylist* list) {
    list->head = 0;
    list->tail = 0;
    cout << "Enter playlist's title: ";
    getline(cin, list->title);
    FillList(list);
}

int main() {
    LinkedPlaylist my_playlist;
    SetUpList(&my_playlist);
    RunMenu(&my_playlist);
    return 0;
}
