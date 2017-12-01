#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "cpp/QwintoPlayer.cpp"

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

vector<string> inputPlayersNames(int numberOfPlayers){
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
	if(gameVersion==1){
		vector<string> names = inputPlayersNames(numberOfPlayers);
		vector<QwintoPlayer> players;
		for(int i=0; i<names.size(); ++i){
			QwintoScoreSheet scoreSheet = QwintoScoreSheet(names[i]);
			players.push_back(QwintoPlayer(names[i], scoreSheet));
		}

		/*
			While game not over
		*/
		bool gameOver = false;
		while(!gameOver){

			//Loop over players
			vector<QwintoPlayer>::iterator activePlayer;
			for(activePlayer = players.begin(); activePlayer<players.end(); activePlayer++){

				activePlayer->active = true; // next player takes a turn i.e., becomes active
				std::cout << "\n" << activePlayer->name << " it's YOUR turn!!" << endl;
				RollOfDice rd;
				activePlayer->inputBeforeRoll(rd); // get input from active player before roll
				rd.roll(); // roll the dice
				std::cout << "\nRolling...\n .\\./.\\./.\\ ~~ [?]\n[" << int(rd) << "] !!\n"; // show result
				std::cout << "\nHere's what your sheet currently looks like: ";
				std::cout << activePlayer->scoreSheet << endl; // print scoresheet of active player
				std::cout << "Your rolled a [" << int(rd) << "]\n"; // roll dice and show result
				std::cout << "What would you like to do?\n" << endl;
				activePlayer->inputAfterRoll(rd);  // get input from active player after roll
				if(!activePlayer->scoreSheet){
					std::cout << "The game will end as a result." << endl;
					gameOver = true;
					break;
				}

				vector<QwintoPlayer>::iterator inactivePlayer;
				for(inactivePlayer = players.begin(); inactivePlayer<players.end(); inactivePlayer++){
					if(!inactivePlayer->active){
						cout << inactivePlayer->scoreSheet << endl;
						inactivePlayer->inputAfterRoll(rd);
						if(!inactivePlayer->scoreSheet){
							std::cout << "The game will end as a result." << endl;
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
		string winnerName = names[0]; // placeholder value
		int winnerScore = -100; // placeholder value
		int score = winnerScore; // placeholder value

		for(int i = 0; i <numberOfPlayers; ++i){
			score = players[i].scoreSheet.setTotal(); // Calculate score for each player
			std::cout << players[i].scoreSheet; // Show score sheet for each player
			if(winnerScore < score){
				winnerScore = score;
				winner = players[i];
				winnerName = players[i].name;
			}
		}
		// Announce winner.
		std::cout << "Congradulations to " << winnerName << " for winning the game with " << winnerScore << " points!" << endl;


	}else{
		cout << "Qwixx isn't implemented yet!" << endl;
	}

	/*
		end of main routine area
	*/


	/*
		playground area
		Prototyping stuff go here
	*/

	/////////////////////
	// RollOfDice stuff//
	/////////////////////
	// std::vector<Dice> d;
	// int arr[] = {0,0,0,0,0,0};int numRolls = 1000000;
	// cout<<"rolled "<<numRolls<<" times...\n";
	// for(int i = 0; i < numRolls; ++i){
	// 	d.push_back( Dice(Dice::Color::blue));
	// 	arr[d[i].face-1]++;
	// }
	// for(int i = 0; i < 6; i++){
	// 	cout<<"number times a "<<(i+1)<<" was rolled: "<<arr[i]<<"\n\n";
	// }

	////////////////////
	// QwintoRow stuff//
	////////////////////
	// QwintoRow<red> row;
	// Dice d1 = Dice(Dice::Color::blue);
	// Dice d2 = Dice(Dice::Color::red);
	// Dice d3 = Dice(Dice::Color::red);
	// RollOfDice rd;
	// rd.dices.push_back(d1);
	// rd.dices.push_back(d2);
	// rd.dices.push_back(d3);
	// try{
	// 	row[2] = rd;
	// 	row[20] = rd;
	// }catch(const std::exception& e){
	// 	std::cout << e.what() << endl;
	// 	std::cout << "Please choose an available cell." << endl;
	// }
 	// std::cout << row[2].roll() << endl;
	// rd.roll();
	// rd.roll();
	// cout << int(rd);
	// cout << rd << "\n";
	// cout << int(rd) << "\n";

	///////////////////////////
	// QwintoScoreSheet stuff//
	//////////////////////////
	// QwintoScoreSheet karim = QwintoScoreSheet("Karim");
	// cout << karim;
	// Dice d1 = Dice(Dice::Color::blue);
	// Dice d2 = Dice(Dice::Color::red);
	// Dice d3 = Dice(Dice::Color::red);
	// RollOfDice rd;
	// rd.dices.push_back(d1);
	// rd.dices.push_back(d2);
	// rd.dices.push_back(d3);
	// rd.roll();
	// cout << rd << endl;
	// karim.score(rd, Dice::Color::red, 1);
	// cout << karim;
	// karim.score(rd, Dice::Color::red, 1);
	// karim.score(rd, Dice::Color::blue, 3);


	/////////////////////
	/// Player stuff ////
	/////////////////////
	// RollOfDice rd;
	// for(int i = 0;  i < players.size(); i ++){
	// 	activePlayer->inputBeforeRoll(rd);
	// }
	// int tmp;
	// while(tmp < numberOfPlayers){
	// 	players.push_back(new Player(playersNames),false);
	// 	playersNames++;
	// 	tmp ++;
	// }
	// RollOfDice rd;
	// QwintoScoreSheet ss = QwintoScoreSheet("bob");
	// rd.dices.push_back(Dice::Color::red);
	// rd.roll();
	// ss.score(rd, Dice::Color::red, 1);
	// cout << ss;

	// players[0].print();
	// QwintoScoreSheet scoreSheet = QwintoScoreSheet("Karim");
	// scoreSheetK.print();

}
