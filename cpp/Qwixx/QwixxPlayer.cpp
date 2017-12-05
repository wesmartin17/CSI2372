void QwixxPlayer::inputBeforeRoll(RollOfDice &_rollOfDice){

  bool validSelection = false;

  cout<<name<<", Please enter the color you would like to enter the white dice ["<<int(_rollOfDice)<<"] in.";
  if(!active)
    cout<<"(Or you can pass)"<<endl;
  else
    cout<<"(Or you can fail)"<<endl;

  while(!validSelection){
  string input = "";
    cin>>input;
    if(input == "pass" && !active){
      validSelection = true;
    }
    else if (input == "fail" && active){
      scoreSheet.failedAttempts.push_back(_rollOfDice);
      validSelection = true;
    }
    else if(input == "red"){
      if(scoreSheet.score(_rollOfDice,Color::red)){
          validSelection = true;
      }
    }
    else if(input == "yellow"){
      if(scoreSheet.score(_rollOfDice,Color::yellow)){
        validSelection = true;
      }
    }
    else if(input == "green"){
      if(scoreSheet.score(_rollOfDice,Color::green)){
        validSelection = true;
      }
    }
    else if(input == "blue"){
      if(scoreSheet.score(_rollOfDice,Color::blue)){
        validSelection = true;
      }
    }
    else
      cout<<name<<", THAT WAS IN INVALID SELECTION!"<<endl<<endl;
  }

}


void QwixxPlayer::inputAfterRoll(RollOfDice &_rollOfDice){
  cout<<name<<", Please enter the name of the colored dice you would like to score (or type fail): "<<endl;
  bool validSelection = false, scored = false;
  string input, color;
  int selectedColorDice;
  while(!scored){
    while(!validSelection){
      input = "";
      cin >> input;
      if(input =="fail"){
        //TODO score a fail
        validSelection = true;
      }
      else if(input == "red"){
        selectedColorDice = 0;
        validSelection = true;
        color = input;
      }
      else if(input == "yellow"){
        selectedColorDice = 1;
        validSelection = true;
        color = input;
      }
      else if(input == "green"){
        selectedColorDice = 2;
        validSelection = true;
        color = input;
      }
      else if(input == "blue"){
        selectedColorDice = 3;
        validSelection = true;
        color = input;
      }
      else{
        cout<<"INVALID SELECTION! (please type one of: red yellow green blue)";
      }

    }

    validSelection = false;

    int selection = 0;
    while(!validSelection){
      input = "";
      cout << "Please enter 1 for white dice [" << _rollOfDice.dices[0].face <<"] or enter 2 for white dice ["<< _rollOfDice.dices[1].face << endl;
      cin >> input;
      stringstream asdf(input);
      if(asdf>>selection && (selection == 1 || selection == 2))
        validSelection = true;
    }

    RollOfDice pair = _rollOfDice.pair(_rollOfDice.dices[selection-1],_rollOfDice.dices[selectedColorDice+2]);
    Color c = static_cast<Color>(selectedColorDice);

    input = "";
      cout<<"Type \"yes\" to confirm your move of "<<color<<", "<<int(pair);
      cin>> input;
      if(input == "yes")
        if(scoreSheet.score(pair,c))
          scored = true;
  }

}
