#include "title.h"

Title::Title(QGraphicsItem*parent):QGraphicsTextItem(parent)
{

}

void Title::init(QString title,int y,int fontSize)
{
    this->title=title;

    setPlainText(title);

    setDefaultTextColor(Qt::blue);

    setFont(QFont("times",fontSize));

    setPos(VIRTUAL_WIDTH/2-boundingRect().width()/2,y);
}
