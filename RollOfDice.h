#ifndef ROLLOFDICE_H_
#define ROLLOFDICE_H_

#include <vector>

enum Color { red, yellow, blue };

struct Dice{
		
		const Color color;
		
		int face;

		Dice(Color color);
		
		void roll();
				
	};

struct RollOfDice {
		
	std::vector<Dice> dices;
	
	void roll();

};

#endif
