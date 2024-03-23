/*Written by Steve Nwachukwu and Nick Larkin*/
#include <iostream>
#include <fstream>
#include "dice.hpp"
#include "Player.hpp"
#include "tools.hpp"
#include "Enum.hpp"
#include "column.hpp"
#include "game.hpp"
#include "board.hpp"
#include "CList.hpp"

//function prototypes for the program
void UnitDice();
void UnitPlayer();
void UnitColumn();
void testGame(Game&);
void unitBoard();
void unitCList();
//-----------------------------------------------
int main() {
    //UnitDice();
    //UnitPlayer();
    //UnitColumn();
    //unitBoard();
    //Game gameclass;
    //Game gaming;
    //testGame(gameclass);
    //gaming.start();
    unitCList();
    bye();
    return 0;
}
//-----------------------------------------------
void UnitDice (){
    srand(time(nullptr)); // random number each time

    // Testing all numbers from 1 to 10
    int nDice = rand() % 10 + 1  ;
    banner() ;
    ofstream Diceroll("Diceroll.txt",ios::app);
    // Testing if open
    if (!Diceroll.is_open()) {
        fatal( "Could not open Dice.Txt file");
    }

    Dice rolling(nDice);
    Diceroll << "And your rolls are:" << endl;
    const int* Rollnum = rolling.roll();
    rolling.print(Diceroll);
    Diceroll << endl;
    // cout << "Now" << rolling << endl ;
    Diceroll.close();
} //the unit test for dice

void UnitPlayer () {
    Player playerVal ( "Jeff", ECcolor::green );
    for (int i=0; i < 3; i++)
    {
        cout << playerVal;
        playerVal.wonColumn(7);
    }

} //the unit test for player
/*
void UnitColumn () {
    const string colstates[3] = {"Available", "Pending", "Captured"};
    Column creation1(2);
    Column creation2(11);
    cout << boolalpha << creation1.move();
    cout << boolalpha << creation2.move();
    Player playing("Josh", ECcolor::blue);
    cout << boolalpha << creation1.startTower(&playing);
    cout << boolalpha << creation1.move();
    creation1.stop(&playing);
    cout << colstates[creation1.getState()];
    creation1.print(cout);
    cout << endl;
    cout << boolalpha << creation2.startTower(&playing);
    cout << boolalpha << creation2.move();
    creation2.stop(&playing);
    cout << colstates[creation2.getState()];
    creation2.print(cout);

} //the unit test for column */
void unitBoard(){
    Board Play;
    //cout << Play;
    Player playing ("John", ECcolor::blue);
    Play.startTurn(&playing);
    Play.move(6);
    cout << Play;
    Play.stop();
    Play.bust();
}

void testGame(Game& games) {
    games.unitTest();
} //the unit test for game

void unitCList() {
    ofstream CListNames ("CList.txt");

upp test1("Jacob", ECcolor::blue);
upp test2 ("Derek", ECcolor::green);
upp test3 ("Olivia", ECcolor::orange);
upp test4 ("Sadie", ECcolor::white);
cout << "Debug" << endl;

Cell* person1 = new Cell (test1);
Cell* person2 = new Cell (test2);
Cell* person3 = new Cell (test3);
Cell* person4 = new Cell (test4);
cout << "Debug" << endl;

CList obj;
obj.addCell(person1);
obj.addCell(person2);
obj.addCell(person3);
obj.addCell(person4);
cout << "Debug" << endl;
    obj.print(CListNames);
obj.init();
obj.next();
obj.remove();
cout << "Remove 1" << endl;
obj.remove();
cout << "Remove 2" << endl;
obj.remove();
cout << "Remove 3" << endl;
obj.remove();
cout << "Remove 4" << endl;

    obj.print(CListNames);


obj.addCell(person1);
obj.addCell(person2);
obj.addCell(person3);
obj.addCell(person4);
cout << "Debug" << endl;

obj.next();
obj.next();
obj.next();
obj.next();
cout << "Debug" << endl;

obj.print(CListNames);
cout << "Debug" << endl;
} //the unit test for CList
