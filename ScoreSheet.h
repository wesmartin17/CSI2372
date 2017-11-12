#ifndef SCORE_SHEET_
#define SCORE_SHEET_

#include <string>
#include <iostream>

#include "RollOfDice.h"

using namespace std;
class ScoreSheet{

	private:
		int failedAttempts;
		int redScore;
		int yellowScore;
		int blueScore;
		int totalScore;

	public:
		void print(ostream& o);
		void score(RollOfDice &rollOfdice, Dice::Color color, int pos=-1);
		void setTotal();

	protected:
		string playerName;
		int calcTotal();

};

#endif
