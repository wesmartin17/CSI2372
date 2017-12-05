template<Color C>
RollOfDice& QwixxRow<C>::operator[](int index){
  return values[index];
}

template<Color C>
QwixxRow<C> QwixxRow<C>::operator+= (RollOfDice rd){
  if(rd.dices[0].diceColor != C and rd.dices[1].diceColor != C and (rd.dices[0].diceColor != Color::white or rd.dices[1].diceColor != Color::white))
    throw std::invalid_argument("Dice color combo is missing the requested row color!");
  else if(rd.dices[0].diceColor != Color::white and rd.dices[1].diceColor != Color::white)
    throw std::invalid_argument("Dice color combo is missing a white dice!");
  values[int(rd)] = rd;
  return *this;
}

template<Color C>
ostream& QwixxRow<C>::operator<<(ostream& os){
  if(this->rowColor == red){
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
  if(this->rowColor == yellow){
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
  if(this->rowColor == green){
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
  if(this->rowColor == blue){
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
