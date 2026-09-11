#include "grid.h"

Grid::Grid(){
    for (int i = 0; i < columnSize; i++){

        for (int r = 0; r < rowSize; r++){
        gridArray[i][r] = ' ';
        }

    }
}

Grid::Grid(const Grid& rhs){

    for (int i = 0; i < columnSize; i++){

        for (int r = 0; r < rowSize; r++){
            gridArray[i][r] = rhs.gridArray[i][r];
        }
    }
}



int Grid::addToGrid(int col, char shape){
    if (col < 0 || col >= columnSize) {
        cout << "Column is out of range, please try another slot." << endl;
        return -1;
    }
    if (!isLegalMove(col)) {
        cout << "Column is full, please try another slot." << endl;
        return -1;
    }
    int i = 0;
    while (gridArray[col][i] != ' '){
        i++;
    }
    gridArray[col][i] = shape;
    return i;
}

int Grid::checkWinCondition(int col, int row) const {
    char target = gridArray[col][row];
    if (target == ' ') {
        return 0;
    }  
    //instead of having to write checks for all directions claude came up with the idea of making
    //an array of directions encoded in a for loop that sorts through all directions and will only add if all and signs are true 
    int dirs[4][2] = {
        {1, 0},   // horizontal (col changes, row stays)
        {0, 1},   // vertical   ( rowchanges, col stays)
        {1, 1},   // diagonal up-right
        {1, -1}   // diagonal down-right
    };

    for (int d = 0; d < 4; d++){
        int dCol = dirs[d][0];
        int dRow = dirs[d][1];

        // Walk forward from (col, row)
        int forward = 0;
        int c = col + dCol;
        int r = row + dRow;
        while (c >= 0 && c < columnSize && r >= 0 && r < rowSize && gridArray[c][r] == target){
            forward++; //holds the logic for how many matching pieces were found (compares at the end)
            c += dCol;
            r += dRow;
        }

        int backward = 0;
        c = col - dCol;
        r = row - dRow;
        while (c >= 0 && c < columnSize && r >= 0 && r < rowSize && gridArray[c][r] == target){
            backward++;
            c -= dCol;
            r -= dRow;
        }
        if (forward + backward + 1 >= 4) {
            return 1;
        }
    }
    return 0;
}

bool Grid::isFull(){
    int counter = 0;
    for(int i = 0; i < columnSize;i++){
         if (gridArray[i][rowSize - 1] != ' '){
            counter++;
         }
         if (counter == 7){
            return true;
        }
    }
    return false;
}
void Grid::reset(){
    for (int i = 0; i < columnSize; i++){

        for (int r = 0; r < rowSize; r++){
        gridArray[i][r] = ' ';
        }
    }
}
bool Grid::isLegalMove(int move)const{
        if (0 > move || move >= columnSize){
            return false;
        }
        for (int r = 0; r < rowSize; r++){
        if (gridArray[move][r] == ' '){
            return true;
        }
    }
    return false;
}

Grid& Grid::operator=(const Grid& rhs){

    if (this == &rhs){
        return *this;
    } 
    for (int i = 0; i < columnSize; i++){
        for (int r = 0; r < rowSize; r++){
            gridArray[i][r] = rhs.gridArray[i][r];
        }
    }
    return *this;
}

ostream& operator<<(ostream& o, const Grid& rhs){
     for (int r = rhs.rowSize - 1; r >= 0; r--){

        for (int i = 0; i < rhs.columnSize; i++){
            o << '|' << rhs.gridArray[i][r];
    }
    o << '|' << endl;
}
    o << " 1 2 3 4 5 6 7" << endl;
    o << "Input 9 to exit " << endl;
    return o;
}
