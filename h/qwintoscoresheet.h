#ifndef QWINTO_SS_
#define QWINTO_SS_

template<Color C>
class QwintoRow {

  public:
    Color rowColor = C;
    RollOfDice values[9];
    RollOfDice& operator[] (const int index);
    ostream& operator<< (ostream& os);
};

template<Color C>
RollOfDice& QwintoRow<C>::operator[] (int index){
  return values[index];
}

template<Color C>
ostream& QwintoRow<C>::operator<< (ostream& os){
  if(this->rowColor == red){
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
  if(this->rowColor == yellow){
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
  if(this->rowColor == blue){
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
  	os << "\n";
  }
  return os;
}

class QwintoScoreSheet : public ScoreSheet<QwintoScoreSheet>{

  public:
    QwintoRow<Color::red> redRow;
    QwintoRow<Color::yellow> yellowRow;
    QwintoRow<Color::blue> blueRow;
    QwintoScoreSheet(string _playerName) : ScoreSheet(_playerName) { };
    bool score(RollOfDice &rollOfdice, Color color, int pos=-1);
    bool notOperator();
    bool twoRows();
    int setTotal();
    int calcTotal();

    ostream& print(ostream& os);

};

#include "../cpp/Qwinto/QwintoScoreSheet.cpp"
#endif
