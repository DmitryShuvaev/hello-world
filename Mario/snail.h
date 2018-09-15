#ifndef SNAIL_H
#define SNAIL_H
#include <QGraphicsPixmapItem>
#include <QDebug>


class Snail: public QGraphicsPixmapItem
{
public:
    Snail(QGraphicsItem *parent = 0);
    void setPix(int x,int y);

    void move();
    float snailX;
    float snailY;
    float movingTimer = 0;
    float movingTimerState = 0;
    int currentFrame=0;
    float movingDuration=2;
     int movingDirection=0;
     bool idle=false;
};

#endif // SNAIL_H
