#include "brick.h"
#include "sounds.h"
extern Sounds sound;

Brick::Brick(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QRect rect(0, 0, 32, 16);

    //qDebug()<<arr[p].y;
    QPixmap  cropped = original.copy(rect);
    cropped= cropped.scaled(QSize(width, height));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setPos(x,y);
}

void Brick::hit()
{


    //inPlay = false;
    //if we're at a higher tier than the base, we need to go down a tier
    //if we're already at the lowest color, else just go down a color

        //if we're in the first tier and the base color, remove brick from play



            color = color - 1;
            //setColor(color);
           if(color == 0){
              inPlay = false;

           }
         if(color >= 0){
            setColor(color);
            sound.player[4]->play();
         }


}

void Brick::init(int x, int y)
{

 this->x=x; this->y=y;
    inPlay=true;
    setPos(x,y);
}

void Brick::setColor(int color)
{
    struct Point
    {
       int x, y;
    };
   //srand(time(NULL));
    struct Point arr[10];
    arr[0].x = 0;    arr[1].x = 128; arr[2].x = 63; arr[3].x = 0; arr[4].x = 128;arr[5].x = 63;
    arr[0].y = 0;    arr[1].y = 0;   arr[2].y = 16; arr[3].y = 32;arr[4].y = 32;arr[5].y = 48;
    //int p= randNum(5, 0);
    QRect rect(arr[color].x, arr[color].y, 32, 16);

    //qDebug()<<arr[p].y;
    QPixmap  cropped = original.copy(rect);
    cropped= cropped.scaled(QSize(width, height));
    setPixmap(cropped);
}

void Brick::setTier(int tier)
{
    struct Point
    {
       int x, y;
    };

    struct Point arr[10];
    arr[0].x = 32;    arr[1].x = 64; arr[2].x = 96; arr[3].x = 161; arr[4].x = 0; arr[5].x = 32;
    arr[0].y = 0;    arr[1].y = 0;   arr[2].y = 0;  arr[3].y = 0;   arr[4].y = 16;arr[5].y = 16;

    QRect rect(arr[color].x, arr[color].y, 32, 16);

    //qDebug()<<arr[p].y;
    QPixmap  cropped = original.copy(rect);
    cropped= cropped.scaled(QSize(width, height));
    setPixmap(cropped);
}

