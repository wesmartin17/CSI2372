#ifndef SCORE_SHEET_
#define SCORE_SHEET_
#include "rollofdice.h"



template<class T>
class ScoreSheet{

	private:
		string playerName;

		friend ostream& operator<<(ostream& os, T & sheet){
			// Prints name and score
			os << "\nPlayer name: " << sheet.playerName;
			int score = sheet.totalScore;
			if(score != 0){
				os << "\t Points: " << score;
			}

			// Prints the rows
			sheet << os;

			return os;
		};

		// friend bool operator not(T & sheet){
		// 	return not(sheet);
		// };

	public:
		int totalScore=0;
		vector<RollOfDice> failedAttempts;
		ScoreSheet(string _playerName) : playerName(_playerName) {};
		// virtual ostream& print(ostream& os) = 0;
		virtual bool score(RollOfDice &rollOfdice, Color color, int pos=-1) = 0;
		virtual int setTotal() = 0;
		virtual int calcTotal() = 0;
		virtual bool operator!() = 0;
		// virtual ~ScoreSheet()=0;
};


#include "qwinto/qwintoscoresheet.h"
#include "qwixx/qwixxscoresheet.h"
#endif
