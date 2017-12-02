#ifndef QWIXX_SS_
#define QWIXX_SS_
#include "scoresheet.h"

enum Color {red, yellow, green, blue, white, };

using namespace std;

template<Color C>
class QwixxRow{

  public:
    RollOfDice[11];
    RollOfDice& operator[] (const int index);

};

template<Color C>
RollofDice& QwixxRow<C>::operator[](int index){
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
#endif
