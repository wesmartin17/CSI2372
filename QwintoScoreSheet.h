#ifndef QWINTO_SS_
#define QWINTO_SS_

#include "ScoreSheet.h"
#include "QwintoRow.cpp"

class QwintoScoreSheet : public ScoreSheet{

  private:
    QwintoRow<red> redRow;
    QwintoRow<yellow> yellowRow;
    QwintoRow<blue> blueRow;

  public:
    QwintoScoreSheet(string _playerName);

};

#endif
