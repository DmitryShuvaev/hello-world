#include "statusinfor.h"

StatusInfor::StatusInfor(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    setPlainText(QString(" Welcome to Pong!\n")+QString("Press Enter to begin!"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",20));
    setPos(1280/2-boundingRect().width()/2,10);
}
void StatusInfor::update(QString st1,QString st2)
{
 setPlainText(st1+st2);
}
