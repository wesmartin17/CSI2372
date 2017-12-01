#include "../h/qwintoplayer.h"

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
    cout<<"\nRolling: "<<endl;
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

  bool hasRed = false, hasBlue = false, hasYellow = false;

  for(std::vector<Dice>::iterator i = _rollOfDice.dices.begin(); i != _rollOfDice.dices.end(); ++i){
    Dice d = *i;
    switch(d.diceColor){
      case Dice::Color::red :
        hasRed = true;
        break;
      case Dice::Color::blue :
        hasBlue = true;
        break;
      case Dice::Color::yellow :
        hasYellow = true;
        break;
    }
  }

  QwintoPlayer *qp = dynamic_cast<QwintoPlayer*>(this); // can be used like this : qp->scoreSheet.score(~~~)

  cout<<name<<", please select the row color and the column number (between 1 and 9) where you would like to place ["<< _rollOfDice << "] in.\nType \"done\" when finished\n";
  cout<<"(e.g. red 3 done)"<< endl;
  if(!active){
    cout <<"NOTE: You can type \"pass\" to skip with no penalty ";
    cout << "(e.g. pass done):" << endl;
  }
  if(active){
    cout<<"NOTE: You can type \"fail\" to mark a failed throw ";
    cout << "(e.g. fail done):" << endl;
  }
  vector<string> selection;
  vector<string>::iterator it;
  string input = "";

  bool enteredValid=false;

  cin.ignore();
  while(!enteredValid){
    input = "";
    while(input != "done"){
      cin >> input;
      if(input == "pass" && active == false){
        enteredValid = true;
      }
      if(input == "fail" && active == true){
        qp->scoreSheet.failedAttempts.push_back(_rollOfDice); // failed throw
        enteredValid = true;
      }
      selection.push_back(input);
    }

    if(selection.size() >= 3){
      stringstream asdf(selection.end()[-2]);
      int x = 0;
      asdf >> x;

      //cout<<"end-2: "<<selection.end()[-2]<<" end-1: "<<selection.end()[-1];
      if(selection.end()[-3] == "red" && hasRed){
        if(qp->scoreSheet.score(_rollOfDice,Dice::Color::red,x-1))
          enteredValid = true;
      }
      else if(selection.end()[-3] == "blue" && hasBlue){
        if(qp->scoreSheet.score(_rollOfDice,Dice::Color::blue,x-1))
          enteredValid = true;
      }
      else if(selection.end()[-3] == "yellow" && hasYellow){
        if(qp->scoreSheet.score(_rollOfDice,Dice::Color::yellow,x-1))
          enteredValid = true;
        else{
          cout<<"invalid entry"<<endl;
          input = "";
          selection.clear();
        }
      }

      if(!enteredValid){
        input = "";
        cout<<endl<<name<<", THAT WAS AN INVALID SELECTION.\n"<<qp->scoreSheet<<endl;
        cout<<endl<<name<<"Now please select the row color and the column number (between 1 and 9) where you would like to place ["<< _rollOfDice << "] in.\nType \"done\" when finished\n";
        cout<<"(e.g. red 3 done)"<< endl;
        if(!active){
          cout <<"NOTE: You can type \"pass\" to skip with no penalty ";
          cout << "(e.g. pass done):" << endl;
        }
        if(active){
          cout<<"NOTE: You can type \"fail\" to mark a failed throw ";
          cout << "(e.g. fail done):" << endl;
        }
        cout<<endl;
        selection.clear();
      }

    }
    else{
      // cout<<"invalid entry"<<endl;
      input = "";
      selection.clear();
    }
  }

}