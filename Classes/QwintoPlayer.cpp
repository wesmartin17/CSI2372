#include "../headers/QwintoPlayer.h"

void Player::inputBeforeRoll(RollOfDice &_rollOfDice){
  string tmp = "";
  vector<string> refinedSelection;
  while(tmp!="yes"){
    refinedSelection.clear();
    cout<<"Please select the dice you would like to roll, type \"done\" when finished: "<<endl;
    cout<<"(e.g. red blue yellow done):"<<endl;
    vector<string> selection;
    vector<string>::iterator it;
    string input = "";

    while(input != "done" || (input != "pass" && active == false)){
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
    cout<<"Rolling: "<<endl;
    for(vector<string>::iterator i = refinedSelection.begin(); i!= refinedSelection.end(); i++ ){
      cout<<"["<<*i<<"  dice]\n";
    }
    cout<<"type \"yes\" to confirm roll:"<<endl;

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
  QwintoPlayer *qp = dynamic_cast<QwintoPlayer*>(this); // can be used like this : qp->scorSheet.score(~~~)

  cout<<name<<", please select the row color and the column number you would like to place ["<< _rollOfDice << "] in, type \"done\" when finished";
  if(!active)
    cout<<"(You can also type \"pass\"):";
  cout<<endl;
  cout<<"(e.g. red 3 done):"<<endl;
  vector<string> selection;
  vector<string>::iterator it;
  string input = "";

  bool enteredValid=false;

  cin.ignore();
  while(!enteredValid){
    input = "";
    while(input != "done"){
      cin >> input;
      if(input == "pass")
        return;
      selection.push_back(input);
    }

    stringstream asdf(selection.end()[-2]);
    int x = 0;
    asdf >> x;

    //cout<<"end-2: "<<selection.end()[-2]<<" end-1: "<<selection.end()[-1];
    if(selection.end()[-3] == "red"){
      if(qp->scoreSheet.score(_rollOfDice,Dice::Color::red,x))
        enteredValid = true;
    }
    else if(selection.end()[-3] == "blue"){
        if(qp->scoreSheet.score(_rollOfDice,Dice::Color::red,x))
      enteredValid = true;
    }
    else if(selection.end()[-3] == "yellow"){
      if(qp->scoreSheet.score(_rollOfDice,Dice::Color::red,x))
        enteredValid = true;
    }
    else{
      cout<<"invalid entry";
      input = "";
    }
  }

}
