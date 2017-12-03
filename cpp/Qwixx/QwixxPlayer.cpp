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
    else if(input == "red")
      if(scoreSheet.score(_rollOfDice,Dice::Color::red,int(_rollOfDice)))
          validSelection = true;
    else if(input == "yellow")
      if(scoreSheet.score(_rollOfDice,Dice::Color::yellow,int(_rollOfDice)))
        validSelection = true;
    else if(input == "green")
      if(scoreSheet.score(_rollOfDice,Dice::Color::green,int(_rollOfDice)))
        validSelection = true;
    else if(input == "blue")
      if(scoreSheet.score(_rollOfDice,Dice::Color::blue,int(_rollOfDice)))
        validSelection = true;
    else
      cout<<name<<", THAT WAS IN INVALID SELECTION!"<<endl<<endl;
  }

}
