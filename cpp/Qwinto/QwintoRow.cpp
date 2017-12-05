
template<Color C>
RollOfDice& QwintoRow<C>::operator[] (int index){
  return values[index];
}

template<Color C>
ostream& QwintoRow<C>::operator<< (ostream& os){
  if(C == red){
    //---- PRINTS RED ROW -----//
    os << "\n\t          ------------------------------------------------- ";
  	os << "\nRed\t          ";
  	for(int i=0; i<9; ++i){
  	  if(values[i] == 0){
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
  			if(values[i]>9){ // for styling
  				if(i==8){
  					os << "| "<< values[i]<< " |"; // last
  				}else if(i==1 or i==2 or i==4 or i==5){
  					os << "$ "<< values[i] <<" "; // pentagons
  				}else if(i==3){
  					os << "|XX| "<< values[i] <<" "; // middle
  				}else{
  					os << "| "<< values[i] <<" "; // everything else
  				}
  			}else{
  				if(i==8){
  					os << "| "<< values[i]<< "  |"; // last
  				}else if(i==1 or i==2 or i==4 or i==5){
  					os << "$ "<< values[i] <<"  "; // pentagons
  				}else if(i==3){
  					os << "|XX| "<< values[i] <<"  "; // middle
  				}else{
  					os << "| "<< values[i] <<"  "; // everything else
  				}
  			}
  		}

  	}
  }
  if(C == yellow){
    //---- PRINTS YELLOW ROW -----//
  	os << "\n\t     ------------------------------------------------- ";
  	os << "\nYellow       ";
  	for(int i=0; i<9; ++i){
  	  if(values[i] == 0){
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
  			if(values[i]>9){ // for styling
  				if(i==8){
  					os << "| "<< values[i] << " |"; // last
  				}else if(i==6 or i==7){
  					os << "$ "<< values[i] <<" "; // pentagons
  				}else if(i==5){
  					os << "|XX| "<< values[i] <<" "; // middle
  				}else{
  					os << "| "<< values[i] <<" "; // everything else
  				}
  			}else{
  				if(i==8){
  					os << "| "<< values[i] << "  |"; // last
  				}else if(i==6 or i==7){
  					os << "$ "<< values[i] <<"  "; // pentagons
  				}else if(i==5){
  					os << "|XX| "<< values[i] <<"  "; // middle
  				}else{
  					os << "| "<< values[i] <<"  "; // everything else
  				}
  			}
  		}

  	}
  	os << "\n";
  }
  if(C == blue){
    //---- PRINTS BLUE ROW -----//
  	os << "\t------------------------------------------------- ";
  	os << "\nBlue    ";
  	for(int i=0; i<9; ++i){
  	  if(values[i] == 0){
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
  			if(values[i]>9){ // for styling
  				if(i==8){
  					os << "$ "<< values[i] << " $"; // last
  				}else if(i==2 or i==3){
  					os << "$ "<< values[i] <<" "; // pentagons
  				}else if(i==4){
  					os << "|XX| "<< values[i] <<" "; // middle
  				}else{
  					os << "| "<< values[i] <<" "; // everything else
  				}
  			}else{
  				if(i==8){
  					os << "$ "<< values[i] << "  $"; // last
  				}else if(i==2 or i==3){
  					os << "$ "<< values[i] <<"  "; // pentagons
  				}else if(i==4){
  					os << "|XX| "<< values[i] <<"  "; // middle
  				}else{
  					os << "| "<< values[i] <<"  "; // everything else
  				}
  			}
  		}

  	}
  }
  return os;
}
