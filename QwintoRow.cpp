#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

enum Color { red, yellow, blue };

using namespace std;

template<Color T>
class QwintoRow {

  private:
    RollOfDice values[9];

  public:
    RollOfDice& operator[] (const int index);
};

template<> RollOfDice& QwintoRow<(Color)0>::operator[] (const int index){

  if(index > 9 or index < 1){
    throw std::runtime_error("Index out of range!");
  }/*else if () {
    // TODO: check if cell already occupied
    throw std::runtime_error("Cell occupied!");
  }*/

  return values[index];
}
