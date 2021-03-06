#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>
#include <stdio.h>
#include <functional>
#include <random>
#include "h/player.h"


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
	int numberOfPlayers = 0;

	cout<<"Choose a number of players between 1 and 3" << endl;

	while (true) {
	   cout << "Your selection: ";
	   getline(cin, input);
	   stringstream myStream(input);
	   if (myStream >> numberOfPlayers){
			 if(numberOfPlayers >= 1 && numberOfPlayers <= 3)
	     break;
		 }
	   cout << "Invalid number, please try again" << endl;
	 }
	 return numberOfPlayers;
}

vector<QwintoPlayer> createQwintoPlayers(int numberOfPlayers){

	vector<QwintoPlayer> players;
	vector<string> playerNames;
	cout<<"Enter each player's name" << endl;
	string input;

	for(int i=0; i < numberOfPlayers; ++i){
		cout<<"Player #" << i+1 << ": " << endl;
		getline(cin, input);
		if(find(playerNames.begin(), playerNames.end(), input) != playerNames.end()){
			cout << "Player " << input << " already exists. Enter a differend name." << endl;
			--i;
		}else{
			playerNames.push_back(input);
			players.push_back(QwintoPlayer(input, QwintoScoreSheet(input)));
		}
	}
	return players;
}

vector<QwixxPlayer> createQwixxPlayers(int numberOfPlayers){

	vector<QwixxPlayer> players;
	vector<string> playerNames;
	cout<<"Enter each player's name" << endl;
	string input;

	for(int i=0; i < numberOfPlayers; ++i){
		cout<<"Player #" << i+1 << ": " << endl;
		getline(cin, input);
		if(find(playerNames.begin(), playerNames.end(), input) != playerNames.end()){
			cout << "Player " << input << " already exists. Enter a differend name." << endl;
			--i;
		}else{
			playerNames.push_back(input);
			players.push_back(QwixxPlayer(input, QwixxScoreSheet(input)));
		}
	}
	return players;
}

/*
	Main routine for a game of Qwinto
*/
void playQwinto(int numberOfPlayers){
	// Create Corresponding Players
	vector<QwintoPlayer> players = createQwintoPlayers(numberOfPlayers);
	bool gameOver = false;

	//While end condition is not reached
	while(!gameOver){
		vector<QwintoPlayer>::iterator activePlayer; //Loop over players
		for(activePlayer = players.begin(); activePlayer<players.end(); activePlayer++){

			activePlayer->active = true; // next player takes a turn i.e., becomes active
			cout << "\n" << activePlayer->name << " it's YOUR turn!!" << endl;
			RollOfDice rd;
			activePlayer->inputBeforeRoll(rd); // get input from active player before roll
			rd.roll(); // roll the dice
			cout << "\nRolling...\n .\\./.\\./.\\ ~~ [?]\n" << rd << " !!\n"; // show result
			cout << "\nHere's what your sheet currently looks like: ";
			cout << activePlayer->scoreSheet << endl; // print scoresheet of active player
			cout << "Your rolled a [" << int(rd) << "]\n";
			cout << "What would you like to do?\n" << endl;
			activePlayer->inputAfterRoll(rd);  // get input from active player after roll
			if(!activePlayer->scoreSheet){ // End condition met by active player
				cout << "The game will end as a result." << endl;
				gameOver = true;
				break;
			}

			vector<QwintoPlayer>::iterator inactivePlayer;
			for(inactivePlayer = players.begin(); inactivePlayer<players.end(); inactivePlayer++){
				if(!inactivePlayer->active){
					cout << inactivePlayer->scoreSheet << endl;
					inactivePlayer->inputAfterRoll(rd);
					if(!inactivePlayer->scoreSheet){ // End condition met by inactive player
						cout << "The game will end as a result." << endl;
						gameOver = true;
						break;
					}
				}
			}
			activePlayer->active = false; // mark player as inactive and go to next player
		}
	}
	/*
		GAME IS OVER
	*/
	QwintoPlayer winner = players[0]; // placeholder value
	string winnerName = winner.name; // placeholder value
	int winnerScore = -100; // placeholder value
	int score = winnerScore; // placeholder value

	for(int i = 0; i <numberOfPlayers; ++i){
		score = players[i].scoreSheet.setTotal(); // Calculate score for each player
		cout << players[i].scoreSheet; // Show score sheet for each player
		if(winnerScore < score){
			winnerScore = score;
			winner = players[i];
			winnerName = players[i].name;
		}
	}
	// Announce winner.
	cout << "Congradulations to " << winnerName << " for winning the game with " << winnerScore << " points!" << endl;
	return;
}

