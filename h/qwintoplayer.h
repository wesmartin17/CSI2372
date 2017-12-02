#ifndef QWINTO_P_
#define QWINTO_P_

class QwintoPlayer : public Player{

  public:
    QwintoScoreSheet scoreSheet;
    QwintoPlayer(string _name, QwintoScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};
};

#include "../cpp/QwintoPlayer.cpp"
#endif
