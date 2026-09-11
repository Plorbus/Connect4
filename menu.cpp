#include "menu.h"
#include "human.h"


int Menu::displayMenu(){
    cout << "====== Starting Connect 4! ☆*: .｡. o(≧▽≦)o .｡.:*☆ ======" << endl;
    cout << "1. Play game" << endl;
    cout << "2. View leaderboard" << endl;
    cout << "9. Quit" << endl;
    return getInput<int>("Choose an option: ");
}


int Menu::startDecider(){
    cout << "Who would you like to go first?" << endl;
    int choice = getInput<int>("Enter 1 to go first, 0 to go second, 9 to quit: ");
    if (choice == 9){
        return 9;
    }
    return choice;
}

string Menu::askForName(){
    string name = getInput<string>("What is your name? (or 9 to quit): ");
    if (name == "9") {
        return "";
    }
    return name;
}

char Menu::askForShape(){
    while (true){
        string input = getInput<string>("Select shape (please input a single character, or 9 to quit): ");
        if (input == "9"){
            return '\0';
        }
        if (input.length() != 1){
            cout << "Must be a single character." << endl;
            continue;
        }
        if (input[0] == ' '){
            cout << "Shape cannot be a space." << endl;
            continue;
        }
        return input[0];
    }
}
// char Menu::askForShape(){
//     return getInput<char>("Please select your shape for Connect 4! (must be a single character example 'x')\nInput 9 to exit ");
// }

