#include "QwintoScoreSheet.h"
#include "stdio.h"

std::ostream& operator<<(std::ostream& os,  QwintoScoreSheet & sheet){
	os << "Player name: " << sheet.getPlayerName() << "\n";
  os << "\t  ----------------------------------------- " << "\n";
  os << "Red\t";
  for(int i=0; i<9; ++i){
    if(sheet.getRedRowRD(i) == 0){
      if(i == 1 or i == 3 or i == 4){ // Pentagons
        os << "  $ ";
      }else if(i == 2){ //middle space
        os << "  $   |XX| ";
      }else{
        os << "  | ";
      }
    }else{
      if(sheet.getRedRowRD(i)>9){ // Just for styling
        os << "  " << sheet.getRedRowRD(i);
      }else{
        os << "   " << sheet.getRedRowRD(i);
      }
    }
  }

	return os;
}

///////////////////////
//// Row Getters //////
///////////////////////
int QwintoScoreSheet::getRedRowRD(int i){
  int value = int(redRow[i]);
  return value;
}
