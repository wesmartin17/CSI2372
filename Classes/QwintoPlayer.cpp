#include "../headers/QwintoPlayer.h"

void Player::inputBeforeRoll(RollOfDice &_rollOfDice){
  string tmp = "";
  vector<string> refinedSelection;
  while(tmp!="yes"){
    refinedSelection.clear();
    cout<<"Please select the dice you would like to roll: (type \"done\" when finished): "<<endl;
    vector<string> selection;
    vector<string>::iterator it;
    string input = "";

    while(input != "done"){
      cin >> input;
      selection.push_back(input);
    }

    for(it = selection.begin();it<selection.end();it++){
      if(*it == "blue" || *it == "b")
        refinedSelection.push_back("blue");
      else if(*it == "red" || *it == "r")
        refinedSelection.push_back("red");
      else if(*it == "yellow" || *it == "y")
        refinedSelection.push_back("yellow");
    }

    cout<<"type \"yes\" to confirm roll of: "<<endl;
    for(vector<string>::iterator i = refinedSelection.begin(); i!= refinedSelection.end(); i++ ){
      cout<<*i<<endl;

    }

    cin>>tmp;
  }

  if(std::find(refinedSelection.begin(), refinedSelection.end(), "red") != refinedSelection.end()) {
    Dice d1 = Dice(Dice::Color::red);
    _rollOfDice.dices.push_back(d1);
  }

  if(std::find(refinedSelection.begin(), refinedSelection.end(), "yellow") != refinedSelection.end()) {
    Dice d2 = Dice(Dice::Color::yellow);
    _rollOfDice.dices.push_back(d2);
  }

  if(std::find(refinedSelection.begin(), refinedSelection.end(), "blue") != refinedSelection.end()) {
    Dice d3 = Dice(Dice::Color::blue);
    _rollOfDice.dices.push_back(d3);
  }

}


void Player::inputAfterRoll(RollOfDice &_rollOfDice){
  
}
