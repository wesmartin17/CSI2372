void QwixxPlayer::inputBeforeRoll(RollOfDice &_rollOfDice){

  bool validSelection = false;
  vector<string> selection;

  while(!validSelection){
      selection.clear();

    cout<<"Please enter the color and column you would like to enter the white dice [placeholder whitedice] in.";
    if(!active)
      cout<<"(Or you can pass)"<<endl;
    else
      cout<<"(Or you can fail)"<<endl;

    string input = "";
    while (input != "done"){
      cin>>input;
      if(input == "pass" && !active){
        validSelection = true;
      }
      else if (input == "fail" && active){
        selection.push_back(input);
        scoreSheet.failedAttempts.push_back(_rollOfDice);
        validSelection = true;
      }

    }

    if(selection.size() >=3){
      stringstream asdf(selection.end()[-2]);
      int x = -1;
      asdf >> x;

      if(x > 0){
        // switch(selection.end()[-3]){
        //   case("red"):
        //     if(qp->scoreSheet.score(_rollOfDice,Dice::Color::red,x))
        //       validSelection = true;
        //       break;
        //     /* ENTER IN THE REST!*/
        // }
      }

    }

    if(!validSelection){
      cout<<name<<", THAT WAS IN INVALID SELECTION!"<<endl<<endl;
    }

  }


}
