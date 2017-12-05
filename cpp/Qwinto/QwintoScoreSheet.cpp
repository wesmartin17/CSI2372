bool QwintoScoreSheet::score(RollOfDice &rollOfdice, Color color, int pos){

	RollOfDice* row;
	switch (color) {
		case Color::red: row = redRow.values; break;
		case Color::yellow: row = yellowRow.values; break;
		case Color::blue: row = blueRow.values; break;
	}
	if(pos > 8 or pos < 0){
		cout << "Invalid input: #" << pos
							<< ":\nYou must select location cell number between 1 and 9" << endl;
		return false;
	}else if(int(row[pos]) != 0){
		cout << "Invalid input: #" << pos
							<< ":\nCell #" << pos << " already has value " << int(row[pos]) << endl;
		return false;
	}
	for(int i=0; i<9; ++i){
		if((int(row[i]) <= int(rollOfdice)) and (row[i]!=0) and (pos<=i)){
			cout << "Invalid input: #" << pos
								<< ":\nCell #" << i << " is right of cell #" << pos << " and holds [" << int(row[i]) << "] \n"
								<< "["<<int(row[i])<<"] is <= "<< "["<<int(rollOfdice)<<"] "<< endl;
			return false;
		}
	}

	row[pos] = rollOfdice;
	return true;
	}


ostream& QwintoScoreSheet::operator<<(ostream& os){

	redRow << os;
	yellowRow << os;
	blueRow << os;
	os << "\n\t------------------------------------------------- ";

	if(failedAttempts.size() > 0){
		os << "\nFailed throws: ";
		for(int i = 0; i<failedAttempts.size(); ++i){
			os << failedAttempts[i] << " ";
		}
	}
	os << "\n";
	return os;
}


bool QwintoScoreSheet::twoRows(){

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


int QwintoScoreSheet::calcTotal(){

	int total = 0;

	int redZeroes = 0;
	int yellowZeroes = 0;
	int blueZeroes = 0;

	for(int i=0; i<9; i++){
		if(redRow[i]==0){
			redZeroes += 1;
		}
	}

	for(int i=0; i<9; i++){
		if(yellowRow[i]==0){
			yellowZeroes += 1;
		}
	}

	for(int i=0; i<9; i++){
		if(blueRow[i]==0){
			blueZeroes += 1;
		}
	}

	/*
		+ Right-most value for full rows
		+ 1 per non-zero for not full rows
	*/
	// Red
	if(redZeroes == 0){
		total += redRow[8];
	}else{
		total += (9 - redZeroes);
	}

	// Yellow
	if(yellowZeroes == 0){
		total += yellowRow[8];
	}else{
		total += (9 - yellowZeroes);
	}

	// Blue
	if(blueZeroes == 0){
		total += blueRow[8];
	}else{
		total += (9 - blueZeroes);
	}

	/*
		Pentagons: If column is full
		+ red: #1 and #4
		+ yellow: #6
		+ blue: #2 and #9
	*/
	// Red #1
	if(redRow[1]!=0 and yellowRow[2]!=0 and blueRow[3]!=0)
		total += redRow[1];

	// Red #4
	if(redRow[4]!=0 and yellowRow[5]!=0 and blueRow[6]!=0)
		total += redRow[4];

	// Yellow #6
	if(redRow[5]!=0 and yellowRow[6]!=0 and blueRow[7]!=0)
		total += yellowRow[6];

	// Blue #2
	if(redRow[0]!=0 and yellowRow[1]!=0 and blueRow[2]!=0)
		total += blueRow[2];

	// Blue #9
	if(redRow[6]!=0 and yellowRow[7]!=0 and blueRow[8]!=0)
		total += blueRow[9];

	/*
		Failed throws:
		-5 * failed throws
	*/
	total -= 5*(failedAttempts.size());

	return total;
}


int QwintoScoreSheet::setTotal(){
	int total = calcTotal();
	this->totalScore = total;
	return total;
}


bool QwintoScoreSheet::notOperator(){
	if(failedAttempts.size() >= 4){
		cout << "\nThis was your fourth and last failed throw :(" << endl;
		return true;
	}
	if(twoRows()){
		cout << "\nLooks like you filled two entire rows. Good Job!!" << endl;
		return true;
	}
	return false;
}
