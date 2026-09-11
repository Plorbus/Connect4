#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "grid.h"
using namespace std;
class Player{
    protected:
    int wins;
    int losses;
    int ties;
    string name;
    char shape;
    int currentStreak;
    int bestStreak;
    
    public:
    Player();
    Player(string, char);
    Player(int, int, int,string,char,int,int);
    Player(const Player&);

    int getWins();
    int getLoss();
    int getTies();
    string getName();
    char getShape();
    int getCurrentStreak();
    int getBestStreak();

    void addWin();
    void addLoss();
    void addTie();
    void setName(string);

    virtual void setShape() = 0;

    
    virtual int makeAMove(const Grid&) = 0;


    virtual ~Player();



};

#endif