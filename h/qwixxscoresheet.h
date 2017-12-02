#ifndef QWIXX_SS_
#define QWIXX_SS_
#include "scoresheet.h"


using namespace std;

template<Color C>
class QwixxRow{

  public:
    RollOfDice values[11];
    RollOfDice& operator[] (const int index);

};

template<Color C>
RollOfDice& QwixxRow<C>::operator[](int index){
  return values[index];
}

class QwixxScoreSheet : public ScoreSheet<QwixxScoreSheet>{

  public:
    QwixxRow<red> redRow;
    QwixxRow<yellow> yellowRow;
    QwixxRow<green> greenRow;
    QwixxRow<blue> blueRow;
    QwixxScoreSheet(string _playerName) : ScoreSheet(_playerName){ };
};

// TODO #include "../cpp/QwixxScoreSheet.cpp"
#endif
