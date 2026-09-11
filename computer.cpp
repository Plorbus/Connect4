#include "computer.h"
#include "grid.h"
#include <cstdlib>//these two libraries were looked up to be found for random number generation.
#include <ctime>//

Computer::Computer():Player(){

}
Computer::Computer(string n, char s):Player(n,s){
    
}
Computer::Computer(int w, int l, int t, string n, char s,int cs, int bs):Player(w,l,t,n,s,cs,bs){
    
}
Computer::Computer(const Computer& rhs):Player(rhs){

}

int Computer::makeAMove(const Grid& g){
    static bool seeded = false;//this method of random generation was looked up, I learned that I have to put static or else this will keep reseeding and place inputs in the same position twice.
    if(seeded == false) {
        srand(time(0));
        seeded = true;
    }
    int col;
    
    while (true){
    col = rand() % 7;
    if (g.isLegalMove(col)){
        return col;
        }
    }
}
void Computer::setShape(){
    shape = 'O';
}
