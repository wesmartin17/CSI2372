bool QwixxScoreSheet::score(RollOfDice &rd, Color C, int pos){

	string color;
	RollOfDice* row;
	int realpos = 0;
	switch (C) {
    case red : realpos = int(rd) - 2; color = "red"; row = redRow.values; break;
		case yellow : realpos = int(rd) - 2; color = "yellow";row = yellowRow.values; break;
    case green : realpos = 12 - int(rd); color = "green"; row = greenRow.values; break;
    case blue : realpos = 12 - int(rd); color = "blue"; row = blueRow.values; break;
  }

	// Passed dice colors dont include 1x C dice
  if((rd.dices[0].diceColor != C) and (rd.dices[1].diceColor != C) and (rd.dices[0].diceColor != Color::white or rd.dices[1].diceColor != Color::white)){
		 cout << "Dice are missing a die of the requested row color!" << endl;
		 return false;
	}


  // Passed dice colors dont include at least 1x white
  if(rd.dices[0].diceColor != Color::white and rd.dices[1].diceColor != Color::white){
		cout << "Dice are missing a least one white dice!" << endl;
		return false;
	}

	// Passed dice is to be scored left of the right-most score
	for(int i=0; i < 11; ++i){
		if(row[i].dices.size() != 0){
			if(realpos < i){
				cout << "Dice combo can't be scored to the left of the right-most score!" << endl;
				return false;
			}
		}
	}

	// Passed dice is to be scored in a scored cell
	if(int(row[realpos]) != 0){
		cout << "This position is taken" << endl;
		return false;
	}

  // Passed dice is to be scored in a locked row
  if(int(row[11]) != 0){
		cout << "Dice combo can't be scored in a locked row!" << endl;
		return false;
  }

	try{

		switch (C) {
			case red : redRow += rd; break;
			case yellow : yellowRow += rd; break;
			case green : greenRow += rd; break;
			case blue : blueRow += rd; break;
		}
	}catch(exception& e){
		cout << e.what() << '\n';
		return false;
	}

	return true;

}



ostream& QwixxScoreSheet::operator<<(ostream& os){

	redRow << os;
	yellowRow << os;
	greenRow << os;
	blueRow << os;
	os << "\n\t----------------------------------------------------------- ";

	if(failedAttempts.size() > 0){
		os << "\nFailed throws: ";
		for(int i = 0; i<failedAttempts.size(); ++i){
			os << "["<< int(failedAttempts[i]) << "], ";
		}
	}
	os << "\n"<<endl;
	return os;
}


int QwixxScoreSheet::calcTotal(){
	int total = 0;
	// Red score
	for(int i=0; i<12; ++i){
		if(int(redRow.values[i]) != 0){
			total += redRow.values[i];
		}
	}

	// Yellow score
	for(int i=0; i<12; ++i){
		if(int(yellowRow.values[i]) != 0){
			total += yellowRow.values[i];
		}
	}

	// Green score
	for(int i=0; i<12; ++i){
		if(int(greenRow.values[i]) != 0){
			total += greenRow.values[i];
		}
	}

	// blue score
	for(int i=0; i<12; ++i){
		if(int(blueRow.values[i]) != 0){
			total += blueRow.values[i];
		}
	}

	// Failed attempts
	total -= (failedAttempts.size()*5);

	return total;
}


int QwixxScoreSheet::setTotal(){

	int total = calcTotal();
	this->totalScore = total;
	return total;
}


bool QwixxScoreSheet::operator!(){

	// Two locked rows
	int locked = 0;
	if(int(redRow.values[11]) != 0)
		locked += 1;
	if(int(yellowRow.values[11]) != 0)
		locked += 1;
	if(int(greenRow.values[11]) != 0)
		locked += 1;
	if(int(blueRow.values[11]) != 0)
		locked += 1;

	if(locked==2){
		cout << "\nThis was your second row to get locked" << endl;
		return true;
	}

	if(failedAttempts.size() >= 4){
		cout << "\nThis was your fourth and last failed throw :(" << endl;
		return true;
	}
	return false;
}
