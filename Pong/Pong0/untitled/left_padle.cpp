#include "left_padle.h"


Left_padle::Left_padle()
{
    setRect(0,0,5*10,20*10);
    setBrush(QColor(255, 255, 255));
    setFlag(QGraphicsItem::ItemIsFocusable);
    //setPos(0,view->height()-rect->rect().height());
    //setFocus();


}

void Left_padle::init(float x, float y, int width, int height)
{
    this->x = 0;
    this->y= y-rect().height();
    this->width = width;
    this->height = height;
    dy = 0 ;
    setPos(this->x,this->y);
}

void Left_padle::move(int PADDLE_SPEED)
{
    dy=PADDLE_SPEED;

    if(y>0&&PADDLE_SPEED<0){
     y=y+dy;
    }
    else if(PADDLE_SPEED>0&&y<720-20*10){
        y=y+dy;
    }
  setPos(x,y);
      //qDebug()<<y;
}
