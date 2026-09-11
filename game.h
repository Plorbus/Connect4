#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "player.h"
#include "human.h"
#include "computer.h"
#include "menu.h"
#include "leaderboard.h"
#include "playerrecord.h"
#include "grid.h"
using namespace std;
class Game{
    private:
    Player* player1;//Human
    Player* player2;//Computer
    Grid board;
    Menu menu;
    Leaderboard leaderboard;
    bool isPlayer1Turn;
    bool gameOver;

    public:
    Game();
    
    bool setUpGame();
    void play();
    
    void switchTurn();
    void run();
    
    ~Game();
    




};




#endif