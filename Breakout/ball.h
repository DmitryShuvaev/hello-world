#ifndef BALL_H
#define BALL_H
#include <QTimer>
#include <QObject>
//#include "constants.h"
#include "paddle.h"
#include "brick.h"
//#include "main.moc" // Required.


extern Constants *consv;
class Ball: public QGraphicsPixmapItem,Constants
{

public:
    Ball(QGraphicsItem *parent = 0);

    void start(int,int);
    void stop();
    //simple positional and dimensional variables
    int width = 24;
    int height = 24;

    //these variables are for keeping track of our velocity on both the
    //X and Y axis, since the ball can move in two dimensions
    float dy = 0;
    float dx = 0;
    int x = WINDOW_WIDTH / 2 - 12;
    int y = WINDOW_HEIGHT - 32*3-24;
    //this will effectively be the color of our ball, and we will index
    //our table of Quads relating to the global block texture using this
    int skin ;


 void update();

 bool collides(Paddle *padle);
 bool collides(Brick *brick);
 void reset();
};

#endif // BALL_H
