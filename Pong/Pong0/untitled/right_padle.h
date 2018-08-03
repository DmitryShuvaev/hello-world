#ifndef RIGHT_PADLE_H
#define RIGHT_PADLE_H
#include <QGraphicsRectItem>
#include <QPen>
#include <QDebug>

class Right_padle:public QGraphicsRectItem
{
public:
    Right_padle();
    void init(float x, float y, int width, int height);
    void move(int PADDLE_SPEED);
    float x,y;
    int width,height,dy;
};

#endif // RIGHT_PADLE_H
