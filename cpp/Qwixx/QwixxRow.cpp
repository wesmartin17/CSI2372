template<class T, Color C>
QwixxRow<T, C>& QwixxRow<T, C>::operator+= (RollOfDice rd){

  string color = "";
  int realpos = 0;
	switch (C) {
    case red : realpos = int(rd) - 2; color = "red"; break;
		case yellow : realpos = int(rd) - 2; color = "yellow";  break;
    case green : realpos = 12 - int(rd); color = "green"; break;
    case blue : realpos = 12 - int(rd); color = "blue";  break;
  }

  // Passed dice colors dont include 1x C dice
  if(rd.dices[0].diceColor != C and rd.dices[1].diceColor != C and (rd.dices[0].diceColor != Color::white or rd.dices[1].diceColor != Color::white))
    throw std::invalid_argument("Dice are missing a die of the requested row color!");

  // Passed dice colors dont include at least 1x white
  if(rd.dices[0].diceColor != Color::white and rd.dices[1].diceColor != Color::white)
    throw std::invalid_argument("Dice are missing a least one white dice!");

  // Passed dice is to be scored in scored cell
  if(int(this->values[realpos]) != 0){
    throw std::invalid_argument("Dice combo can't be scored in an already scored spot!");
  }

  // Passed dice is to be scored in a locked row
  if(int(this->values[12]) != 0){
    throw std::invalid_argument("Dice combo can't be scored in a locked row!");
  }


  // Passed dice is to be scored left of double-white-dice score
	for(int i=0; i < realpos-1; ++i){
    if(values[i].dices.size() != 0)
		  if((values[i].dices[0].diceColor==white) and (values[i].dices[1].diceColor==white))
        throw std::invalid_argument("Dice combo can't be scored left of a double-white dice score!");
	}

  // GOOD TO SCORE
  values[realpos] = rd;

  // Check if row should be locked
  int rowCount = 0; // Count scores
  for(int i=0; i<12; ++i){
    if(values[i]!=0){
      rowCount++;
    }
  }
  // Check count
  if((rowCount>=5) and (int(values[11]) != 0)){
    values[12] = rd;
  }

  cout << "\nSelected row is now locked\n"
       << "["<< color << " dice] are now removed from the game\n" <<  endl;

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
  			if(i==13){
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
  			if(i==13){
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
