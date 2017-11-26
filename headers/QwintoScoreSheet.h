#ifndef QWINTO_SS_
#define QWINTO_SS_

#include "ScoreSheet.h"
#include "../Classes/QwintoRow.cpp"

class QwintoScoreSheet : public ScoreSheet<QwintoScoreSheet>{

  public:
    QwintoRow<red> redRow;
    QwintoRow<yellow> yellowRow;
    QwintoRow<blue> blueRow;
    QwintoScoreSheet(string _playerName) : ScoreSheet(_playerName) { };

};

#endif
