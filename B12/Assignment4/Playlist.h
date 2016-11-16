/**
 *    Name: Sean Halpin
 *    Class: COMP B12 8AM MW
 *    Created On: 2016/11/11
 *    Instructor: RIchard Miles
 *    Assignment: Linked Playlist #(4 + 5)
 */
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
using namespace std;


class PlaylistNode {
  public:
    PlaylistNode();
    PlaylistNode(string initID, string initSongName, 
                 string initArtistName, int initSongLength, 
                 PlaylistNode* nextLoc = 0);
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
    
  private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif