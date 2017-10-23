#include "ScoreSheet.h"
#include <iomanip>

ScoreSheet::ScoreSheet(string name){
	this->name= name;
	
}

void ScoreSheet::print(ostream& o){

	o<<"Player name: "<<this->name<<std::setw(40-name.length())<<"Points: "<<(redScore + blueScore + yellowScore)<<endl;
	o<<std::setfill('-')<<std::setw(55)<<" "<<endl;	
	
	
	
}
