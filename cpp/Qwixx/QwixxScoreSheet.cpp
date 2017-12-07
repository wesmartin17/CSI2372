bool QwixxScoreSheet::score(RollOfDice &rollOfdice, Color color, int pos){


	switch (color) {
		case Color::red:{
			try{
				redRow += rollOfdice;
				return true;
			}
			catch(InvalidInputException& e ){
				cout << e.what() << endl;
				return false;
			}
			catch(FailedAttemptException& e ){
				cout << e.what() << endl;
				cout << "[!] That was a failed attempt to score and it will be marked." << endl;
				failedAttempts.push_back(rollOfdice);
				return false;
			}
			break;
		}
		case Color::yellow:{
			try{
				yellowRow += rollOfdice;
				return true;

			}
			catch(InvalidInputException& e ){
				cout << e.what() << endl;
				return false;
			}
			catch(FailedAttemptException& e ){
				cout << e.what() << endl;
				cout << "That was a failed attempt to score and it will be marked." << endl;
				failedAttempts.push_back(rollOfdice);
				return false;
			}
			break;
		}
		case Color::green:{
			try{
				greenRow += rollOfdice;
				return true;
			}
			catch(InvalidInputException& e ){
				cout << e.what() << endl;
				return false;
			}
			catch(FailedAttemptException& e ){
				cout << e.what() << endl;
				cout << "[!] That was a failed attempt to score and it will be marked." << endl;
				failedAttempts.push_back(rollOfdice);
				return false;
			}
			break;
		}
		case Color::blue:{
			try{
				blueRow += rollOfdice;
				return true;

			}
			catch(InvalidInputException& e ){
				cout << e.what() << endl;
				return false;
			}
			catch(FailedAttemptException& e ){
				cout << e.what() << endl;
				cout << "\n[!]That was a failed attempt to score and it will be marked." << endl;
				failedAttempts.push_back(rollOfdice);
				return false;
			}
			break;
		}

	}

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
	if(int(redRow.values[12]) != 0)
		locked += 1;
	if(int(yellowRow.values[12]) != 0)
		locked += 1;
	if(int(greenRow.values[12]) != 0)
		locked += 1;
	if(int(blueRow.values[12]) != 0)
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
