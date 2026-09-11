// grid.h
#ifndef GRID_H
#define GRID_H
#include <iostream>
using namespace std;

class Grid {
private:
    char gridArray[7][6];
    int rowSize = 6;
    int columnSize = 7;
    //the columnsize and rowSize are simply there for ease of reading code in the cpp file. 
    //While the memory is static I decided to include these for simpliciy for the code. 
    // int humanFilled;
    // int computerFilled;
    // We can take these out as the checkWinCondtion will only check for the shape that was used. 
    // Rather than maintaing a bunch of useless memory of who placed what at certain cordinates. Checking for shapes saves from needlessly complex logic

public:
    Grid();
    // Grid(char[][], int, int);
    Grid(const Grid&);

    bool isFull();
    void reset();

    int addToGrid(int, char);   // returns false if col full/invalid
    int checkWinCondition(int, int) const;
    bool isLegalMove(int) const;

    
    Grid& operator=(const Grid&);
    friend ostream& operator<<(ostream&, const Grid&);

};
#endif