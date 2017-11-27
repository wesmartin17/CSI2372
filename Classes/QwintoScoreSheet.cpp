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
	}else{
		for(int i=0; i<pos; ++i){
			if(int(row[i]) > int(rollOfdice)){
				std::cout << "Invalid input: #" << pos
									<< ":\nCell #" << i << " is right of " << pos << " and holds value [" << int(row[i]) << "], large than your current roll" << endl;
				return false;
			}
		}
	}
	row[pos] = rollOfdice;
	return true;
	}


template <class QwintoScoreSheet>
std::ostream& ScoreSheet<QwintoScoreSheet>::print(std::ostream& os, QwintoScoreSheet & sheet){
	//---- PRINTS RED ROW -----//
	os << "\nRed\t     ";
	for(int i=0; i<9; ++i){
	  if(sheet.redRow[i] == 0){
	    if(i == 1 or i == 3 or i == 4){ // pentagons
	      os << "  $ ";
	    }else if(i == 2){ //middle space
	      os << "  $   |XX| ";
	    }else{
	      os << "  | ";
	    }
	  }else{
	    if(sheet.redRow[i]>9){ // just for styling
	      os << "  " << sheet.redRow[i];
	    }else{
	      os << "   " << sheet.redRow[i];
	    }
	  }
	}
	os << "\n";
	//---- PRINTS YELLOW ROW -----//
	os << "\t   -------------------------------------------- " << "\n";
	os << "Yellow   ";
	for(int i=0; i<9; ++i){
	  if(sheet.yellowRow[i] == 0){
	    if(i == 5 or i == 6){ // pentagons
	      os << "  $ ";
	    }else if(i == 4){ //middle space
	      os << "  |   |XX| ";
	    }else{
	      os << "  | ";
	    }
	  }else{
	    if(sheet.yellowRow[i]>9){ // just for styling
	      os << "  " << sheet.yellowRow[i];
	    }else{
	      os << "   " << sheet.yellowRow[i];
	    }
	  }
	}
	os << "\n";
	//---- PRINTS BLUE ROW -----//
	os << "      ---------------------------------------------- " << "\n";
	os << "Blue ";
	for(int i=0; i<9; ++i){
	  if(sheet.blueRow[i] == 0){
	    if(i == 2 or i == 7 or i == 8){ // pentagons
	      os << "  $ ";
	    }else if(i == 3){ //middle space
	      os << "  $   |XX| ";
	    }else{
	      os << "  | ";
	    }
	  }else{
	    if(sheet.blueRow[i]>9){ // just for styling
	      os << "  " << sheet.blueRow[i];
	    }else{
	      os << "   " << sheet.blueRow[i];
	    }
	  }
	}
	os << "\n";
	os << "      ------------------------------------------ " << "\n";
return os;
}
