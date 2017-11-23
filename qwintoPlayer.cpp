#include "qwintoPlayer.h"

QwintoPlayer(string _name) : Player(string _name){}


void inputBeforeRoll(RollOfDice &_rollOfDice){
  string tmp = "";
  vector<string> refinedSelection;
  while(tmp != "yes"){
    cout<<"Please select the dice you would like to roll: (type \"done\" when finished): "<<endl;
    vector<string> selection;
    vector<string>::iterator it;
    string input = "";

    while(input != "done"){
      cin >> input;
      selection.push_back(input);
    }


    vector<string> refinedSelection;
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
      cout<<" "<<*i<<endl;

    }

    cin>>tmp;
  }

  for(vector<string>::iterator i = refinedSelection.begin(); i != refinedSelection.end(); i++){

    if(*i == "red"){
      Dice d(Dice::Color::red);
      //not sure how to add it to rollofdice
    }

    if(*i == "blue"){
      Dice d(Dice::Color::blue);
      //not sure how to add it to rollofdice
    }
    if(*i == "yellow"){
      Dice d(Dice::Color::yellow);
      //not sure how to add it to rollofdice
    }

  }

}
