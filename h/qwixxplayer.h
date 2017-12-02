#ifndef QWIXX_P_
#define QWIXX_PP_
#include "../cpp/QwintoScoreSheet.cpp"
#include "Player.h"

class QwixxPlayer : public Player{

  public:
    QwixxScoreSheet scoreSheet;
    QwixxPlayer(string _name, QwixxScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};
};

#endif
