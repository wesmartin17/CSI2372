#ifndef PLAYER_
#define PLAYER_
#include "../cpp/RollOfDice.cpp"

class Player{

  private:
    string name;

  public:
    bool active;
    Player(string _name){name = _name;};
    virtual void inputBeforeRoll(RollOfDice &_rollOfDice);
    virtual void inputAfterRoll(RollOfDice &_rollOfDice);
    // virtual ~Player()=0;
};

#endif
