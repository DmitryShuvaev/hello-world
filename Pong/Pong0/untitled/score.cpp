#include "score.h"

Score::Score(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    player1Score = 0;
    player2Score = 0;
setPlainText(QString::number(player1Score)+QString("         ")+QString::number(player2Score));
setDefaultTextColor(Qt::blue);
setFont(QFont("times",40));
setPos(1280/2-boundingRect().width()/2,720/2-boundingRect().height()/2);

// initialize score variables, used for rendering on the screen and keeping
// track of the winner

}

void Score::update()
{
 setPlainText(QString::number(player1Score)+QString("         ")+QString::number(player2Score));
}
