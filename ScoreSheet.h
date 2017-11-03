#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum Color {red, yellow, blue};

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
		void score(RollOfDice &rollOfdice, Color color, int pos=-1);

};
