#include <string>
#include <iostream>
#include <vector>

#include "RollOfDice.h"

using namespace std;

class ScoreSheet{

	private:
		string playerName;
		int failedAttempts;
		int redScore;
		int yellowScore;
		int blueScore;
		int totalScore;

	public:
		ScoreSheet(string _playerName);
		void print(ostream& o);
		void score(RollOfDice &rollOfdice, Dice::Color color, int pos=-1);

};
