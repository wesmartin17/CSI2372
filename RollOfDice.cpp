#include "RollOfDice.h"
#include <iostream>
#include <ctime>


int RandomDice(){

	static std::default_random_engine rng(std::random_device{}());
  static 	std::uniform_int_distribution<int> dist(1,6);
  return dist(rng);

}

Dice::Dice(const Color color){
	diceColor = color;
	face = RandomDice();
}

void Dice::roll(){
	face = RandomDice();
}

void RollOfDice::roll(){
	for(std::vector<Dice>::iterator it = dices.begin(); it != dices.end(); ++it){

		Dice d = *it;
		d.roll();

	}
}

RollOfDice RollOfDice::pair(){
	RollOfDice rd();
	//rd.dices.push_back(new Dice(Color.red)); //Not sure how this is supposed to work
}

//conversion operator to int.  is the sum of faces
RollOfDice::operator int(){

	int sum;
	for(std::vector<Dice>::iterator it = dices.begin(); it != dices.end(); ++it){

		Dice d = *it;
		sum+= d.face;
	}
	return sum;
}
