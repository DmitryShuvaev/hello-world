#include "bird.h"

Bird::Bird(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
   // load bird image from disk and assign its width and height
    QPixmap pixmap(":/pics/bird.png");
    setPixmap(pixmap);
    x=pixmap.width() / 2;
    y=pixmap.height() / 2;
    setPos(x,y);
}

void Bird::update()
{

    setPos(x,y);
    move();
}

void Bird::move()
{
    //apply gravity to velocity
    dy = dy + GRAVITY;
    //apply current velocity to Y position
    y = y + dy;
}

