#ifndef PADDLE_H
#define PADDLE_H
#include "constants.h"

class Paddle: public QGraphicsPixmapItem,Constants
{
public:
    Paddle(QGraphicsItem *parent = 0);
    //x is placed in the middle
    int x = WINDOW_WIDTH / 2 - 32*3-20;

    // y is placed a little above the bottom edge of the screen
    int y = WINDOW_HEIGHT - 32*3;

    //start us off with no velocity
    int dx = 0;

    //starting dimensions
    int width = 64*3+20;
    int height = 16*3;

    //the skin only has the effect of changing our color, used to offset us
    //into the gPaddleSkins table later
    int skin = 1;

    //the variant is which of the four paddle sizes we currently are; 2
    //is the starting size, as the smallest is too tough to start with
    int size = 2;
   void update();
};

#endif // PADDLE_H
