#ifndef Playlist_h
#define Playlist_h
#include <vector>
#include <string>
#include "Song.h"

using namespace std;

class Playlist {
public:
    Playlist();
    Playlist(string playlistName);
    string GetPlaylistName() const;
    void AddUserSong(Song* addSong);
    void PrintUserSongLine();
    void PrintUserSongName();
    void PlaySong();
    void DeleteSong(int songIndex);
    void DeleteSongLib(Song* selectedSong);
    
private:
    string playlistName;
    vector<Song*> userSongList;
};
#endif