/*
	Main routine for a game of Qwixx
*/
void playQwixx(int numberOfPlayers){
	vector<QwixxPlayer> players = createQwixxPlayers(numberOfPlayers);
	bool gameOver = false;
	vector<Color> availableColors = {red, yellow, green, blue};
	//While end condition is not reached
	while(!gameOver){
		vector<QwixxPlayer>::iterator activePlayer; //Loop over players
		//starts every player's turn
		for(activePlayer = players.begin(); activePlayer<players.end(); activePlayer++){

			activePlayer->active = true; // next player takes a turn i.e., becomes active
			cout << "\n" << activePlayer->name << " it's YOUR turn!!" << endl;
			RollOfDice rd;
			rd.dices.push_back(Dice(Color::white));
			rd.dices.push_back(Dice(Color::white));
			for(int i=0; i<availableColors.size(); ++i){
				rd.dices.push_back(Dice(availableColors[i]));
			}
			RollOfDice wd = RollOfDice::pair(rd.dices[0], rd.dices[1]);

			rd.roll();
			cout << "\nRolling dice...\n .\\./.\\./.\\./.\\./.\\./ ~~ [?][?][?][?][?][?]\n";
			cout << rd;
			cout << "----------------------------------"<<endl;
			cout << "WHITE #1: ["<<rd.dices[0].face<<"]"<<endl;
			cout << "WHITE #2: ["<<rd.dices[1].face<<"]"<<endl<<endl;
			cout << "SUM: "<<int(wd)<<endl;
			cout << "----------------------------------"<<endl;
			for(vector<QwixxPlayer>::iterator i = players.begin(); i != players.end(); ++i){
					cout<< i->scoreSheet <<endl;
					i->inputBeforeRoll(wd);
					// Check if any rows are locked
					if(int(i->scoreSheet.redRow[11])!=0){
						if ( find(availableColors.begin(), availableColors.end(), red) != availableColors.end() ){
							availableColors.erase(remove(availableColors.begin(), availableColors.end(), red), availableColors.end());
							cout << "[!] Red die removed from the game." << endl;

						}
					}
					if(int(i->scoreSheet.yellowRow[11])!=0){
						if ( find(availableColors.begin(), availableColors.end(), yellow) != availableColors.end() ){
							availableColors.erase(remove(availableColors.begin(), availableColors.end(), yellow), availableColors.end());
							cout << "[!] Yellow die removed from the game." << endl;
						}
					}
					if(int(i->scoreSheet.greenRow[11])!=0){
						if ( find(availableColors.begin(), availableColors.end(), green) != availableColors.end() ){
							availableColors.erase(remove(availableColors.begin(), availableColors.end(), green), availableColors.end());
							cout << "[!] Green die removed from the game." << endl;
						}
					}
					if(int(i->scoreSheet.blueRow[11])!=0){
						if ( find(availableColors.begin(), availableColors.end(), blue) != availableColors.end() ){
							availableColors.erase(remove(availableColors.begin(), availableColors.end(), blue), availableColors.end());
							cout << "[!] Blue die removed from the game." << endl;
						}
					}
					if(!i->scoreSheet){ // End condition met by active player
						cout << "The game will end as a result." << endl;
						gameOver = true;
						break;
					}
			}

			cout << "\n" << activePlayer->name
					<< ", it's you turn to choose a white dice (number 1 or number 2) as well as a colored dice to score their sum." << endl << activePlayer->scoreSheet <<endl<<rd <<endl;
			activePlayer->inputAfterRoll(rd);
			// Check if any rows are locked
			if(int(activePlayer->scoreSheet.redRow[11])!=0){
				if ( find(availableColors.begin(), availableColors.end(), red) != availableColors.end() ){
					availableColors.erase(remove(availableColors.begin(), availableColors.end(), red), availableColors.end());
					cout << "[!] Red die removed from the game." << endl;

				}
			}
			if(int(activePlayer->scoreSheet.yellowRow[11])!=0){
				if ( find(availableColors.begin(), availableColors.end(), yellow) != availableColors.end() ){
					availableColors.erase(remove(availableColors.begin(), availableColors.end(), yellow), availableColors.end());
					cout << "[!] Yellow die removed from the game." << endl;
				}
			}
			if(int(activePlayer->scoreSheet.greenRow[11])!=0){
				if ( find(availableColors.begin(), availableColors.end(), green) != availableColors.end() ){
					availableColors.erase(remove(availableColors.begin(), availableColors.end(), green), availableColors.end());
					cout << "[!] Green die removed from the game." << endl;
				}
			}
			if(int(activePlayer->scoreSheet.blueRow[11])!=0){
				if ( find(availableColors.begin(), availableColors.end(), blue) != availableColors.end() ){
					availableColors.erase(remove(availableColors.begin(), availableColors.end(), blue), availableColors.end());
					cout << "[!] Blue die removed from the game." << endl;
				}
			}

			if(!activePlayer->scoreSheet){ // End condition met by active player
				cout << "The game will end as a result." << endl;
				gameOver = true;
				break;
			}

			vector<QwixxPlayer>::iterator inactivePlayer;
			for(inactivePlayer = players.begin(); inactivePlayer<players.end(); inactivePlayer++){
				if(!inactivePlayer->active){
					if(!inactivePlayer->scoreSheet){ // End condition met by inactive player
						cout << "The game will end as a result." << endl;
						gameOver = true;
						break;
					}
				}
			}
			activePlayer->active = false; // mark player as inactive and go to next player
		}
	}
	/*
		GAME IS OVER
	*/
	QwixxPlayer winner = players[0]; // placeholder value
	string winnerName = winner.name; // placeholder value
	int winnerScore = -100; // placeholder value
	int score = winnerScore; // placeholder value

	for(int i = 0; i <numberOfPlayers; ++i){
		score = players[i].scoreSheet.setTotal(); // Calculate score for each player
		cout << players[i].scoreSheet; // Show score sheet for each player
		if(winnerScore < score){
			winnerScore = score;
			winner = players[i];
			winnerName = players[i].name;
		}
	}
	// Announce winner.
	cout << "Congradulations to " << winnerName << " for winning the game with " << winnerScore << " points!" << endl;
	return;
}

int main() {

	/*
		main rountine area
	*/

	int gameVersion = versionSelection(); // Ask player to choose a version
	int numberOfPlayers = playersNumberSelection(); // Ask player to choose number of players

	if(gameVersion==1){ // PLAYING QWINTO
		playQwinto(numberOfPlayers);
	}
	if(gameVersion==2){ // PLAYING QWIXX
		playQwixx(numberOfPlayers);
	}

	/*
		end of main routine area
	*/


}
