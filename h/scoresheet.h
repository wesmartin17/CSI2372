#ifndef SCORE_SHEET_
#define SCORE_SHEET_
#include "rollofdice.h"



template<class T>
class ScoreSheet{

	private:
		string playerName;

		friend ostream& operator<<(ostream& os, T & sheet){
			os << "\nPlayer name: " << sheet.playerName;
			int score = sheet.totalScore;
			if(score != 0){
				os << "\t Points: " << score;
			}
			sheet.print(os);
			return os;
		};

		friend bool operator not(T & sheet){
			return sheet.notOperator();
		};

	public:
		int totalScore=0;
		vector<RollOfDice> failedAttempts;
		ScoreSheet(string _playerName) : playerName(_playerName) {};
		virtual ostream& print(ostream& os) = 0;
		virtual bool score(RollOfDice &rollOfdice, Color color, int pos=-1) = 0;
		virtual bool twoRows() = 0;
		virtual int setTotal() = 0;
		virtual int calcTotal() = 0;
		virtual bool notOperator() = 0;
		// virtual ~ScoreSheet()=0;
};


#include "qwintoscoresheet.h"
#include "qwixxscoresheet.h"
#endif
