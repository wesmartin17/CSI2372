#include "QwintoScoreSheet.h"
#include "stdio.h"
// #include "RollOfDice.cpp"

void QwintoScoreSheet::print(){

  std::cout << "Player name: " << playerName << endl;
  std::cout << "\t    -------------------------------" << endl;
  std::cout << "Red:\t   ";
  printf("| %s $ %d $ %s |XX| %s $ %s $ %s | %s | %s | %s |\n",
   redRow[0], int(redRow[1]), redRow[2], redRow[3], redRow[4], redRow[5], redRow[6],
   redRow[7], redRow[8]);

}
