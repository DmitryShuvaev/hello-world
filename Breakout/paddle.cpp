#include "paddle.h"

Paddle::Paddle(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    //QPixmap pixmap(":/pics/bird.png");
    QRect rect(32, 64, 64, 16);
    QPixmap  original(":/graphics/graphics/breakout.png");
    QPixmap  cropped = original.copy(rect);
   cropped= cropped.scaled(QSize(64*3, 16*3));
    setPixmap(cropped);
    //setOffset(16, 0);
setFlag(QGraphicsItem::ItemIsFocusable);
    setPos(x,y);
}

void Paddle::update()
{
   if(x>4&&dx<0)
   x=x+dx;
   else if(dx>0&&x<WINDOW_WIDTH-width){

       x=x+dx;

   }
   setPos(x,y);
   //qDebug()<<x;
}
