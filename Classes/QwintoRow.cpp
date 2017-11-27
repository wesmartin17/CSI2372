#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "../headers/RollOfDice.h"

enum Color { red, yellow, blue };

using namespace std;

template<Color C>
class QwintoRow {

  public:
    RollOfDice values[9];
    RollOfDice& operator[] (const int index);
};

template<Color C>
RollOfDice& QwintoRow<C>::operator[] (int index){
  return values[index];
}
