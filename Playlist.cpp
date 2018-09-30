#include "Playlist.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Playlist::Playlist() {
    playlistName = "none";
}

Playlist::Playlist(string inputName) {
    playlistName = inputName;
}

string Playlist::GetPlaylistName() const {
    return playlistName;
}

void Playlist::AddUserSong(Song* selectedSong) {
    userSongList.push_back(selectedSong);
}

void Playlist::PrintUserSongLine() {
    for (int i = 0; i < userSongList.size(); ++i) {
        cout << userSongList.at(i)->GetFirstLine();
        cout << endl;
    }
}

void Playlist::PrintUserSongName() {
    for (int i = 0; i < userSongList.size(); ++i) {
        cout << i << ": ";
        cout << userSongList.at(i)->GetSongName();
        cout << endl;
    }
}

void Playlist::PlaySong() {
    for (int i = 0; i < userSongList.size(); ++i) {
        userSongList.at(i)->CountPlay();
    }
}

void Playlist::DeleteSong(int songIndex) {
    userSongList.erase(userSongList.begin() + songIndex);
}

void Playlist::DeleteSongLib(Song* selectedSong) {
    for (int i = 0; i < userSongList.size(); ++i) {
        if (userSongList.at(i) == selectedSong) {
            userSongList.erase(userSongList.begin() + i);
        }
    }
}
