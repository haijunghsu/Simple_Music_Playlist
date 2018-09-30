#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Song.h"
#include "Playlist.h"

using namespace std;

void PrintMenu() {
    cout << "add      Adds a list of songs to the library" << endl;
    cout << "list     Lists all the songs in the library" << endl;
    cout << "addp     Adds a new playlist" << endl;
    cout << "addsp    Adds a song to a playlist" << endl;
    cout << "listp    Lists all the playlists" << endl;
    cout << "play     Plays a playlist" << endl;
    cout << "delp     Deletes a playlist" << endl;
    cout << "delsp    Deletes a song from a playlist" << endl;
    cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
    cout << "options  Prints this options menu" << endl;
    cout << "quit     Quits the program" << endl << endl;
}

void GetLineNotWS(string& inpString) {
    getline(cin, inpString);
    if (inpString.find_first_not_of(" \t") == std::string::npos) {
        getline(cin, inpString);
    }
}

void AddSong(vector<Song*>& songList, Song* newSong) {
    string songName;
    string songLine;
    const int INITIAL_NUM_PLAY = 0;

    cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
    cout << "Song Name:" << endl;
    GetLineNotWS(songName);
    while (songName != "STOP") {
        
        cout << "Song's first line:" << endl;
        GetLineNotWS(songLine);
        
        newSong = new Song(songName, songLine, INITIAL_NUM_PLAY); //returning an address.
        songList.push_back(newSong);
        
        cout << "Song Name:" << endl;
        GetLineNotWS(songName);
    }
    cout << endl;
}

void PrintSongList(const vector<Song*>& songList) {
    for (int i = 0; i < songList.size(); ++i) {
        songList.at(i)->PrintSong();
    }
}

void ListSong(const vector<Song*>& songList) {
    for (int i = 0; i < songList.size(); ++i) {
        cout << i << ": ";
        cout << songList.at(i)->GetSongName();
        cout << endl;
    }
}

void AddPlaylist(vector<Playlist*>& playlist, Playlist* newPlayList) {
    string PlaylistName;
    
    cout << "Playlist name: " << endl << endl;
    GetLineNotWS(PlaylistName);
    newPlayList = new Playlist(PlaylistName);
    playlist.push_back(newPlayList);
}

void ListPlaylist(const vector<Playlist*>& playlist) {
    for (int i = 0; i < playlist.size(); ++i) {
        cout << i << ": ";
        cout << playlist.at(i)->GetPlaylistName();
        cout << endl;
    }
}

void AddSongPlaylist(vector<Playlist*>& playlist, vector<Song*>& songList, Song* newSong) {
    int songPicked = 0;
    int listPicked = 0;
    
    ListPlaylist(playlist);
    cout << "Pick a playlist index number: " << endl;
    cin >> listPicked;
    
    ListSong(songList);
    cout << "Pick a song index number: " << endl << endl;
    cin >> songPicked;
    newSong = songList.at(songPicked);
    
    playlist.at(listPicked)->AddUserSong(newSong);
}

void PlayPlaylist(const vector<Playlist*>& playlist) {
    int listPicked = 0;
    
    ListPlaylist(playlist);
    cout << "Pick a playlist index number: " << endl;
    cin >> listPicked;
    cout << endl;
    
    cout << "Playing first lines of playlist: ";
    cout << playlist.at(listPicked)->GetPlaylistName();
    playlist.at(listPicked)->PlaySong();
    cout << endl;
    
    playlist.at(listPicked)->PrintUserSongLine();
    cout << endl;
}

void DeletePlaylist(vector<Playlist*>& playlist) {
    int listPicked = 0;
    Playlist* tempPtr = nullptr;
    
    ListPlaylist(playlist);
    cout << "Pick a playlist index number to delete: " << endl << endl;
    cin >> listPicked;
    
    tempPtr = playlist.at(listPicked);
    delete tempPtr; //freeing memory from the selected playlist.
    playlist.erase(playlist.begin() + listPicked);
}

void DeleteSongPlaylist(vector<Playlist*>& playlist) {
    int listPicked = 0;
    int songPicked = 0;
    
    ListPlaylist(playlist);
    cout << "Pick a playlist index number: " << endl;
    cin >> listPicked;
    
    playlist.at(listPicked)->PrintUserSongName();
    cout << "Pick a song index number to delete: " << endl << endl;
    cin >> songPicked;
    playlist.at(listPicked)->DeleteSong(songPicked);
}

void DeleteSongFromLib(vector<Playlist*>& playlist, vector<Song*>& songList) {
    int songPicked = 0;
    Song* tempPtr = nullptr;

    ListSong(songList);
    cout << "Pick a song index number:" << endl << endl;
    cin >> songPicked;
    tempPtr = songList.at(songPicked);
    delete tempPtr; //freeing memory from the selected song
    
    songList.erase(songList.begin() + songPicked);
    for (int i = 0; i < playlist.size(); ++i) {
        playlist.at(i)->DeleteSongLib(tempPtr);
    }
}

int main() {
    Song* newSong = nullptr;
    Playlist* newPlayList = nullptr;
    vector<Song*> songList;
    vector<Playlist*> playlist;
    string userOption;
    const int REPEAT = 1;

    cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;
    while (REPEAT) {
        cout << "Enter your selection now:" << endl;
        cin >> userOption;

        if (userOption == "add") {
            AddSong(songList, newSong);
        }
        else if (userOption == "list") {
            PrintSongList(songList);
        }
        else if (userOption == "addp") {
            AddPlaylist(playlist, newPlayList);
        }
        else if (userOption == "listp") {
            ListPlaylist(playlist);
        }
        else if (userOption == "addsp") {
            AddSongPlaylist(playlist, songList, newSong);
        }
        else if (userOption == "play") {
            PlayPlaylist(playlist);
        }
        else if (userOption == "delp") {
            DeletePlaylist(playlist);
        }
        else if (userOption == "delsp") {
            DeleteSongPlaylist(playlist);
        }
        else if (userOption == "delsl") {
            DeleteSongFromLib(playlist, songList);
        }
        else if (userOption == "options") {
            PrintMenu();
        }
        else if (userOption == "quit") {
            //freeing memory from the rest of the songs and the playlists.
            
            for (int i = 0; i < songList.size(); ++i) {
                delete songList.at(i);
            }
            
            for (int i = 0; i < playlist.size(); ++i) {
                delete playlist.at(i);
            }
            
            cout << "Goodbye!" << endl;
            return 0;
        }
        else {
            PrintMenu();
            continue;
        }
    }
}
