#ifndef BIRD_H
#define BIRD_H
#include <QGraphicsPixmapItem>

class Bird: public QGraphicsPixmapItem
{
public:
    Bird(QGraphicsItem *parent = 0);
//Y velocity; gravity
    float dy = 0;
    float x;
    float y;
    float GRAVITY = 0.05;
    void update();
    void move();
};

#endif // BIRD_H
