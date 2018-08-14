#include "ball.h"
#include "sounds.h"
extern Sounds sound;

Ball::Ball(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QRect rect(96, 48, 8, 8);
    QPixmap  original(":/graphics/graphics/breakout.png");
    QPixmap  cropped = original.copy(rect);
    cropped= cropped.scaled(QSize(width, height));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setPos(x,y);
    dx=randNum(-2,2);
    dy=randNum(-4,-5);


}


void Ball::update()
{
    x = x + dx;
    y = y + dy;
    //allow ball to bounce off walls
     if(x <= 0){
        x = 0;
        dx = -dx;
        sound.player[3]->play();
     }
     if(x >= WINDOW_WIDTH - width){
        x = WINDOW_WIDTH - width;
        dx = -dx;
        sound.player[3]->play();
     }
     if(y <= 0){
        y = 0;
        dy = -dy;
        sound.player[3]->play();
     }
    setPos(x,y);

}

bool Ball::collides(Paddle* padle)
{
    //first, check to see if the left edge of either is farther to the right
    //than the right edge of the other
    /*
    if((x >= padle->x &&x<=padle->x+padle->width)&&
     (y+height >= padle->y&& y<padle->y+height) ){
     qDebug()<<"colis";
     return true;
    }
    return false;
    */
    if(x > padle->x + padle->width-20 || padle->x > x + width)
        return false ;
    if(y > padle->y + padle->height||padle->y > y + height)
        return false;
     sound.player[2]->play();
     y=padle->y-height;
     return true;
}

bool Ball::collides(Brick *brick)
{
    if(x > brick->x + brick->width || brick->x > x + width)
        return false ;
    if(y > brick->y + brick->height||brick->y > y + height)
        return false;
    //sound.player[4]->play();
     return true;
}

void Ball::reset()
{
     dy = 0;
     dx = 0;
     x = WINDOW_WIDTH / 2 - 12;
     y = WINDOW_HEIGHT - 32*3-24;
}

void Ball::start(int x,int y)
{
 this->x=x;this->y=y;
 setPos(this->x,this->y);

}

void Ball::stop()
{


}
//#include "main.moc" ;// Required.
