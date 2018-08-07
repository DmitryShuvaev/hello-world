#include "score.h"

Score::Score(QGraphicsItem*parent):QGraphicsTextItem(parent),score(0)
{

    setPlainText(QString("Score: ")+QString::number(score));

    setDefaultTextColor(Qt::white);

    setFont(QFont("times",20));
    setZValue(1);
    setPos(0,10);
}

void Score::update()
{
     setPlainText(QString("Score: ")+QString::number(score));
}
