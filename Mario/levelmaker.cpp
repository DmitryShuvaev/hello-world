#include "levelmaker.h"

Levelmaker::Levelmaker()
{

}

void Levelmaker::init()
{

    struct Point2
    {
       int x, y;
    };
    struct Point2 arr2[10];
    arr2[0].x = 0;    arr2[1].x = 80; arr2[2].x = 160; arr2[3].x = 240; arr2[4].x = 320;arr2[5].x = 400;
    arr2[0].y = 0;    arr2[1].y = 0;  arr2[2].y = 0;   arr2[3].y = 0;   arr2[4].y = 0;  arr2[5].y = 0;
    int xr2 = qrand() % 5 + 0;
    int yr2 = 0;
    QPixmap pixmap2(":/pic/tile_tops.png");
    //ground
    struct Point
    {
       int x, y;
    };
    struct Point arr[10];
    arr[0].x = 32; arr[1].x = 112; arr[2].x = 192; arr[3].x = 272; arr[4].x = 352;arr[5].x = 432;
    arr[0].y = 0;  arr[1].y = 0;  arr[2].y = 0;    arr[3].y = 0;   arr[4].y = 0;  arr[5].y = 0;
    int xr = qrand() % 5 + 0;
    int yr = 0;
    int brickwidth=16*5;
    int brickhight=16*5;
    //
    int ground=720/3+brickhight;
    int mapHeight=2;
   //

    for(int y=1;y<20;y++){
        //
     for(int x=0;x<20;x++){
         Tile *t=new Tile();
         QRect rect(arr[xr].x, arr[yr].y, 16, 16);
         QPixmap pixmap(":/pic/tiles.png");
         QPixmap  cropped = pixmap.copy(rect);
         QPixmap scaled = cropped.scaled(QSize(brickwidth,brickhight));
         t->setPixmap(scaled);
         t->setPos((brickwidth)*x,720/3+(brickhight*y));
         t->y=720/3+(brickhight*y);
         t->x=(brickwidth)*x;
         groundTiles.push_back(t);

         if(y==1){//top level
             //random chance for a pillar
             int spawnPillar = qrand() % 5 + 0;
             if(spawnPillar==1){
                for(int y=1;y<=mapHeight;y++){
                 Tile *t=new Tile();

                 t->setPixmap(scaled);
                 t->setPos((brickwidth)*x,ground-brickhight*y);
                 t->y=ground-brickhight*y;
                 t->x=(brickwidth)*x;
                 tiles.push_back(t);

                 //top ground
                 QRect rect2(arr2[xr2].x, arr2[yr2].y, 16, 7);
                 QPixmap  cropped3 = pixmap2.copy(rect2);
                 Tile *top2=new Tile();
                 cropped3= cropped3.scaled(QSize(16*5, 7*5));
                 top2->setPixmap(cropped3);
                 top2->setPos(x*(16*5),ground-brickhight*mapHeight);

                 top2->y=ground-brickhight*mapHeight;
                 top2->x=x*(16*5);
                 tiles.push_back(top2);

                 }
             }else{
                 QRect rect2(arr2[xr2].x, arr2[yr2].y, 16, 7);
                 QPixmap  cropped3 = pixmap2.copy(rect2);
                 Tile *top2=new Tile();
                 cropped3= cropped3.scaled(QSize(16*5, 7*5));
                 top2->setPixmap(cropped3);
                 top2->setPos(x*(16*5),720/3+(16*5));
                 top2->setZValue(1);
                 top2->y=720/3+(16*5);
                 top2->x=x*(16*5);
                 top2->TILE_ID_GROUND=true;
                 groundTiles.push_back(top2);


             }
         }
     }
    }

}

void Levelmaker::addtoScene(QGraphicsScene *scene)
{
    for(int i=0;i<tiles.size();i++){
        if(tiles[i]->scene()==0)
        scene->addItem(tiles[i]);
    }

}

