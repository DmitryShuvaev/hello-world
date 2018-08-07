#ifndef PIPE_H
#define PIPE_H
#include <QGraphicsPixmapItem>
#include "constants.h"
#include <QTime>
#include <QDebug>

class Pipe: public QGraphicsPixmapItem,public Constants
{
public:
    Pipe(QGraphicsItem *parent = 0);
    void setDirection(int direction);
    void init(int y);
    void update();
    float PIPE_SCROLL = -1;
    float width;
    float x;
    float y;
    //int orientation;
};

#endif // PIPE_H
