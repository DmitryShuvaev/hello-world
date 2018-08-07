#include "pipe.h"

Pipe::Pipe(QGraphicsItem *parent): QGraphicsPixmapItem(parent),x(0)
{
    qsrand(QTime::currentTime().msec()); //seeding for the first time only!
    // load pipe image from disk
     QPixmap pixmap(":/pics/pipe.png");
     setPixmap(pixmap);
}

void Pipe::setDirection(int direction)
{
    QTransform transform;
    transform.scale(1, direction);
    setTransform(transform);
}

void Pipe::init(int y)
{
    //set the Y to a random value halfway below the screen
    // int range = VIRTUAL_HEIGHT - 20 - VIRTUAL_HEIGHT / 5 + VIRTUAL_HEIGHT - 20;
    x = VIRTUAL_WIDTH;
   // y = rand() % ((VIRTUAL_HEIGHT - 10)-(VIRTUAL_HEIGHT / 4)+1)+VIRTUAL_HEIGHT / 4;
    this->y=y;

     //qDebug() <<y;
     setPos(x,y);
     width=boundingRect().width();
     //setDirection(1);
}

void Pipe::update()
{
     setPos(x,y);
     x = x + PIPE_SCROLL;

}
