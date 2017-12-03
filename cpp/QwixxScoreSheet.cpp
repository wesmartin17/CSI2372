bool QwixxScoreSheet::score(RollOfDice &rollOfdice, Dice::Color color, int pos){

	RollOfDice* row;
	switch (color) {
		case Dice::Color::red: row = redRow.values; break;
		case Dice::Color::yellow: row = yellowRow.values; break;
    case Dice::Color::green: row = greenRow.values; break;
		case Dice::Color::blue: row = blueRow.values; break;
	}
	if(pos > 11 or pos < 0){
		cout << "Invalid input: #" << pos
							<< ":\nYou must select location cell number between 1 and 9" << endl;
		return false;
	}else if(int(row[pos]) != 0){
		cout << "Invalid input: #" << pos
							<< ":\nCell #" << pos << " already has value " << int(row[pos]) << endl;
		return false;
	}

  // TODO implement score

	row[pos] = rollOfdice;
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
      if(redRow[i-2]>9){ // for styling
        os << "| "<<redRow[i-2]<<" ";
      }else{
        os << "| "<<redRow[i-2]<<"  ";
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
      if(yellowRow[i-2]>9){ // for styling
        os << "| "<<yellowRow[i-2]<<" ";
      }else{
        os << "| "<<yellowRow[i-2]<<"  ";
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
      if(greenRow[j]>9){ // for styling
        os << "| "<<greenRow[j]<<" ";
      }else{
        os << "| "<<greenRow[j]<<"  ";
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
      if(blueRow[j]>9){ // for styling
        os << "| "<<blueRow[j]<<" ";
      }else{
        os << "| "<<blueRow[j]<<"  ";
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
