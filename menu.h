#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;
#include "playerrecord.h"
class Menu{
    public:
    static int displayMenu();
    static int startDecider();
    static string askForName();
    static char askForShape(); //taken is used to stop the computer from picking the same char as the player. 
    template <typename T>
    static T getInput(const string& prompt);
};
template <typename T>
T Menu::getInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input try again." << endl;
        } else {
            cin.ignore(1000, '\n');
            return value;  
        }
    }
}
//I was having trouble in testing setting this up as it would get stuck in a constant loop with an invalid input
//After looking online I was given this solution that way when an invalid input is put the template automatically handles
#endif