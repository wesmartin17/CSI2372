bool QwixxScoreSheet::score(RollOfDice &rollOfdice, Color color, int pos){

	RollOfDice* row;
	int temp = int(rollOfdice);

	int realpos = 0;
	switch (color) {
		case Color::red:{
			row = redRow.values;
			realpos = temp - 2; // 2 thourgh 12
			break;
		}
		case Color::yellow:{
			row = yellowRow.values;
			realpos = temp - 2; // 2 through 12
			break;
		}
		case Color::green:{
			row = greenRow.values;
			realpos = 12 - temp; // 12 through 2
			break;
		}
		case Color::blue:{
			row = blueRow.values;
			realpos = 12 - temp; // 12 through 2
			break;
		}
	}



	// out of range
	if(realpos > 11 or realpos < 0){
		cout << "Invalid input: #" << pos
							<< ":\nYou must select location cell number between 2 and 11" << endl;
		return false;
	}
	// taken
	if(int(row[realpos]) != 0){
		cout << "Invalid input: #" << pos
							<< ":\nCell #" << pos << " has been scored already" << endl;
		return false;
	}

	// left of double-white-dice score
	for(int i=0; i<=realpos; ++i){
		int whiteCount = 0;
		for(vector<Dice>::iterator it = row[realpos].dices.begin(); it != row[realpos].dices.end(); ++it){
			if(it->diceColor == Color::white){
				whiteCount++;
			}
		}
		if(whiteCount>1){
			cout << "Invalid input: #" << int(rollOfdice)
				   << ":\nA cell in this row is right of cell #" << rollOfdice << " and holds a score by two white dice";
			return false;
		}
	}

	// locked row
	if(row[12]!=0){
		cout << "Invalid input: #" << int(rollOfdice)
				<< "This row is locked because it contains 5 scores already";
		return false;
	}

	// GOOD TO SCORE
	row[realpos] = rollOfdice;

	// check if should lock row
	int rowCount = 0;
	for(int i=0; i<12; ++i){
		if(row[i]!=0){
			rowCount++;
		}
	}
	if(rowCount==5){
		row[12] = rollOfdice;
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
			os << failedAttempts[i] << " ";
		}
	}
	os << "\n";
	return os;
}


int QwixxScoreSheet::calcTotal(){
  // TODO implement calcTotal

	int total = 0;
	return total;
}


int QwixxScoreSheet::setTotal(){

	int total = calcTotal();
	this->totalScore = total;
	return total;
}


bool QwixxScoreSheet::notOperator(){

	if(failedAttempts.size() >= 4){
		cout << "\nThis was your fourth and last failed throw :(" << endl;
		return true;
	}
  // TODO finish notOperator
	return false;
}


bool QwixxScoreSheet::twoRows(){

	//TODO implement twoRoes
	int zeroes = 0;
	for(int i=0; i<9; i++){
		if(redRow[i]==0){
			zeroes += 1;
		}
	}

	for(int i=0; i<9; i++){
		if(yellowRow[i]==0){
			zeroes += 1;
		}
	}

	for(int i=0; i<9; i++){
		if(blueRow[i]==0){
			zeroes += 1;
		}
	}

	return zeroes<=1;
}
