#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include "grid.h"
class Computer:public Player{
    public:
    Computer();
    Computer(string, char);
    Computer(int, int, int, string, char, int, int);
    Computer(const Computer&);

    int makeAMove(const Grid&);
    void setShape();


};

#endif
