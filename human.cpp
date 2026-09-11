#include "human.h"




Human::Human():Player(){

}
Human::Human(string n, char s):Player(n,s){
    
}
Human::Human(int w, int l, int t, string n, char s, int cs,int bs):Player(w,l,t,n,s,cs,bs){
    
}
Human::Human(const Human& rhs):Player(rhs){
}



int Human::makeAMove(const Grid& g) {
    while (true) {
        int col = Menu::getInput<int>(name + ", enter column (1-7) or 0 to quit: ");
        if (col == 9){
            return 9; 
        }
        col -= 1;
        if (col < 0 || col > 6) {
            cout << "Column must be between 1 and 7." << endl;
            continue;
        }
        if (!g.isLegalMove(col)) {
            cout << "That column is full. Pick another." << endl;
            continue;
        }
        return col;
    }
}

void Human::setShape() {
    shape = Menu::askForShape();
}