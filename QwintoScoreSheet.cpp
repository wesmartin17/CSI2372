#include "QwintoScoreSheet.h"
#include "stdio.h"

std::ostream& operator<<(std::ostream& os,  QwintoScoreSheet & sheet){
	os << "Player name: " << sheet.getPlayerName() << "\n";
  
	return os;
}
