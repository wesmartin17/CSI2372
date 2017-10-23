#include <string>
#include <iostream>
#include <vector>

using namespace std;
	
	enum Color{red, yellow, blue};
	
	struct Dice{
		int number;
		void print(ostream& o){
				cout<<number;
			}
	};

class ScoreSheet{
	
	private:
		string name;
		int failedAttempts;
		int redScore;
		int yellowScore;
		int blueScore;
		
	public:
		ScoreSheet(string playerName);
		void print(ostream& o);
		void score(vector<Dice> dice, Color color, int pos);
			
	
};
