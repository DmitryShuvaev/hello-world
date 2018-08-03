#ifndef LEFT_PADLE_H
#define LEFT_PADLE_H
#include <QGraphicsRectItem>
#include <QPen>
#include <QDebug>

class Left_padle:public QGraphicsRectItem
{
public:
public:
    Left_padle();
    void init(float x, float y, int width, int height);
    void move(int PADDLE_SPEED);
    float x,y;
    int width,height,dy;
};

#endif // LEFT_PADLE_H
