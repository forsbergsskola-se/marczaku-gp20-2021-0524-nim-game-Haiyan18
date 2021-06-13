#include <iostream>
#include <string>
#include "Nim.h"
using namespace std;

const int N_Matches = 24;
const int MatchesNumbers = 24;
const int Max_Move = 3;
const int No_Good_Move = -1;
const Player Start_Player = Player1;
Player simpleNim::opponent(Player player) {
    return (player == Player1) ? Player2 : Player1;
}

void simpleNim::printInstructions() {
    cout << "***************************************************************" << endl;
    cout << "Welcome to Nim Game!" << endl;
    cout << "There are " << N_Matches<<" matches on the table in this game." << endl;
    cout << "Players take turns to draw matches and may draw 1 to "<< Max_Move << " matches." << endl;
    cout << "player who has to take last match loses" << endl;
    cout << "***************************************************************" << endl << endl;
}

void simpleNim::play() {
    matches = N_Matches;
    whoseTurn = Start_Player;
    cout << "There are 24 matches on the table now." << endl;
    while (matches > 1){
        // cout << Printable ASCII [124]:\n << endl;
        cout << "||||||||||||||||||||||||" << endl;
        cout << "There are " << matches << " matches left on the table now." << endl << endl;
        if(whoseTurn == Player1){
            matches -= getUserMove();
        }else{
            int nTaken = getPlayer2Move();
            cout << "Player2: I will take " << nTaken << " matches." << endl;
            matches -= getPlayer2Move();
        }
        whoseTurn = opponent(whoseTurn);
    }
    announceResult();
}


int simpleNim::getPlayer2Move() {
    int nTaken = findGoodMove(matches);
    return (nTaken == No_Good_Move) ? 1 : nTaken;
}

int simpleNim::findGoodMove(int matches) {
    int limit = (matches < Max_Move) ? matches : Max_Move;
    for(int nTaken = 1; nTaken <= limit; nTaken++){
        if(isBadPosition(matches - nTaken)) return nTaken;
    }
    return No_Good_Move;
}

bool simpleNim::isBadPosition(int matches) {
    if(matches == 1) return true;
    return findGoodMove(matches) == No_Good_Move;
}

int simpleNim::getUserMove() {
    while(true){
        int nTaken;
        cout << "How many matches do you want to take? " << endl << "Player1: " ;
        cin >> nTaken;
        int limit = (matches < Max_Move) ? matches : Max_Move;
        if(nTaken > 0 && nTaken <= Max_Move) return nTaken;
        cout << "Invalid value, please input value from 1 to " << limit << endl;
    }
}

void simpleNim::announceResult() {
    if(matches == 0){
        cout << "You take the last match, you lose!" << endl;
    }else{
        cout << "There is only one match left!" << endl;
        if(whoseTurn == Player1){
            cout << "You lose!" << endl;
        }else {
            cout << "You win!" << endl;
        }
    }
}

int main(){
    simpleNim game;
    game.printInstructions();
    game.play();
    int var=124;
    cout<<(char)var<<endl;
    return 0;
}