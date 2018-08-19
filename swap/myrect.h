#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

#include <QPen>

class MyRect:public QGraphicsRectItem
{
public:
    MyRect();
     void init(int x, int y);
};

#endif // MYRECT_H
