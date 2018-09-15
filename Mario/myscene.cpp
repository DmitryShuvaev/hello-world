#include "myscene.h"

MyScene::MyScene(QObject *parent):QGraphicsScene(parent)
{
 //size of our actual window
 setSceneRect(0, 0, 1280, 720);
 qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
 int backgroundR = qrand() % 255 + 0;
 int backgroundG = qrand() % 255 + 0;
 int backgroundB = qrand() % 255 + 0;
 setBackgroundBrush(QBrush(QColor(backgroundR, backgroundG, backgroundB, 255), Qt::SolidPattern));

 ml.init();
 ml.addtoScene(this);
 ml.addtoSceneGroundTiles(this);

  character=new Player();
  addItem(character);
  //snail

   an.init(2);
   timer=new QTimer();
   fallTimer=new QTimer();

   connect(timer, &QTimer::timeout, this, &MyScene::update);
   //
   timer->start();
}
void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsScene::mouseMoveEvent(event);

}
void MyScene::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return;

    }
    if(event->key()==Qt::Key_Left){

        character->setDir(-1);

    }else if(event->key()==Qt::Key_Right){

         character->setDir(1);

    }else if(event->key()==Qt::Key_Space){
     // characterDY = JUMP_VELOCITY;
       jumtimer=0;
      jumpAnimation=true;
       an.currentFrame=3;
      character->characterDY=-10;
    }else if(event->key()==Qt::Key_R){
        //delete all items
        ml.deletTiles(this);
        ml.deletgroundTiles(this);

        ml.init();
        ml.addtoScene(this);
        ml.addtoSceneGroundTiles(this);
      }
}

void MyScene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return;

    }
    switch (event->key()) {

    case Qt::Key_Left:
    case Qt::Key_Right:
     character->setDir(0);

        break;

    }
}

void MyScene::generateToptiles( QGraphicsPixmapItem *tile)
{


}

void MyScene::generatetiles(QGraphicsPixmapItem *tile)
{

}

void MyScene::SnailMovingState()
{
    if(ml.moving){
     SnailMove();
    }else if(ml.chasing){
     SnailChaise();
    }
//calculate difference between snail and player on X axis
    // and only chase if <= 5 tiles
    int diffX = std::abs(character->x() - ml.snail->x());
    if(diffX<200){
        //chasing
     qDebug()<<"chasing";
     ml.chasing=true;
     ml.moving=false;
    }else{
     ml.moving=true;
     ml.chasing=false;
    }

}

void MyScene::SnailMove()
{
    ml.snail->movingTimerState=ml.snail->movingTimerState+0.01;
    // reset movement direction and timer if timer is above duration

    if(ml.snail->movingTimerState > ml.snail->movingDuration){
      // qDebug()<<"time";
       //chance to go into idle state randomly
       if(qrand() % 5 + 0==1){
          qDebug()<<"idle";
          ml.snail->idle=true;
          ml.snail->currentFrame=0;
          ml.snail->setPix(32,100);
          ml.snail->movingTimerState=0;
          ml.snail->movingDuration=qrand() % 5 + 1;
       }else{
          ml.snail->idle=false;
          ml.snail->movingTimerState=0;
          ml.snail->movingDuration= qrand() % 5 + 0;
          ml.snail->movingDirection = qrand() % 2 + 1;
       }
    }
    if(ml.snail->idle==false)
        ml.update_Snail(ml.snail->movingDirection);
}

void MyScene::SnailChaise()
{
  ml.snail->idle=false;
 if(character->x()<ml.snail->x()){
     ml.snail->movingDirection=1;

 }else{
    ml.snail->movingDirection=2;
 }
  ml.update_Snail(ml.snail->movingDirection);
}

bool MyScene::collidesLeft()
{

 for(int i=0;i<ml.tiles.size();i++){
     if(character->x()<ml.tiles[i]->x+ml.tiles[i]->pixmap().width()+2&&
        character->x()>ml.tiles[i]->x &&
        character->y()+character->pixmap().height()>ml.tiles[i]->y
       // character->y()+character->pixmap().height()<=ml.tiles[i]->y+ml.tiles[i]->pixmap().height()
             ){
        //qDebug()<<"col left";
        ml.setTilesx(character->x()-(ml.tiles[i]->x+ml.tiles[i]->pixmap().width()));//-value
         return true;
     }
 }
    return false;
}

bool MyScene::collidesRight()
{
//
    for(int i=0;i<ml.tiles.size();i++){
        if(character->x()+character->pixmap().width()>ml.tiles[i]->x-2&&
           character->x()+character->pixmap().width()<ml.tiles[i]->x+ml.tiles[i]->pixmap().width()&&
           character->y()+character->pixmap().height()>ml.tiles[i]->y ){
           qDebug()<<"col right";
           ml.setTilesx(character->x()+character->pixmap().width()-ml.tiles[i]->x);
            return true;
        }
    }
       return false;

}

