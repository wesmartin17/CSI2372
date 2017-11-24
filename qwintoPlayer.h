#include "QwintoScoreSheet.cpp"
#include "Player.h"


class QwintoPlayer : public Player{

  protected:
    QwintoScoreSheet scoreSheet;

  public:
    QwintoPlayer(string _name, QwintoScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};

};
