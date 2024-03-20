/*Written by Steve Nwachukwu and Nick Larkin*/
#include "dice.hpp"

Dice::Dice(int n){
    nDice = n;
    diceVal = new int [nDice];
    srand(time(NULL));

} //constructor for the dice

Dice::~Dice() {
    delete [] diceVal;
} //destructor for the dice

const int* Dice::
roll () {
    for (int j = 0; j < nDice; j++) {
        diceVal [j] = rand()%6+1;
    }
    return diceVal;
} //the dice value array

ostream& Dice::print(ostream& diceOutput) {
    for (int j = 0; j < nDice; j++) {
        diceOutput << diceVal [j] << " ";
    }
    return diceOutput;

} //print function for the program