void Levelmaker::addtoSceneGroundTiles(QGraphicsScene *scene)
{
    for(int i=0;i<groundTiles.size();i++){
        if(groundTiles[i]->scene()==0)
        scene->addItem(groundTiles[i]);
    }
   //
addSnail(scene);
}
void Levelmaker::setTilesx(float x){
    for(int i=0;i<tiles.size();i++){
 if(tiles[i]->scene()!=0){
      tiles[i]->x= tiles[i]->x+x;
      tiles[i]->setX(tiles[i]->x);
 }
}
    for(int i=0;i<groundTiles.size();i++){
 if(groundTiles[i]->scene()!=0){
       groundTiles[i]->x= groundTiles[i]->x+x;
       groundTiles[i]->setX(groundTiles[i]->x);
 }
    }
    snail->setX(snail->x()+x);
}

void Levelmaker::addSnail(QGraphicsScene *scene)
{

    bool groundFound = false;
      for(int i=0;i<groundTiles.size();i++){

          if(!groundFound && groundTiles[i]->TILE_ID_GROUND==true){
             if(groundTiles[i]->x>800){
             snail=new Snail();
             snail->setX(groundTiles[i]->x);
              if(snail->scene()==0)scene->addItem(snail);
              groundFound=true;
             }
          }
      }

}
bool Levelmaker::collidesLeftSnail()
{

 for(int i=0;i<tiles.size();i++){
     if(snail->x()<tiles[i]->x+tiles[i]->pixmap().width()+2&&
        snail->x()>tiles[i]->x &&
        snail->y()+snail->pixmap().height()>tiles[i]->y
       // character->y()+character->pixmap().height()<=ml.tiles[i]->y+ml.tiles[i]->pixmap().height()
             ){
        qDebug()<<"col left snail";
        snail->setX(tiles[i]->x+tiles[i]->pixmap().width());//-value
         return true;
     }
 }
 return false;
}
bool Levelmaker::collidesRightSnail()
{
    for(int i=0;i<tiles.size();i++){
        if(snail->x()+snail->pixmap().width()>tiles[i]->x-2&&
           snail->x()+snail->pixmap().width()<tiles[i]->x+tiles[i]->pixmap().width()&&
           snail->y()+snail->pixmap().height()>tiles[i]->y ){
           qDebug()<<"col right snail";
           snail->setX(tiles[i]->x-snail->pixmap().width());
            return true;
        }
    }
       return false;
}
void Levelmaker::update_Snail(int dir){
 if(dir==1){
 //moving left
    if(collidesLeftSnail()&&moving){
        snail->movingDirection=2;
        return;
    }
     snail->setX(snail->x()-0.5);
     snail->move();

 }else if(dir==2){
     if(collidesRightSnail()&&moving){
       snail->movingDirection=1;
       return;
     }
     snail->setX(snail->x()+0.5);
     snail->move();
     }

}

void Levelmaker::updateTiles(bool dir)
{
    for(int i=0;i<tiles.size();i++){
      if(dir==true){
       tiles[i]->x=tiles[i]->x+2;
       tiles[i]->setX( tiles[i]->x);

      }
      else{
       tiles[i]->x=tiles[i]->x-2;
       tiles[i]->setX( tiles[i]->x);

      }
    }
    for(int i=0;i<groundTiles.size();i++){
      if(dir==true){
       groundTiles[i]->x=groundTiles[i]->x+2;
       groundTiles[i]->setX( groundTiles[i]->x);

      }
      else{
       groundTiles[i]->x=groundTiles[i]->x-2;
       groundTiles[i]->setX( groundTiles[i]->x);
      }
    }
    //update snail
    if(dir==true){
       snail->setX(snail->x()+2);
    }else{
       snail->setX(snail->x()-2);
    }
}

void Levelmaker::deletTiles(QGraphicsScene *scene)
{
     for(int i=0;i<tiles.size();i++){
         if(tiles[i]->scene()!=0)
         {
         scene->removeItem(tiles[i]);
         tiles.remove(i);

         }
     }
     if(tiles.size()>0)deletTiles(scene);
     if(snail->scene()!=0)scene->removeItem(snail);
}

void Levelmaker::deletgroundTiles(QGraphicsScene *scene)
{
    for(int i=0;i<groundTiles.size();i++){
        if(groundTiles[i]->scene()!=0)
        {
        scene->removeItem(groundTiles[i]);
        groundTiles.remove(i);

        }
    }
    if(groundTiles.size()>0)deletgroundTiles(scene);
}
