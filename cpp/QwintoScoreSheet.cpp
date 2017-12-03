bool QwintoScoreSheet::score(RollOfDice &rollOfdice, Dice::Color color, int pos){

	RollOfDice* row;
	switch (color) {
		case Dice::Color::red: row = redRow.values; break;
		case Dice::Color::yellow: row = yellowRow.values; break;
		case Dice::Color::blue: row = blueRow.values; break;
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


ostream& QwintoScoreSheet::print(ostream& os){

	//---- PRINTS RED ROW -----//
	os << "\nRed\t          ";
	for(int i=0; i<9; ++i){
	  if(redRow[i] == 0){
			if(i==8){
				os << "|    |"; // last
			}else if(i==1 or i==2 or i==4 or i==5){
				os << "$    "; // pentagons
			}else if(i==3){
				os << "|XX|    "; // middle
			}else{
				os << "|    "; // everything else
			}
	  }else{
			if(redRow[i]>9){ // for styling
				if(i==8){
					os << "| "<< redRow[i]<< " |"; // last
				}else if(i==1 or i==2 or i==4 or i==5){
					os << "$ "<< redRow[i] <<" "; // pentagons
				}else if(i==3){
					os << "|XX| "<< redRow[i] <<" "; // middle
				}else{
					os << "| "<< redRow[i] <<" "; // everything else
				}
			}else{
				if(i==8){
					os << "| "<< redRow[i]<< "  |"; // last
				}else if(i==1 or i==2 or i==4 or i==5){
					os << "$ "<< redRow[i] <<"  "; // pentagons
				}else if(i==3){
					os << "|XX| "<< redRow[i] <<"  "; // middle
				}else{
					os << "| "<< redRow[i] <<"  "; // everything else
				}
			}
		}

	}

	//---- PRINTS YELLOW ROW -----//
	os << "\n\t     ------------------------------------------------- ";
	os << "\nYellow       ";
	for(int i=0; i<9; ++i){
	  if(yellowRow[i] == 0){
			if(i==8){
				os << "|    |"; // last
			}else if(i==6 or i==7){
				os << "$    "; // pentagons
			}else if(i==5){
				os << "|XX|    "; // middle
			}else{
				os << "|    "; // everything else
			}
	  }else{
			if(yellowRow[i]>9){ // for styling
				if(i==8){
					os << "| "<< yellowRow[i] << " |"; // last
				}else if(i==6 or i==7){
					os << "$ "<< yellowRow[i] <<" "; // pentagons
				}else if(i==5){
					os << "|XX| "<< yellowRow[i] <<" "; // middle
				}else{
					os << "| "<< yellowRow[i] <<" "; // everything else
				}
			}else{
				if(i==8){
					os << "| "<< yellowRow[i] << "  |"; // last
				}else if(i==6 or i==7){
					os << "$ "<< yellowRow[i] <<"  "; // pentagons
				}else if(i==5){
					os << "|XX| "<< yellowRow[i] <<"  "; // middle
				}else{
					os << "| "<< yellowRow[i] <<"  "; // everything else
				}
			}
		}

	}
	os << "\n";

	//---- PRINTS BLUE ROW -----//
	os << "\t------------------------------------------------- ";
	os << "\nBlue    ";
	for(int i=0; i<9; ++i){
	  if(blueRow[i] == 0){
			if(i==8){
				os << "$    $"; // last is pentagon
			}else if(i==2 or i==3){
				os << "$    "; // pentagons
			}else if(i==4){
				os << "|XX|    "; // middle
			}else{
				os << "|    "; // everything else
			}
	  }else{
			if(blueRow[i]>9){ // for styling
				if(i==8){
					os << "$ "<< blueRow[i] << " $"; // last
				}else if(i==2 or i==3){
					os << "$ "<< blueRow[i] <<" "; // pentagons
				}else if(i==4){
					os << "|XX| "<< blueRow[i] <<" "; // middle
				}else{
					os << "| "<< blueRow[i] <<" "; // everything else
				}
			}else{
				if(i==8){
					os << "$ "<< blueRow[i] << "  $"; // last
				}else if(i==2 or i==3){
					os << "$ "<< blueRow[i] <<"  "; // pentagons
				}else if(i==4){
					os << "|XX| "<< blueRow[i] <<"  "; // middle
				}else{
					os << "| "<< blueRow[i] <<"  "; // everything else
				}
			}
		}

	}
	os << "\n";
	os << "\t------------------------------------------------- ";
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
