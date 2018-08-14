#include "title.h"

Title::Title(QGraphicsItem*parent):QGraphicsTextItem(parent)

{


}



void Title::init(QString title,int y,int fontSize)

{
    this->title=title;

    setPlainText(title);

    setDefaultTextColor(Qt::white);

    setFont(QFont("times",fontSize));

    setPos(WINDOW_WIDTH/2-boundingRect().width()/2,y);
}

void Title::setColor()
{

    setDefaultTextColor(Qt::green);
}
