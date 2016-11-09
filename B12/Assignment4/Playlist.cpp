#include "Playlist.h"
#include <iostream>

using namespace std;
PlaylistNode::PlaylistNode() {
    uniqueID = "Default";
    songName = "Default";
    artistName = "Default";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string initID, string initSongName,
                             string initArtistName, int initSongLength, 
                             PlaylistNode* nextLoc) {
    uniqueID = initID;
    songName = initSongName;
    artistName = initArtistName;
    songLength = initSongLength;
    nextNodePtr = nextLoc;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* temp = nextNodePtr;
    nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = temp;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

string PlaylistNode::GetID() const{
    return uniqueID;
}

string PlaylistNode::GetSongName() const{
    return songName;
}

string PlaylistNode::GetArtistName() const{
    return artistName;
}

int PlaylistNode::GetSongLength() const{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}
/*   
private:
   string uniqueID;
   string songName;
   string artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
*/