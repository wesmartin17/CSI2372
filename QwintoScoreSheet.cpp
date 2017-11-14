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

void QwintoScoreSheet::initRows(){
  for(int i = 0; i<9; ++i){
    RollOfDice rd;
    redRow[i] = rd;
    yellowRow[i] = rd;
    blueRow[i] = rd;
  }
  Dice d2 = Dice(Dice::Color::red);
  redRow[1].dices.push_back(d2);
  redRow[1].roll();
}
