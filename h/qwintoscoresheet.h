#ifndef QWINTO_SS_
#define QWINTO_SS_

template<Color C>
class QwintoRow {

  public:
    RollOfDice values[9];
    RollOfDice& operator[] (const int index);
};

template<Color C>
RollOfDice& QwintoRow<C>::operator[] (int index){
  return values[index];
}

class QwintoScoreSheet : public ScoreSheet<QwintoScoreSheet>{

  public:
    QwintoRow<red> redRow;
    QwintoRow<yellow> yellowRow;
    QwintoRow<blue> blueRow;
    QwintoScoreSheet(string _playerName) : ScoreSheet(_playerName) { };

};

#include "../cpp/QwintoScoreSheet.cpp"
#endif
