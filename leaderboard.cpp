#include "leaderboard.h"
#include <iomanip>

Leaderboard::Leaderboard(){
    maxSize = 42;
    currentSize = 0;
    records = new PlayerRecord[maxSize];

}
Leaderboard::Leaderboard(PlayerRecord* pR, int mS, int cS){
    maxSize = mS;
    currentSize = cS;
    records = new PlayerRecord[maxSize];
    for(int i = 0; i < currentSize; i++){
        records[i] = pR[i];
    }
}

Leaderboard::Leaderboard(const Leaderboard& rhs){
    maxSize = rhs.maxSize;
    currentSize = rhs.currentSize;
    records = new PlayerRecord[maxSize];
    for (int i = 0; i < currentSize; i++){
        records[i] = rhs.records[i];
    }
}

void Leaderboard::loadFromFile(const string& filename){
    ifstream fid(filename);
    if (!fid.is_open()){
        return;//fail check
    }
    string line;
    getline(fid,line);
    while (getline(fid,line)){
        stringstream ss(line);
        string comma_finder;
        
        PlayerRecord read;
        getline(ss, comma_finder, ',');  
        read.name = comma_finder;
        getline(ss, comma_finder, ',');
        read.wins = stoi(comma_finder);
        getline(ss, comma_finder, ',');
        read.losses = stoi(comma_finder);
        getline(ss, comma_finder, ',');
        read.ties = stoi(comma_finder); 
        getline(ss, comma_finder, ',');
        read.bestStreak = stoi(comma_finder);
        getline(ss, comma_finder, ',');
        read.currentstreak = stoi(comma_finder); 

        if (currentSize == maxSize) resize();
        records[currentSize] = read;
        currentSize++;
    }
    
}
    
void Leaderboard::saveToFile(const string& filename)const{
    ofstream fid(filename);
    fid << "Name,Wins,Losses,Ties,BestStreak,CurrentStreak" << endl;
    for(int i = 0; i < currentSize; i++){
        fid << records[i].name << "," << records[i].wins << ","
        << records[i].losses << "," << records[i].ties << "," <<records[i].bestStreak <<
        "," << records[i].currentstreak << endl;
    }
    fid.close();
}

void Leaderboard::updateRecord(const string& n, int w, int l, int t, int bStreak,int cStreak){
    PlayerRecord* r = findRecord(n);
    if (r == nullptr){
        if (currentSize == maxSize) {
            resize();
        }
        records[currentSize].name = n;
        r = &records[currentSize];
        currentSize++;
    }
    r->wins = w;
    r->losses = l;
    r->ties = t;
    r->bestStreak = bStreak;
    r->currentstreak = cStreak;
}

    
PlayerRecord* Leaderboard::findRecord(const string& name){
      for (int i = 0; i < currentSize; i++){
        if (records[i].name == name){
            return &records[i];
        }
    }
    return nullptr;
}

void Leaderboard::showLeaderboard(){
    cout << left
         << setw(15) << "Name"
         << setw(8)  << "Wins"
         << setw(8)  << "Losses"
         << setw(8)  << "Ties"
         << setw(14) << "BestStreak"
         << setw(14) << "CurrentStreak" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < currentSize; i++){
        cout << left
             << setw(15) << records[i].name
             << setw(8)  << records[i].wins
             << setw(8)  << records[i].losses
             << setw(8)  << records[i].ties
             << setw(14) << records[i].bestStreak
             << setw(14) << records[i].currentstreak << endl;
    }
}

Leaderboard& Leaderboard::operator=(const Leaderboard& rhs){
    if (this == &rhs){
        return *this;
    }
    maxSize = rhs.maxSize;
    currentSize = rhs.currentSize;
    PlayerRecord* temp = new PlayerRecord[maxSize];
    for (int i = 0; i < currentSize; i++){
        temp[i] = rhs.records[i];
    }
    delete [] records;
    records = temp;
    return *this;
}
void Leaderboard::resize(){
    maxSize = maxSize * 2;
    PlayerRecord* temp = new PlayerRecord[maxSize];
    for (int i = 0; i < currentSize; i++){
        temp[i] = records[i];
    }
    delete[] records;
    records = temp;
}

Leaderboard::~Leaderboard(){
    delete[] records;
}
