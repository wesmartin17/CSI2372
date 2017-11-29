#include "../headers/QwintoScoreSheet.h"
#include "stdio.h"

template <class QwintoScoreSheet>
bool ScoreSheet<QwintoScoreSheet>::score(RollOfDice &rollOfdice, Dice::Color color, int pos){
	QwintoScoreSheet *qt = dynamic_cast<QwintoScoreSheet*>(this);
	RollOfDice* row;
	switch (color) {
		case Dice::Color::red: row = qt->redRow.values; break;
		case Dice::Color::yellow: row = qt->yellowRow.values; break;
		case Dice::Color::blue: row = qt->blueRow.values; break;
	}
	if(pos > 8 or pos < 0){
		std::cout << "Invalid input: #" << pos
							<< ":\nYou must select location cell number between 1 and 9" << endl;
		return false;
	}else if(int(row[pos]) != 0){
		std::cout << "Invalid input: #" << pos
							<< ":\nCell #" << pos << " already has value " << int(row[pos]) << endl;
		return false;
	}
	for(int i=0; i<9; ++i){
		if((int(row[i]) <= int(rollOfdice)) and (row[i]!=0)){
			std::cout << "Invalid input: #" << pos
								<< ":\nCell #" << i << " is right of cell #" << pos << " and holds [" << int(row[i]) << "] \n"
								<< "["<<int(row[i])<<"] is <= "<< "["<<int(rollOfdice)<<"] "<< endl;
			return false;
		}
	}

	row[pos] = rollOfdice;
	return true;
	}


template <class QwintoScoreSheet>
std::ostream& ScoreSheet<QwintoScoreSheet>::print(std::ostream& os, QwintoScoreSheet & sheet){

	//---- PRINTS RED ROW -----//
	os << "\nRed\t          ";
	for(int i=0; i<9; ++i){
	  if(sheet.redRow[i] == 0){
			if(i==8){
				os << "|    |"; // last
			}else if(i==1 or i==2 or i==4 or i==5){
				os << "$    "; // pentagons
			}else if(i==3){
				os << "|XX|    "; // middle
			}else{
				os << "|    "; // everything else
			}
	  }else{
			if(sheet.redRow[i]>9){ // for styling
				if(i==8){
					os << "| "<< sheet.redRow[i]<< " |"; // last
				}else if(i==1 or i==2 or i==4 or i==5){
					os << "$ "<< sheet.redRow[i] <<" "; // pentagons
				}else if(i==3){
					os << "|XX| "<< sheet.redRow[i] <<" "; // middle
				}else{
					os << "| "<< sheet.redRow[i] <<" "; // everything else
				}
			}else{
				if(i==8){
					os << "| "<< sheet.redRow[i]<< "  |"; // last
				}else if(i==1 or i==2 or i==4 or i==5){
					os << "$ "<< sheet.redRow[i] <<"  "; // pentagons
				}else if(i==3){
					os << "|XX| "<< sheet.redRow[i] <<"  "; // middle
				}else{
					os << "| "<< sheet.redRow[i] <<"  "; // everything else
				}
			}
		}

	}

	//---- PRINTS YELLOW ROW -----//
	os << "\n\t     ------------------------------------------------- ";
	os << "\nYellow       ";
	for(int i=0; i<9; ++i){
	  if(sheet.yellowRow[i] == 0){
			if(i==8){
				os << "|    |"; // last
			}else if(i==6 or i==7){
				os << "$    "; // pentagons
			}else if(i==5){
				os << "|XX|    "; // middle
			}else{
				os << "|    "; // everything else
			}
	  }else{
			if(sheet.yellowRow[i]>9){ // for styling
				if(i==8){
					os << "| "<< sheet.yellowRow[i] << " |"; // last
				}else if(i==6 or i==7){
					os << "$ "<< sheet.yellowRow[i] <<" "; // pentagons
				}else if(i==5){
					os << "|XX| "<< sheet.yellowRow[i] <<" "; // middle
				}else{
					os << "| "<< sheet.yellowRow[i] <<" "; // everything else
				}
			}else{
				if(i==8){
					os << "| "<< sheet.yellowRow[i] << "  |"; // last
				}else if(i==6 or i==7){
					os << "$ "<< sheet.yellowRow[i] <<"  "; // pentagons
				}else if(i==5){
					os << "|XX| "<< sheet.yellowRow[i] <<"  "; // middle
				}else{
					os << "| "<< sheet.yellowRow[i] <<"  "; // everything else
				}
			}
		}

	}
	os << "\n";

	//---- PRINTS BLUE ROW -----//
	os << "\t------------------------------------------------- ";
	os << "\nBlue    ";
	for(int i=0; i<9; ++i){
	  if(sheet.blueRow[i] == 0){
			if(i==8){
				os << "$    $"; // last is pentagon
			}else if(i==2 or i==3){
				os << "$    "; // pentagons
			}else if(i==4){
				os << "|XX|    "; // middle
			}else{
				os << "|    "; // everything else
			}
	  }else{
			if(sheet.blueRow[i]>9){ // for styling
				if(i==8){
					os << "$ "<< sheet.blueRow[i] << " $"; // last
				}else if(i==2 or i==3){
					os << "$ "<< sheet.blueRow[i] <<" "; // pentagons
				}else if(i==4){
					os << "|XX| "<< sheet.blueRow[i] <<" "; // middle
				}else{
					os << "| "<< sheet.blueRow[i] <<" "; // everything else
				}
			}else{
				if(i==8){
					os << "$ "<< sheet.blueRow[i] << "  $"; // last
				}else if(i==2 or i==3){
					os << "$ "<< sheet.blueRow[i] <<"  "; // pentagons
				}else if(i==4){
					os << "|XX| "<< sheet.blueRow[i] <<"  "; // middle
				}else{
					os << "| "<< sheet.blueRow[i] <<"  "; // everything else
				}
			}
		}

	}
	os << "\n";
	os << "\t------------------------------------------------- ";
	return os;
}
