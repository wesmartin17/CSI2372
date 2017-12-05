template<class T, Color C>
RollOfDice& QwixxRow<T, C>::operator[](int index){
  return values[index];
}

template<class T, Color C>
QwixxRow<T, C> QwixxRow<T, C>::operator+= (RollOfDice rd){

  // Passed dice colors dont include C
  if(rd.dices[0].diceColor != C and rd.dices[1].diceColor != C and (rd.dices[0].diceColor != Color::white or rd.dices[1].diceColor != Color::white))
    throw std::invalid_argument("Dice color combo is missing the requested row color!");

  // Passed dice colors dont include at least 1x white
  if(rd.dices[0].diceColor != Color::white and rd.dices[1].diceColor != Color::white)
    throw std::invalid_argument("Dice color combo is missing a white dice!");


  // Passed dice is to be scored in a locked row
  if(int(values[12]) != 0){
    throw std::invalid_argument("Dice combo can't be scored in a locked row!");
  }

  // Passed dice is to be scored left of double-white-dice score
	for(int i=0; i<=int(rd); ++i){
		if(values[i].dices[0].diceColor==Color::white and values[i].dices[1].diceColor==Color::white){
      throw std::invalid_argument("Dice combo can't be scored left of a double-white dice score!");
		}
	}

  values[int(rd)] = rd;
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
