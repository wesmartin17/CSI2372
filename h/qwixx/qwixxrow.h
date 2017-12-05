#ifndef QWIXXROW_
#define QWIXXROW_

template<class T, Color C>
class QwixxRow{

  public:
    RollOfDice values[13];
    QwixxRow<T, C>& operator+= (RollOfDice rd);
    ostream& operator<< (ostream& os);

};

#include "../../cpp/Qwixx/QwixxRow.cpp"
#endif
