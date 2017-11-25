#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "../headers/RollOfDice.h"

enum Color { red, yellow, blue };

using namespace std;

template<Color C>
class QwintoRow {

  private:
    RollOfDice values[9];

  public:
    RollOfDice& operator[] (const int index);
};

template<Color C>
RollOfDice& QwintoRow<C>::operator[] (const int index){
  string input = "";
  int i = index;
  if(index > 8 or index < 0){
    while(i > 8 or i < 0){
      cout << "Index " << index << " is invalid!\n";
      cout << "Enter a position between 0-8" << endl;
      getline(cin, input);
      stringstream myStream(input);
      if(!(myStream >> i)){
        cout << "Invalid input!" << endl;
      }
    }
  }
  return values[i];
}
