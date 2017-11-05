#include "RollOfDice.h"
#include <iostream>


void Dice::roll(){
		
}

void RollOfDice::roll(){
	for(auto it = dices.begin(); it != dices.end(); ++it){
		std::cout<<"rolling";	
	}
}
