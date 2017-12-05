#ifndef QWIXX_SS_
#define QWIXX_SS_
#include "qwixxrow.h"


class QwixxScoreSheet : public ScoreSheet<QwixxScoreSheet>{

  public:
    QwixxRow<vector<RollOfDice>, red> redRow;
    QwixxRow<vector<RollOfDice>, yellow> yellowRow;
    QwixxRow<list<RollOfDice>, green> greenRow;
    QwixxRow<list<RollOfDice>, blue> blueRow;
    QwixxScoreSheet(string _playerName) : ScoreSheet(_playerName){ };
    bool score(RollOfDice &rollOfdice, Color color, int pos=-1);
    bool notOperator();
    int setTotal();
    int calcTotal();
    ostream& operator<<(ostream& os);

};

#include "../../cpp/Qwixx/QwixxScoreSheet.cpp"
#endif
