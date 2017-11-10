#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

enum Color { red, yellow, blue };

using namespace std;

template<Color T>
class QwintoRow {

  private:
    int size = 9;
    RollOfDice values[9];

  public:
    RollOfDice& operator[] (const int index);
};

template<> RollOfDice& QwintoRow<(Color)0>::operator[] (const int index){
    return values[index];
}
