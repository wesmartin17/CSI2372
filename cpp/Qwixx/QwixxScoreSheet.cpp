bool QwixxScoreSheet::score(RollOfDice &rollOfdice, Color color, int pos){


	switch (color) {
		case Color::red:{
			try{
				redRow += rollOfdice;
				return true;
			}catch(const invalid_argument& e ){
				return false;
			}
			break;
		}
		case Color::yellow:{
			try{
				yellowRow += rollOfdice;
				return true;

			}catch(const invalid_argument& e ){
				return false;
			}
			break;
		}
		case Color::green:{
			try{
				greenRow += rollOfdice;
				return true;

			}catch(const invalid_argument& e ){
				return false;
			}
			break;
		}
		case Color::blue:{
			try{
				blueRow += rollOfdice;
				return true;

			}catch(const invalid_argument& e ){
				return false;
			}
			break;
		}

	}




	// out of range
	// if(realpos > 11 or realpos < 0){
	// 	cout << "Invalid input: #" << pos
	// 						<< ":\nYou must select location cell number between 2 and 11" << endl;
	// 	return false;
	// }
	// // taken
	// if(int(row[realpos]) != 0){
	// 	cout << "Invalid input: #" << pos
	// 						<< ":\nCell #" << pos << " has been scored already" << endl;
	// 	return false;
	// }

	// GOOD TO SCORE


	// check if should lock row
	// int rowCount = 0;
	// for(int i=0; i<12; ++i){
	// 	if(row[i]!=0){
	// 		rowCount++;
	// 	}
	// }
	// if(rowCount==5){
	// 	row[12] = rollOfdice;
	// }
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


bool QwixxScoreSheet::operator!(){

	if(failedAttempts.size() >= 4){
		cout << "\nThis was your fourth and last failed throw :(" << endl;
		return true;
	}
  // TODO finish notOperator
	return false;
}
