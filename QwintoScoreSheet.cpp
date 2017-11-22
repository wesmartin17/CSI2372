#include "QwintoScoreSheet.h"
#include "stdio.h"

std::ostream& operator<<(std::ostream& os,  QwintoScoreSheet & sheet){
	// os << "Player name: " << sheet.getPlayerName() << "\n";
  // os << "\t       ---------------------------------------- " << "\n";

  //---- PRINTS RED ROW -----//
  os << "Red\t     ";
  for(int i=0; i<9; ++i){
    if(sheet.getRedRowRD(i) == 0){
      if(i == 1 or i == 3 or i == 4){ // pentagons
        os << "  $ ";
      }else if(i == 2){ //middle space
        os << "  $   |XX| ";
      }else{
        os << "  | ";
      }
    }else{
      if(sheet.getRedRowRD(i)>9){ // just for styling
        os << "  " << sheet.getRedRowRD(i);
      }else{
        os << "   " << sheet.getRedRowRD(i);
      }
    }
  }
  os << "\n";
  //---- PRINTS YELLOW ROW -----//
  os << "\t   -------------------------------------------- " << "\n";
  os << "Yellow   ";
  for(int i=0; i<9; ++i){
    if(sheet.getYellowRowRD(i) == 0){
      if(i == 5 or i == 6){ // pentagons
        os << "  $ ";
      }else if(i == 4){ //middle space
        os << "  |   |XX| ";
      }else{
        os << "  | ";
      }
    }else{
      if(sheet.getYellowRowRD(i)>9){ // just for styling
        os << "  " << sheet.getYellowRowRD(i);
      }else{
        os << "   " << sheet.getYellowRowRD(i);
      }
    }
  }
  os << "\n";
  //---- PRINTS BLUE ROW -----//
  os << "      ---------------------------------------------- " << "\n";
  os << "Blue ";
  for(int i=0; i<9; ++i){
    if(sheet.getBlueRowRD(i) == 0){
      if(i == 2 or i == 7 or i == 8){ // pentagons
        os << "  $ ";
      }else if(i == 3){ //middle space
        os << "  $   |XX| ";
      }else{
        os << "  | ";
      }
    }else{
      if(sheet.getBlueRowRD(i)>9){ // just for styling
        os << "  " << sheet.getBlueRowRD(i);
      }else{
        os << "   " << sheet.getBlueRowRD(i);
      }
    }
  }
  os << "\n";
  os << "      ------------------------------------------ " << "\n";
  //---- Return ----//
	return os;
}

///////////////////////
//// Row Getters //////
///////////////////////
int QwintoScoreSheet::getRedRowRD(int i){
  int value = int(redRow[i]);
  return value;
}

int QwintoScoreSheet::getYellowRowRD(int i){
  int value = int(yellowRow[i]);
  return value;
}

int QwintoScoreSheet::getBlueRowRD(int i){
  int value = int(yellowRow[i]);
  return value;
}
