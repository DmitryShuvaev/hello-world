#include "myrect.h"

MyRect::MyRect()
{
    setRect(0,0,32*2,32*2);

    //setBrush(QColor(255, 255, 255));QPen(Qt::cyan, 1)
    setPen(QPen(QColor(255, 0, 0),5));
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void MyRect::init(int x, int y)
{
 setPos(x,y);
}
