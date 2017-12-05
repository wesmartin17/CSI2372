int RandomDice(){

	unsigned long seed = static_cast<unsigned long>(time(0));
	static default_random_engine rng(seed);
  static uniform_int_distribution<int> dist(1,6);
  return dist(rng);

}

Dice::Dice(const Color color){
	diceColor = color;
	face = RandomDice();
}

int Dice::roll(){
	face = RandomDice();
	return face;
}

int RollOfDice::roll(){
	int result = 0;
	for(vector<Dice>::iterator it = dices.begin(); it != dices.end(); ++it){

		Dice d = *it;
		result += d.roll();
	}
	return result;
}

RollOfDice RollOfDice::pair(Dice d1, Dice d2){
	RollOfDice rd;
	rd.dices.push_back(d1);
	rd.dices.push_back(d2);

	return rd;
}

//conversion operator to int.  is the sum of faces
RollOfDice::operator int(){

	int sum = 0;
	for(vector<Dice>::iterator it = dices.begin(); it != dices.end(); ++it){

		Dice d = *it;
		sum+= d.face;
	}
	return sum;
}

ostream& operator<<(ostream& os,  RollOfDice& rd){

	for(int i=0; i<rd.dices.size(); ++i){
		if(rd.dices[i].diceColor == Color::red)
			os << "[R "<< int(rd.dices[i].face) << "]\n";
		else if(rd.dices[i].diceColor == Color::yellow)
			os << "[Y "<< int(rd.dices[i].face) << "]\n";
		else if(rd.dices[i].diceColor == Color::green)
			os << "[G "<< int(rd.dices[i].face) << "]\n";
		else if(rd.dices[i].diceColor == Color::blue)
			os << "[B "<< int(rd.dices[i].face) << "]\n";
		else if(rd.dices[i].diceColor == Color::white)
			os << "[W "<< int(rd.dices[i].face) << "]\n";
	}
	os << "Total: [" << int(rd) << "]\n";
	return os;
}