bool MyScene::collidesTop()
{
    for(int i=0;i<ml.tiles.size();i++){
        if(character->y()+character->pixmap().height()+character->characterDY>ml.tiles[i]->y&&
           character->x()<ml.tiles[i]->x+ml.tiles[i]->pixmap().width()-5&&
           character->x()>ml.tiles[i]->x-70 &&
           character->y()+character->pixmap().height()+characterDY<ml.tiles[i]->y+ml.tiles[i]->pixmap().height()
              ){
               character->setY(ml.tiles[i]->y-character->pixmap().height());
           character->characterY=character->y();
//            qDebug()<<"col y";
            return true;
        }
    }

    for(int i=0;i<ml.groundTiles.size();i++){
        if(character->y()+character->pixmap().height()+character->characterDY>ml.groundTiles[i]->y&&
           character->x()<=ml.groundTiles[i]->x+ml.groundTiles[i]->pixmap().width()&&
           character->x()>=ml.groundTiles[i]->x-80 &&
           character->y()+character->pixmap().height()+character->characterDY<ml.groundTiles[i]->y+ml.groundTiles[i]->pixmap().height()
              ){
               character->setY(ml.groundTiles[i]->y-character->pixmap().height());
               character->characterY=character->y();
            return true;
        }
}

    return false;
}

bool MyScene::colid()
{/*
    for(QGraphicsItem* item: collidingItems(character)) {
        Tile *c = qgraphicsitem_cast<Tile*>(item);
           if(typeid(*(c))==typeid(Tile)){

               return true;
             }
           }
      */
    return false;
}


bool MyScene::collidesLeftSnail()
{

 for(int i=0;i<ml.tiles.size();i++){
     if(ml.snail->x()<ml.tiles[i]->x+ml.tiles[i]->pixmap().width()+2&&
        ml.snail->x()>ml.tiles[i]->x &&
        ml.snail->y()+ml.snail->pixmap().height()>ml.tiles[i]->y
       // character->y()+character->pixmap().height()<=ml.tiles[i]->y+ml.tiles[i]->pixmap().height()
             ){
        qDebug()<<"col left snail";
        ml.snail->setX(ml.tiles[i]->x+ml.tiles[i]->pixmap().width());//-value
         return true;
     }
 }
 return false;
}

bool MyScene::collidesRightSnail()
{
    for(int i=0;i<ml.tiles.size();i++){
        if(ml.snail->x()+ml.snail->pixmap().width()>ml.tiles[i]->x-2&&
           ml.snail->x()+ml.snail->pixmap().width()<ml.tiles[i]->x+ml.tiles[i]->pixmap().width()&&
           ml.snail->y()+ml.snail->pixmap().height()>ml.tiles[i]->y ){
           qDebug()<<"col right snail";
           ml.snail->setX(ml.tiles[i]->x-ml.snail->pixmap().width());
            return true;
        }
    }
       return false;
}
void MyScene::update()
{

    SnailMovingState();

    if(jumpAnimation){

    if(character->m_direction>0){
     if(!collidesRight())
      ml.updateTiles(false);
    }
    else if(character->m_direction<0){
    if(!collidesLeft())
      ml.updateTiles(true);
    }else {
       an.currentFrame=0;
    }

    if(character->checkY(&ml,character->characterDY)==false){
        jumtimer+=0.01;
        character->jump(jumtimer,&ml);
//        timer->stop();
//        qDebug()<<character->characterDY;
    //    qDebug()<<character->y();
    }else{
        jumtimer=0;
       jumpAnimation=false;
       character->characterDY=0;
//timer->stop();
    }

    }

   if(jumpAnimation==false){
        jumtimer+=0.2;
   character->characterDY=dyFall*jumtimer;

       if(collidesTop()==false){
       //qDebug()<<"character check y";
             if( character->characterDY>0){
                if(collidesRight()){
                  qDebug()<<"fallng r";
//                    ml.setTilesx(character->x+character->pixmap().width()-);
                }

                   else if(collidesLeft()){
                         qDebug()<<"fallng l";
                                      }

             }
   character->setY(character->y()+character->characterDY);
 //  if(character->m_direction>0)
 //  ml.setTilesx(-5);
        dyFall=2;

       }else{
           dyFall=0;
           jumtimer=0;

            // qDebug()<<character->characterDY;
         //  character->characterDY=0;

       }

       //*************

       if(character->m_direction>0){

        if(!collidesRight())
         ml.updateTiles(false);
       }
       else if(character->m_direction<0){
        if(!collidesLeft())
         ml.updateTiles(true);

       }else {
          an.currentFrame=0;
       }

       //************
    if(an.currentFrame==2){
       an.update(1);
      character->setPix(16*10,0);
    }else if(an.currentFrame==1){
       an.update(1);
      character->setPix(16*9,0);
    }
    else if(an.currentFrame==0){
       an.update(1);
       character->setPix(0,0);
    }
   }else{
       if(an.currentFrame==3){
        character->setjumpPixmap(16*2);
        an.update(1);
       }else if(character->m_direction==0){
        character->setjumpPixmap(0);
       }
   }

}
