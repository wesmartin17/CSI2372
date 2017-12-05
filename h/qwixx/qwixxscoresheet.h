#ifndef QWIXX_SS_
#define QWIXX_SS_
#include "qwixxrow.h"


class QwixxScoreSheet : public ScoreSheet<QwixxScoreSheet>{

  public:
    QwixxRow<red> redRow;
    QwixxRow<yellow> yellowRow;
    QwixxRow<green> greenRow;
    QwixxRow<blue> blueRow;
    QwixxScoreSheet(string _playerName) : ScoreSheet(_playerName){ };
    bool score(RollOfDice &rollOfdice, Color color, int pos=-1);
    bool twoRows();
    bool notOperator();
    int setTotal();
    int calcTotal();
    ostream& operator<<(ostream& os);

};

#include "../../cpp/Qwixx/QwixxScoreSheet.cpp"
#endif
