bool QwixxScoreSheet::score(RollOfDice &rollOfdice, Dice::Color color, int pos){

	RollOfDice* row;
	int realpos = pos;
	switch (color) {
		case Dice::Color::red:{
			row = redRow.values;
			realpos = int(rollOfdice) - 2; // 2 thourgh 12
			break;
		}
		case Dice::Color::yellow:{
			row = yellowRow.values;
			realpos = int(rollOfdice) - 2; // 2 through 12
			break;
		}
		case Dice::Color::green:{
			row = greenRow.values;
			realpos = 12 - int(rollOfdice); // 12 through 2
			break;
		}
		case Dice::Color::blue:{
			row = blueRow.values;
			realpos = 12 - int(rollOfdice); // 12 through 2
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
			if(it->diceColor == Dice::Color::white){
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


ostream& QwixxScoreSheet::print(ostream& os){

	os << "\n\t----------------------------------------------------------- ";

	//---- PRINTS RED ROW -----//
	os << "\nRed\t";
	for(int i=2; i<14; ++i){
    if(redRow[i-2] == 0){
      if(i>9){ // for styling
				if(i==13){
					os << "| U  "; // last
				}else{
        	os << "| "<<i<<" "; // 10, 11, 12
				}
      }else{
      	os << "| "<<i<<"  "; // 2-9
      }
    }else{
			if(i==13){
				os << "| L ";
			}else{
				os << "| XX ";
			}
    }

	}
	os << "\n\t----------------------------------------------------------- ";

	//---- PRINTS YELLOW ROW -----//
	os << "\nYellow\t";
	for(int i=2; i<14; ++i){
    if(yellowRow[i-2] == 0){
      if(i>9){ // for styling
				if(i==13){
					os << "| U  "; // last
				}else{
        	os << "| "<<i<<" "; // 10, 11, 12
				}
      }else{
      	os << "| "<<i<<"  "; // 2-9
      }
    }else{
			if(i==13){
				os << "| L ";
			}else{
				os << "| XX ";
			}
    }

	}
	os << "\n\t----------------------------------------------------------- ";

	//---- PRINTS GREEN ROW -----//
	os << "\nGreen\t";
	int j=0;
	for(int i=12; i>0; --i){
    if(greenRow[j] == 0){
      if(i>9){ // for styling
      	os << "| "<<i<<" "; // 10, 11, 12
      }else{
				if(i==1){
					os << "| U  "; // last
				}else{
      		os << "| "<<i<<"  "; // 2-9
				}
      }
    }else{
			if(i==13){
				os << "| L ";
			}else{
				os << "| XX ";
			}
    }
		++j;
	}
	os << "\n\t----------------------------------------------------------- ";

	//---- PRINTS BLUE ROW -----//
	os << "\nBlue\t";
	j=0;
	for(int i=12; i>0; --i){
    if(blueRow[j] == 0){
      if(i>9){ // for styling
      	os << "| "<<i<<" "; // 10, 11, 12
      }else{
				if(i==1){
					os << "| U  "; // last
				}else{
      		os << "| "<<i<<"  "; // 2-9
				}
      }
    }else{
			if(i==13){
				os << "| L ";
			}else{
				os << "| XX ";
			}
    }
		++j;
	}
	os << "\n\t----------------------------------------------------------- ";

	//---- PRINTS FAILED THROWS -----//
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
