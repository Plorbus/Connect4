#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "menu.h"
#include "grid.h"
class Human:public Player {
public:
    Human();
    Human(string, char);
    Human(int, int, int, string, char,int,int);
    Human(const Human&);

    int makeAMove(const Grid&);
    void setShape();
};
#endif