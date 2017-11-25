#include "QwintoScoreSheet.cpp"
#include "Player.h"


class QwintoPlayer : public Player{

  private:
    QwintoScoreSheet scoreSheet;

  public:
    QwintoPlayer(string _name, QwintoScoreSheet _scoreSheet) : Player(_name), scoreSheet(_scoreSheet){};
};
