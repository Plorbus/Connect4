#include "player.h"

Player::Player(){
    wins = 0;
    losses = 0;
    ties = 0;
    name = "N/A";
    shape = ' ';
    currentStreak = 0;
    bestStreak = 0;
}
Player::Player(int w, int l, int t, string n, char s,int cs,int bs){
    wins = w;
    losses = l;
    ties = t;
    name = n;
    shape = s;
    currentStreak = cs;
    bestStreak = bs;

}
Player::Player(const Player& rhs){
    wins = rhs.wins;
    losses = rhs.losses;
    ties = rhs.ties;
    name = rhs.name;
    shape = rhs.shape;
    currentStreak = rhs.currentStreak;
    bestStreak = rhs.bestStreak;
}

Player::Player(string n, char s){
    wins = 0;
    losses = 0;
    ties = 0;
    currentStreak = 0;
    bestStreak = 0;
    name = n;
    shape = s;
}
Player::~Player(){

}

void Player::addWin(){
    wins++;
    currentStreak++;
    if (currentStreak > bestStreak){
        bestStreak = currentStreak;
    }
}
void Player::addLoss(){
    losses++;
    currentStreak = 0;
}
void Player::addTie(){
    ties++;
}

void Player::setName(string na){
    name = na;
}

int Player::getWins(){ 
    return wins;
}
int Player::getLoss(){ 
    return losses;
}
int Player::getTies() { 
return ties;
}
string Player::getName(){
    return name;
}
char Player::getShape(){
    return shape;
}
int Player::getBestStreak(){
    return bestStreak;
}
int Player::getCurrentStreak(){
    return currentStreak;
}