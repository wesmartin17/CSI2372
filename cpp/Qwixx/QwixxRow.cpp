template<class T, Color C>
QwixxRow<T, C>& QwixxRow<T, C>::operator+= (RollOfDice rd){

  string color;
	RollOfDice* row;
	int realpos = 0;
	switch (C) {
    case red : realpos = int(rd) - 2; color = "red"; break;
		case yellow : realpos = int(rd) - 2; color = "yellow"; break;
    case green : realpos = 12 - int(rd); color = "green"; break;
    case blue : realpos = 12 - int(rd); color = "blue"; break;
  }

  if(rd.dices.size()==0){
    throw invalid_argument("This roll of dice is invalid!");
  }

  if((int(rd) > 12) or (int(rd)<0)){
    throw invalid_argument("This roll of dice is invalid!");
  }

  // GOOD TO SCORE
  values[realpos] = rd;

  // Check if row should be locked
  int rowCount = 0; // Count scores
  for(int i=0; i<11; ++i){
    if(int(values[i]) != 0){
      rowCount++;
    }
  }
  // Check count
  if((rowCount>=5) and (int(values[10]) != 0)){
    values[11] = rd;
    cout << "\n[!] Player locked selected row. ["<< color << " dice] will be removed from the game" <<  endl;
  }

  return *this;
}

template<class T, Color C>
ostream& QwixxRow<T, C>::operator<<(ostream& os){
  if(C == red){
    //---- PRINTS RED ROW -----//
  	os << "\n\t----------------------------------------------------------- ";
  	os << "\nRed\t";
  	for(int i=2; i<14; ++i){
      if(values[i-2] == 0){
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

  }
  if(C == yellow){
    //---- PRINTS YELLOW ROW -----//
  	os << "\nYellow\t";
  	for(int i=2; i<14; ++i){
      if(values[i-2] == 0){
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

  }
  if(C == green){
    //---- PRINTS GREEN ROW -----//
  	os << "\nGreen\t";
  	int j=0;
  	for(int i=12; i>0; --i){
      if(values[j] == 0){
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
  			if(j==11){
  				os << "| L ";
  			}else{
  				os << "| XX ";
  			}
      }
  		++j;
  	}
  	os << "\n\t----------------------------------------------------------- ";

  }
  if(C == blue){
    //---- PRINTS BLUE ROW -----//
  	os << "\nBlue\t";
  	int j=0;
  	for(int i=12; i>0; --i){
      if(values[j] == 0){
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
  			if(j==11){
  				os << "| L ";
  			}else{
  				os << "| XX ";
  			}
      }
  		++j;
  	}
  }

  return os;
}


template<class T, Color C>
RollOfDice& QwixxRow<T, C>::operator[] (int index){
  return values[index];
}
