#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
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

int main() {

	/*
		main rountine area
	*/

	int gameVersion = versionSelection(); // Ask player to choose a version
	int numberOfPlayers = playersNumberSelection(); // Ask player to choose number of players

	if(gameVersion==1){ // PLAYING QWINTO

		// Create Corresponding Players
		vector<QwintoPlayer> players = createQwintoPlayers(numberOfPlayers);

		/*
			While end condition is not reached
		*/
		bool gameOver = false;
		while(!gameOver){


			vector<QwintoPlayer>::iterator activePlayer; //Loop over qwinto players
			for(activePlayer = players.begin(); activePlayer<players.end(); activePlayer++){

				activePlayer->active = true; // next player takes a turn i.e., becomes active
				cout << "\n" << activePlayer->name << " it's YOUR turn!!" << endl;
				RollOfDice rd;
				activePlayer->inputBeforeRoll(rd); // get input from active player before roll
				rd.roll(); // roll the dice
				cout << "\nRolling...\n .\\./.\\./.\\ ~~ [?]\n[" << int(rd) << "] !!\n"; // show result
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


	}else{//PLAYING QWIXX
			vector<QwixxPlayer> players = createQwixxPlayers(numberOfPlayers);

			bool gameOver = false;
			while(!gameOver){
							vector<QwixxPlayer>::iterator activePlayer; //Loop over qwinto players
							for(activePlayer = players.begin(); activePlayer<players.end(); activePlayer++){

								activePlayer->active = true; // next player takes a turn i.e., becomes active
								cout << "\n" << activePlayer->name << " it's YOUR turn!!" << endl;
								RollOfDice rd;
								rd.dices.push_back(Dice(Dice::Color::white));
								rd.dices.push_back(Dice(Dice::Color::white));


								cout << "\nRolling white dice...\n .\\./.\\./.\\ ~~ [?]\n";
								cout << "----------------------------------"<<endl;
								cout << "WHITE #1: ["<<rd.dices[0].face<<"]"<<endl;
								cout << "WHITE #2: ["<<rd.dices[1].face<<"]"<<endl<<endl;
								cout << "SUM: "<<int(rd)<<endl;
								cout << "----------------------------------"<<endl;

								cout<<activePlayer->scoreSheet<<endl;
								activePlayer->inputBeforeRoll(rd);
								for(vector<QwixxPlayer>::iterator i = players.begin(); i != players.end(); ++i){
										if(!i->active){
										cout<<i->scoreSheet<<endl;
										i->inputBeforeRoll(rd);
									}
								}

								rd.dices.push_back(Dice(Dice::Color::red));
								rd.dices.push_back(Dice(Dice::Color::yellow));
								rd.dices.push_back(Dice(Dice::Color::blue));
								rd.dices.push_back(Dice(Dice::Color::green));

								cout<<endl<<"Rolling colored dice:"<<endl;
								for(vector<Dice>::iterator it = rd.dices.begin()+2; it != rd.dices.end(); ++it){
									Dice d = *it;
									switch(d.diceColor){
										case 0:
											cout<<"red"<<" ["<<d.face<<"]"<<endl;
											break;
										case 1:
											cout<<"YELLOW"<<" ["<<d.face<<"]"<<endl;
											break;
										case 2:
											cout<<"BLUE"<<" ["<<d.face<<"]"<<endl;
											break;
										case 3:
											cout<<"GREEN"<<" ["<<d.face<<"]"<<endl<<endl;
											break;
									}

								}
								cout << "WHITE #1: ["<<rd.dices[0].face<<"]"<<endl;
								cout << "WHITE #2: ["<<rd.dices[1].face<<"]"<<endl<<endl;

								activePlayer->inputAfterRoll(rd);

								if(!activePlayer->scoreSheet){ // End condition met by active player
									cout << "The game will end as a result." << endl;
									gameOver = true;
									break;
								}

								vector<QwixxPlayer>::iterator inactivePlayer;
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

	}

	/*
		end of main routine area
	*/

}
