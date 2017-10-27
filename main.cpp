#include <iostream>
#include "ScoreSheet.h"
#include <sstream>

int versionSelection(){
	string input = "";
	int gameVersion = 0;

	cout<<"Choose a version by entering the version number \n"
	    <<"[1] Qwinto \n"
	    <<"[2] Qwixx " << endl;

	while (true) {
	   cout << "Your selection: ";
	   getline(cin, input);
	   stringstream myStream(input);
	   if (myStream >> gameVersion){
			 if(gameVersion == 1 || gameVersion == 2)
	     break;
		 }
	   cout << "Invalid number, please try again" << endl;
	 }
	 return gameVersion;
}

int playersNumberSelection(){
	string input = "";
	int numberPlayers = 0;

	cout<<"Choose a number of players between 2 and 6" << endl;

	while (true) {
	   cout << "Your selection: ";
	   getline(cin, input);
	   stringstream myStream(input);
	   if (myStream >> numberPlayers){
			 if(numberPlayers >= 2 && numberPlayers <= 6)
	     break;
		 }
	   cout << "Invalid number, please try again" << endl;
	 }
	 return numberPlayers;
}

vector<string> playersRegisteration(int numberOfPlayers){
	vector<string> playerNames;
	cout<<"Enter each player's name" << endl;
	string input;
	for(int i=0; i < numberOfPlayers; i++){
		cout<<"Player #" << i+1 << ": " << endl;
		getline(cin, input);
		playerNames.push_back(input);
	}

	return playerNames;
}

int main() {

	// ScoreSheet s("Wes");
	// s.print(cout);
	int gameVersion = versionSelection();
	int numberOfPlayers = playersNumberSelection();
	string* playerNames = &playersRegisteration(numberOfPlayers)[0];

}
