#ifndef QWINTO_SS_
#define QWINTO_SS_

#include "ScoreSheet.h"
#include "../Classes/QwintoRow.cpp"

class QwintoScoreSheet : public ScoreSheet<QwintoScoreSheet>{

  protected:
    QwintoRow<red> redRow;
    QwintoRow<yellow> yellowRow;
    QwintoRow<blue> blueRow;

  public:
    QwintoScoreSheet(string _playerName) : ScoreSheet(_playerName) { };
    int getRedRowRD(int i);
    int getYellowRowRD(int i);
    int getBlueRowRD(int i);
    template<Color C>
    QwintoRow<C> getRow(){
    	switch(C){
    		case red: return redRow; break;
    		case yellow: return yellowRow; break;
    		case blue: return blueRow; break;
    	}
    };

};

#endif
