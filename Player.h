#include <string>

class Player{
  private:
    string name;
    bool active;

  public:
    Player(string _name, bool _active=false);
    void inputBeforeRoll(RollOfDice &_rollOfDice);
    void inputAfterRoll(RollOfDice &_rollOfDice);

};
