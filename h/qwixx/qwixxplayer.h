#ifndef QWIXX_P_
#define QWIXX_P_

class QwixxPlayer : public Player{

  public:
    QwixxScoreSheet scoreSheet;
    QwixxPlayer(string _name, QwixxScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};
    void inputBeforeRoll(RollOfDice &_rollOfDice);
    void inputAfterRoll(RollOfDice &_rollOfDice);

};

#include "../../cpp/Qwixx/QwixxPlayer.cpp"
#endif
