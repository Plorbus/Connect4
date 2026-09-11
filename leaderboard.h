#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
#include "playerrecord.h"
class Leaderboard{
    private: 
    PlayerRecord* records; // dynamic array for printing the score
    int maxSize;
    int currentSize;
    void resize();
    public:
    Leaderboard();
    Leaderboard(PlayerRecord*, int, int);
    Leaderboard(const Leaderboard&);

    void loadFromFile(const string&);
    void saveToFile(const string&)const;
    void updateRecord(const string&, int, int, int, int,int);
    PlayerRecord* findRecord(const string&);
    void showLeaderboard();

    Leaderboard& operator=(const Leaderboard&); 
    ~Leaderboard();
 

};

#endif