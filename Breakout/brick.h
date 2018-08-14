#ifndef BRICK_H
#define BRICK_H
#include "constants.h"
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QParallelAnimationGroup>
#include <QPen>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>


class Brick: public QGraphicsPixmapItem,Constants
{

public:
    Brick(QGraphicsItem *parent = 0);
    void hit();
    void init(int x, int y);
    void setColor(int);
    void setTier(int);
    void explode(QObject * obj);
   bool m_explosion;
    //used for coloring and score calculation
    int tier = 0;
    int color = 1;

    int x=10 ;
    int y=10 ;
    int width = 32*3;
    int height = 16*3;

    //used to determine whether this brick should be rendered
    bool inPlay = true;

};

#endif // BRICK_H
