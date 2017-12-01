#ifndef QWINTO_P_
#define QWINTO_PP_
#include "../cpp/QwintoScoreSheet.cpp"
#include "Player.h"

class QwintoPlayer : public Player{

  public:
    QwintoScoreSheet scoreSheet;
    QwintoPlayer(string _name, QwintoScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};
};

#endif
