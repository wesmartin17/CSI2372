#include "RollOfDice.cpp"
#include <string>

class Player{

  private:
    // ScoreSheet scoreSheet;
    string name;
    bool active;

  public:
    Player(string _name){name = _name;};
    virtual void inputBeforeRoll(RollOfDice &_rollOfDice);
    //virtual void inputAfterRoll(RollOfDice &_rollOfDice);
//    ~Player();

};
