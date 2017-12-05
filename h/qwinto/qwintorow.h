#ifndef QWINTOROW_
#define QWINTOROW_

template<Color C>
class QwintoRow {

  public:
    Color rowColor = C;
    RollOfDice values[9];
    RollOfDice& operator[] (const int index);
    ostream& operator<< (ostream& os);
};


#include "../../cpp/Qwinto/QwintoRow.cpp"
#endif
