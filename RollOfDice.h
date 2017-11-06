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

		Dice(const Color color);

		void roll();

	};

struct RollOfDice {

	std::vector<Dice> dices;

	void roll();
	RollOfDice pair();

	operator int();

};

#endif
