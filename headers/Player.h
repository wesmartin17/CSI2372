#include "../Classes/RollOfDice.cpp"
#include <string>

class Player{

  private:
    string name;

  public:
    bool active;
    Player(string _name){name = _name;};
    virtual void inputBeforeRoll(RollOfDice &_rollOfDice);
    virtual void inputAfterRoll(RollOfDice &_rollOfDice);
   // ~Player();

};
