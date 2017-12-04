#ifndef PLAYER_
#define PLAYER_
#include "scoresheet.h"


class Player{

  public:
    string name;
    bool active;
    Player(string _name){name = _name;};
    virtual void inputBeforeRoll(RollOfDice &_rollOfDice) = 0;
    virtual void inputAfterRoll(RollOfDice &_rollOfDice) = 0;
    // virtual ~Player()=0;
};

#include "qwintoplayer.h"
#include "qwixxplayer.h"
#endif
