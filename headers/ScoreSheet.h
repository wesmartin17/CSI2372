#ifndef SCORE_SHEET_
#define SCORE_SHEET_

#include <string>
#include <iostream>

#include "RollOfDice.h"

using namespace std;

template<class T>
class ScoreSheet{

	private:
		int totalScore=0;
		string playerName;
		friend std::ostream& operator<<(std::ostream& os, T & sheet){
			os << "\nPlayer name: " << sheet.playerName;
			int score = sheet.totalScore; // TODO: Make this sheet.calcTotal()
			if(score > 0){
				os << "\t Points: " << score;
			}
			os << "\n\t          ------------------------------------------------- ";
			sheet.print(os, sheet);
			return os;
		};

	public:
		int failedAttempts=0;
		ScoreSheet(string _playerName) : playerName(_playerName) {};
		virtual ostream& print(std::ostream& os, T & sheet);
		virtual bool score(RollOfDice &rollOfdice, Dice::Color color, int pos=-1);
		virtual bool twoRows();
		virtual int setTotal();
		virtual int calcTotal();

};
#endif
