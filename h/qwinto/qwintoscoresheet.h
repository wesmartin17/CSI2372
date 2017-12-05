#ifndef QWINTO_SS_
#define QWINTO_SS_
#include "qwintorow.h"

class QwintoScoreSheet : public ScoreSheet<QwintoScoreSheet>{

  public:
    QwintoRow<Color::red> redRow;
    QwintoRow<Color::yellow> yellowRow;
    QwintoRow<Color::blue> blueRow;
    QwintoScoreSheet(string _playerName) : ScoreSheet(_playerName) { };
    bool score(RollOfDice &rollOfdice, Color color, int pos=-1);
    bool notOperator();
    bool twoRows();
    int setTotal();
    int calcTotal();
    bool operator!();
    ostream& operator<<(ostream& os);

};

#include "../../cpp/Qwinto/QwintoScoreSheet.cpp"
#endif
