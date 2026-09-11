#include "game.h"
//game compiles all classes into one big file where all of the class functions are called and used to run connect 4. 

Game::Game(){
    player1 = nullptr;
    player2 = nullptr;
    isPlayer1Turn = true;
    gameOver = false;
    leaderboard.loadFromFile("leaderboard.csv");
}
bool Game::setUpGame(){
    string name = menu.askForName();
    if (name == ""){
        return false;
    }
    char humanShape = menu.askForShape();
    if (humanShape == '\0'){
        return false;
    }
    char computerShape;
    if (toupper(humanShape) != 'O'){
        computerShape = 'O';
    } else{
        computerShape = 'X';
    }

    //had to implment these because the pointers would get stuck and not update properly
    delete player1;
    delete player2;

    //leaderboard will only work if names are exactly the same. shapes can be different as we omitted that data.
    PlayerRecord* existing = leaderboard.findRecord(name);
    if (existing != nullptr){
        player1 = new Human(existing->wins, existing->losses, existing->ties, name, humanShape, existing->currentstreak, existing->bestStreak);
    } else{
        player1 = new Human(name, humanShape);
    }
    //PlayerRecord has public variables allowing us to grab data directly via -> calls
    PlayerRecord* existingComp = leaderboard.findRecord("Computer");
    if (existingComp != nullptr){
    player2 = new Computer(existingComp->wins, existingComp->losses, existingComp->ties,"Computer", computerShape, existingComp->currentstreak, existingComp->bestStreak);
    } else{
    player2 = new Computer("Computer", computerShape);
    }

    board.reset();
    isPlayer1Turn = true;
    gameOver = false;
    return true;
}
void Game::play() {
    int firstChoice = menu.startDecider();
    if (firstChoice == 9){
        return;
    }
    if (firstChoice == 1){
    isPlayer1Turn = true;
    }else{
    isPlayer1Turn = false;
    }
    while (gameOver == false){
        //game will constantly flip between human and computer using current which handles the polymorphism of the makeAMove() 
        Player* current;
        if (isPlayer1Turn == true){
            current = player1;
        }else{
            current = player2;
        }        
        cout << board;
        
        //tie checker
        if (board.isFull() == true){
            gameOver = true;
            cout << "Its a tie!" << endl;
            player1->addTie();
            player2->addTie();
            leaderboard.updateRecord(player1->getName(),player1->getWins(),player1->getLoss(),player1->getTies(),player1->getBestStreak(),player2->getCurrentStreak());
            leaderboard.updateRecord(player2->getName(),player2->getWins(),player2->getLoss(),player2->getTies(),player2->getBestStreak(),player2->getCurrentStreak());
            leaderboard.saveToFile("leaderboard.csv");
            break;
        }
        
        //exit checker
        int colChoice = current->makeAMove(board);
        if (colChoice == 9){
            cout << "Game abandoned." << endl;
            gameOver = true;
            break;
        }

        int placedRow = board.addToGrid(colChoice, current->getShape());

        //win checker
        if (board.checkWinCondition(colChoice, placedRow) == 1){
            gameOver = true;
            cout << board;  // show final board
            current->addWin();
            leaderboard.updateRecord(current->getName(),current->getWins(),current->getLoss(),current->getTies(),current->getBestStreak(),current->getCurrentStreak());
            Player* loser = nullptr;//check who the loser is then reset their streak by adding a loss.
            if(isPlayer1Turn == true){
                loser = player2;
            }else{
                loser = player1;
            }
            loser->addLoss();
            leaderboard.updateRecord(loser->getName(),loser->getWins(),loser->getLoss(),loser->getTies(),loser->getBestStreak(),loser->getCurrentStreak());
            cout << current->getName() << " wins!" << endl;
            leaderboard.saveToFile("leaderboard.csv");
            break;
        }
        switchTurn();
    }
}

void Game::switchTurn() {
    if (isPlayer1Turn == true) {
        isPlayer1Turn = false;
    } else {
        isPlayer1Turn = true;
    }
}

Game::~Game(){
    delete player1;
    delete player2;
    
}
void Game::run(){
    while (true){
        int choice = Menu::displayMenu();
        if (choice == 1){
            bool setupWorked = setUpGame(); //this check is nightmare because its 2 checks nested wihtin setUpGame where if 9 is inputted it returns impossible values to then fufill if statements to return false and bring back the user to the main menu
            if(setupWorked == true){
                play();
            }
        }
        else if(choice == 2){
            leaderboard.showLeaderboard();
        }
        else if(choice == 9){
            break;
        }
        else{
            cout << "Invalid choice." << endl;
        }
    }
}