#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

#include "ScoreSheet.h"
#include "RollOfDice.h"
#include "QwintoRow.cpp"


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

	cout<<"Choose a number of players between 1 and 3" << endl;

	while (true) {
	   cout << "Your selection: ";
	   getline(cin, input);
	   stringstream myStream(input);
	   if (myStream >> numberPlayers){
			 if(numberPlayers >= 1 && numberPlayers <= 3)
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
	for(int i=0; i < numberOfPlayers; ++i){
		cout<<"Player #" << i+1 << ": " << endl;
		getline(cin, input);
		if(std::find(playerNames.begin(), playerNames.end(), input) != playerNames.end()){
			cout << "Player " << input << " already exists. Enter a differend name." << endl;
			--i;
		}else{
			playerNames.push_back(input);
		}
	}

	return playerNames;
}

int main() {


	/*
		main rountine area
		Final stuff go here
	*/
	int gameVersion = versionSelection();
	int numberOfPlayers = playersNumberSelection();
	string* playerNames = &playersRegisteration(numberOfPlayers)[0];
	// end of main routine area


	/*
		playground area
		prototyping stuff go here
	*/

	/////////////////////
	// RollOfDice SUTFF//
	/////////////////////
	// std::vector<Dice> d;
	// int arr[] = {0,0,0,0,0,0};int numRolls = 1000000;
	// cout<<"rolled "<<numRolls<<" times...\n";
	// for(int i = 0; i < numRolls; ++i){
	// 	d.push_back( Dice(Dice::Color::blue));
	// 	arr[d[i].face-1]++;
	// }
  //
	// for(int i = 0; i < 6; i++){
	// 	cout<<"number times a "<<(i+1)<<" was rolled: "<<arr[i]<<"\n\n";
	// }

	////////////////////
	// QwintoRow SUTFF//
	////////////////////
	// QwintoRow<red> row;
	// RollOfDice rd;
	// row [2] = rd;
	// try{
	// 	row[20] = rd;
	// }catch(const std::exception& e){
	// 	std::cout << e.what() << endl;
	// 	std::cout << "Please choose an available cell." << endl;
	// }


}
