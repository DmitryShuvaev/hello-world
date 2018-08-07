#include "countdownstate.h"

CountdownState::CountdownState(QGraphicsItem*parent):QGraphicsTextItem(parent)
{

 state=Constants::Player::Invalid;


}
/*
Constants::Player CountdownState::setState()
{
    if(state==Constants::Player::play){
      return state;
    }  else{

    }

}
*/
void CountdownState::update(int count)
{


    setPlainText(QString::number(count));

    setDefaultTextColor(Qt::white);

    setFont(QFont("times",40));
    setZValue(1);
    setPos(VIRTUAL_WIDTH/2-boundingRect().width()/2,PIPE_HEIGHT/2-boundingRect().height()/2);

}
