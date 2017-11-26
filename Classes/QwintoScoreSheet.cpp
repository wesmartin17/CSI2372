#include "../headers/QwintoScoreSheet.h"
#include "stdio.h"

template <class QwintoScoreSheet>
bool ScoreSheet<QwintoScoreSheet>::score(RollOfDice &rollOfdice, Dice::Color color, int pos){


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
