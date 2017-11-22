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
		string playerName;

	public:
		ScoreSheet(string _playerName) : playerName(_playerName) {};
		// virtual void score(RollOfDice &rollOfdice, Dice::Color color, int pos=-1);
		// virtual void setTotal();
		// virtual string getPlayerName();
		// virtual int calcTotal();

};
#endif
