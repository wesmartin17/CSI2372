#ifndef ROLLOFDICE_H_
#define ROLLOFDICE_H_

#include <vector>
#include <random>
#include <iostream>


 struct RandomDice{

	static int value;

};

struct Dice{

		enum Color { red, yellow, blue };

		Color diceColor;

		int face;

		Dice(Color color);

		int roll();

	};

struct RollOfDice {

	std::vector<Dice> dices;

	int roll();

	static RollOfDice pair(Dice d1, Dice d2);

	operator int();

	friend std::ostream& operator<<(std::ostream& os, const RollOfDice & rd);

};

#endif
