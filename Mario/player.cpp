#include "player.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    QPixmap pixmap(":/pic/character.png");
    QRect rect(0, 0, 16, 20);
    QPixmap  cropped = pixmap.copy(rect);
    cropped= cropped.scaled(QSize(16*5, 20*5));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);
    m_direction=0;
    characterX=1280/2-(cropped.width() / 2);
    characterY=220-cropped.height();

    setPos(characterX,characterY);
    setZValue(1);
}

bool Player::checkX(Levelmaker *ml)
{
    for(int i=0;i<ml->tiles.size();i++){
        if(m_direction<0){
        if(this->x()<ml->tiles[i]->x+ml->tiles[i]->pixmap().width()&&
           this->x()>ml->tiles[i]->x &&
           this->y()+this->pixmap().height()>ml->tiles[i]->y
          // this->y()+this->pixmap().height()<=ml->tiles[i]->y+ml->tiles[i]->pixmap().height()
                ){
       // setTilesx(ml,(float)this->x()-ml->tiles[i]->pixmap().width());
          // this->setX(ml->tiles[i]->x+ml->tiles[i]->pixmap().width());
            return true;
        }
        }else if(m_direction>0){
            if(this->x()+this->pixmap().width()>ml->tiles[i]->x&&
               this->x()+this->pixmap().width()<ml->tiles[i]->x+ml->tiles[i]->pixmap().width()&&
               this->y()+this->pixmap().height()>ml->tiles[i]->y
              // this->y()+this->pixmap().height()<=ml->tiles[i]->y+ml->tiles[i]->pixmap().height()
                    ){
          //  setTilesx(ml,this->x()+this->pixmap().width());
             //   this->setX(ml->tiles[i]->x-this->pixmap().width());
                return true;
            }
        }

    }
    return false;
}

bool Player::checkY(Levelmaker *ml, float characterDY)
{

    for(int i=0;i<ml->tiles.size();i++){
        if(this->y()+this->pixmap().height()+characterDY>ml->tiles[i]->y&&
           this->x()<ml->tiles[i]->x+ml->tiles[i]->pixmap().width()&&
           this->x()>ml->tiles[i]->x-80 &&
           this->y()+this->pixmap().height()+characterDY<ml->tiles[i]->y+ml->tiles[i]->pixmap().height()
              ){
               this->setY(ml->tiles[i]->y-this->pixmap().height());
            characterY=this->y();
            qDebug()<<"col y";
            return true;
        }
    }

    for(int i=0;i<ml->groundTiles.size();i++){
        if(this->y()+this->pixmap().height()+characterDY>ml->groundTiles[i]->y&&
           this->x()<=ml->groundTiles[i]->x+ml->groundTiles[i]->pixmap().width()&&
           this->x()>=ml->groundTiles[i]->x &&
           this->y()+this->pixmap().height()+characterDY<ml->groundTiles[i]->y+ml->groundTiles[i]->pixmap().height()
              ){
               this->setY(ml->groundTiles[i]->y-this->pixmap().height());
               characterY=this->y();
            return true;
        }
}

    return false;
}
void setTilesx(Levelmaker *ml,float x){
    for(int i=0;i<ml->tiles.size();i++){

       ml->tiles[i]->x=x;
       ml->tiles[i]->setX( ml->tiles[i]->x);
}
    for(int i=0;i<ml->groundTiles.size();i++){

     //  ml->groundTiles[i]->x=x;
     //  ml->groundTiles[i]->setX( ml->tiles[i]->x);
}
}

void Player::jump(float jumtimer,Levelmaker *ml)
{

    characterDY = (characterDY)+GRAVITY*jumtimer;
    //check x
    //if(check x==false)check y

      qDebug()<<m_direction;
      if(checkY(ml,characterDY)==false){
  //characterDY=0;
 characterY = characterY + characterDY;
      }


    setY(characterY);
   // qDebug()<<characterY;

}

void Player::setjumpPixmap(int x)
{
    QPixmap pixmap(":/pic/character.png");
    QRect rect(x, 0, 16, 20);
    QPixmap  cropped = pixmap.copy(rect);
    cropped= cropped.scaled(QSize(16*5, 20*5));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Player::setDir(int direction)
{
    m_direction = direction;
     if (m_direction != 0) {
         QTransform transform;
         if (m_direction < 0) {
            transform.scale(-1, 1);
            transform.translate(-pixmap().width(),0);
         }
          setTransform(transform);
     }
}

void Player::setPix(int x,int y)
{
    QPixmap pixmap(":/pic/character.png");
    QRect rect(x, y, 16, 20);
    QPixmap  cropped = pixmap.copy(rect);
    cropped= cropped.scaled(QSize(16*5, 20*5));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);

}
