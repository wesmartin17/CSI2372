#include <string>
#include <iostream>
#include <vector>

using namespace std;
	
	enum Color{red, yellow, blue};
	
	struct Dice{
		int number;
		void print(ostream o){
				cout<<number;
			}
	};

class SchoreSheet{
	
	private:
		string name;
		int failedAttempts;
		int playerScore;
		
	public:
		ScoreSheet(string playerName);
		void print(ostream o);
		void score(vector<Dice> dice, Color color, int pos);
			
	
};
