#include "snail.h"

Snail::Snail(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap pixmap(":/pic/creatures.png");
    QRect rect(0, 100, 16, 12);
    QPixmap  cropped = pixmap.copy(rect);
    cropped= cropped.scaled(QSize(16*5, 12*5));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);
    movingDuration=qrand() % 5 + 0;
    snailX=900;
    snailY=320-cropped.height();
    movingDirection = qrand() % 2 + 1;
    setPos(snailX,snailY);
    setZValue(1);
}

void Snail::move()
{
   if(idle==false){
   if(movingTimer>=0&&movingTimer<0.2){
        movingTimer = movingTimer + 0.01;
        currentFrame=2;
    //qDebug()<<timer;
    }
   else if(movingTimer >=0.2&&movingTimer<0.4){
        movingTimer = movingTimer + 0.01;
        currentFrame=1;
    }
   else if(movingTimer >0.4){
        movingTimer =0;
    }
   }
    //************
 if(currentFrame==2){
    setPix(0,100);
 }else if(currentFrame==1){
    setPix(16,100);
 }
 else if(currentFrame==0){
    setPix(32,100);
 }

}
void Snail::setPix(int x,int y)
{
    QPixmap pixmap(":/pic/creatures.png");
    QRect rect(x, y, 16, 12);
    QPixmap  cropped = pixmap.copy(rect);
    cropped= cropped.scaled(QSize(16*5, 12*5));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);
    QTransform transform;
    if (movingDirection ==2) {
       transform.scale(-1, 1);
       transform.translate(-this->pixmap().width(),0);
    }
     setTransform(transform);

}

