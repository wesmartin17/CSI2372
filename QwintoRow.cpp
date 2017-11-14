#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "RollOfDice.h"

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

  if(index > 9 or index < 0){
    throw std::runtime_error("Index out of range!");
  }/*else if () {
    // TODO: check if cell already occupied
    throw std::runtime_error("Cell occupied!");
  }*/

  return values[index];
}
