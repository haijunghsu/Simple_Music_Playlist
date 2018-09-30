#include "Song.h"
#include <vector>
#include <iostream>

using namespace std;

Song::Song() {
    songName = "none";
    songLine = "none";
    numPlay = 0;
}

Song::Song(string inputName, string inputLine, int countPlay) {
    songName = inputName;
    songLine = inputLine;
    numPlay = countPlay;
}

string Song::GetSongName() const {
    return songName;
}

string Song::GetFirstLine() const {
    return songLine;
}

void Song::CountPlay() {
    ++numPlay;
}

void Song::PrintSong() {
    cout << songName << ": " << "\"" << songLine << "\"" << ", " << numPlay << " play(s)." << endl;
}
