#include "RollOfDice.h"
#include <iostream>
#include <ctime>


int RandomDice(){

	static std::default_random_engine rng(time(0));
  static 	std::uniform_int_distribution<int> dist(1,6);
  return dist(rng);

}

Dice::Dice(const Color color){
	diceColor = color;
	face = RandomDice();
}

int Dice::roll(){
	face = RandomDice();
	return face;
}

int RollOfDice::roll(){
	int result = 0;
	for(std::vector<Dice>::iterator it = dices.begin(); it != dices.end(); ++it){

		Dice d = *it;
		result += d.roll();

	}
	return result;
}

RollOfDice RollOfDice::pair(Dice d1, Dice d2){
	RollOfDice rd;
	rd.dices.push_back(d1);
	rd.dices.push_back(d2);

	return rd;
}

//conversion operator to int.  is the sum of faces
RollOfDice::operator int(){

	int sum;
	for(std::vector<Dice>::iterator it = dices.begin(); it != dices.end(); ++it){

		Dice d = *it;
		sum+= d.face;
		std::cout<< "hi" <<  sum;
	}
	return sum;
}

std::ostream& RollOfDice::operator<<(std::ostream& os){
	for(std::vector<Dice>::iterator it = dices.begin(); it != dices.end(); ++it){

		Dice d = *it;
		os<<d.face;
	}
	return os;
}
