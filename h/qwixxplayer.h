#ifndef QWIXX_P_
#define QWIXX_P_

class QwixxPlayer : public Player{

  public:
    QwixxScoreSheet scoreSheet;
    QwixxPlayer(string _name, QwixxScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};
};

// TODO #include "../cpp/QwixxPlayer.cpp"
#endif
