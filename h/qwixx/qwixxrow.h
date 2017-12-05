#ifndef QWIXXROW_
#define QWIXXROW_

template<class T, Color C>
class QwixxRow{

  public:
    Color rowColor = C;
    RollOfDice values[12];
    RollOfDice& operator[] (const int index);
    QwixxRow<T, C> operator+= (RollOfDice rd);
    ostream& operator<< (ostream& os);

};

#include "../../cpp/Qwixx/QwixxRow.cpp"
#endif
