void QwixxPlayer::inputBeforeRoll(RollOfDice &_rollOfDice){

  bool validSelection = false;

  while(!validSelection){
    cout<<name<<", Please enter the color you would like to enter the white dice ["<<int(_rollOfDice)<<"] in.";

    cout<<"(Or you can pass)"<<endl;

    string input = "";
    cin>>input;

    if(input == "pass"){
      validSelection = true;
    }

    if(input == "red"){
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
    if(!validSelection)
      cout<<name<<", THAT WAS IN INVALID SELECTION!"<<endl<<endl;
  }

}


void QwixxPlayer::inputAfterRoll(RollOfDice &_rollOfDice){
  bool validSelection = false, scored = false, failed = false;
  string input, color;
  int selectedColorDice;
  while(!scored){
    cout<<name<<", Please enter the name of the colored dice you would like to score (or type fail): "<<endl;

    validSelection = false;
    while(!validSelection){
      input = "";
      cin >> input;
      if(input =="fail"){
        scoreSheet.failedAttempts.push_back(_rollOfDice);
        validSelection = true;
        failed = true;
        scored = true;
      }
      if(input == "red"){
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
      if(!validSelection){
        cout<<"INVALID SELECTION! (please type one of: red yellow green blue)";
      }

    }
      validSelection = false;
    if(!failed){
      int selection = 0;
      while(!validSelection){
        input = "";
        cout << "Please enter 1 for white dice [" << _rollOfDice.dices[0].face <<"] or enter 2 for white dice ["<< _rollOfDice.dices[1].face<<"]"<<endl;
        cin >> input;
        stringstream asdf(input);
        if(asdf>>selection && (selection == 1 || selection == 2))
          validSelection = true;
      }

      validSelection = false;

      RollOfDice pair = _rollOfDice.pair(_rollOfDice.dices[selection-1],_rollOfDice.dices[selectedColorDice+2]);
      Color c = static_cast<Color>(selectedColorDice);

      input = "";
        cout<<"Type \"yes\" to confirm your move of "<<color<<", "<<int(pair)<<endl;
        cin>> input;
        if(input == "yes"){
          if(scoreSheet.score(pair,c)){
            scored = true;
          }
          else{
            cout<<"That is an invalid move"<<endl;
          }
        }
    }
  }

}
