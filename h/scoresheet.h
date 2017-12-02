#ifndef SCORE_SHEET_
#define SCORE_SHEET_
#include "rollofdice.h"


enum Color { red, yellow, blue, green, white };

template<class T>
class ScoreSheet{

	private:
		int totalScore=0;
		string playerName;

		friend std::ostream& operator<<(std::ostream& os, T & sheet){
			os << "\nPlayer name: " << sheet.playerName;
			int score = sheet.totalScore;
			if(score != 0){
				os << "\t Points: " << score;
			}
			os << "\n\t          ------------------------------------------------- ";
			sheet.print(os, sheet);
			return os;
		};

		friend bool operator not(T & sheet){
			return sheet.notOperator();
		};

	public:
		std::vector<RollOfDice> failedAttempts;
		ScoreSheet(string _playerName) : playerName(_playerName) {};
		virtual ostream& print(std::ostream& os, T & sheet);
		virtual bool score(RollOfDice &rollOfdice, Dice::Color color, int pos=-1);
		virtual bool twoRows();
		virtual int setTotal();
		virtual int calcTotal();
		virtual bool notOperator();
		// virtual ~ScoreSheet()=0;
};


#include "qwintoscoresheet.h"
#include "qwixxscoresheet.h"
#endif
