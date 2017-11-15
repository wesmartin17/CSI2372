#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string _name, bool _active ){
  name = _name;
}

void Player::inputAfterRoll(RollOfDice &_rollOfDice){
  int numberOfDice;
  cin >> numberOfDice;
  //Dice::Dice = new Dice;
  for(int i = 0; i < numberOfDice; i++){

    //*_rollOfDice.dices.insert();
  }
}
