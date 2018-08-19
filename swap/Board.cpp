#include "Board.h"

void Board::init(int x,int y)
{
    /*
    QRect rect(x, y, 32, 32);
    QPixmap  original(":/pics/match3.png");
    QPixmap  cropped = original.copy(rect);
    cropped= cropped.scaled(QSize(32*2, 32*2));
    setPixmap(cropped);
    this->x=x*2;
    this->y=y*2;
   // setPos(this->x+128*2,this->y+32*2);
   */
}

Board::Board(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

}
