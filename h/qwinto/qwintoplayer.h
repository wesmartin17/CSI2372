#ifndef QWINTO_P_
#define QWINTO_P_

class QwintoPlayer : public Player{

  public:
    QwintoScoreSheet scoreSheet;
    QwintoPlayer(string _name, QwintoScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};
    void inputBeforeRoll(RollOfDice &_rollOfDice);
    void inputAfterRoll(RollOfDice &_rollOfDice);

};

#include "../../cpp/Qwinto/QwintoPlayer.cpp"
#endif
