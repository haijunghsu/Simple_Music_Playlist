#ifndef Song_h
#define Song_h
#include <vector>
#include <string>

using namespace std;

class Song {
public:
    Song();
    Song(string inputName, string inputLine, int countPlay);
    string GetSongName() const;
    string GetFirstLine() const;
    void PrintSong();
    void CountPlay();
    
private:
    string songName;
    string songLine;
    int numPlay;
};
#endif
