#include "myscene.h"



MyScene::MyScene(QObject *parent):QGraphicsScene(parent)
{
 connect(&timer, &QTimer::timeout, this, &MyScene::update);
 setSceneRect(0, 0, 1280, 720);
 // Initialize sequence
 qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
 QPixmap  original(":/pics/match3.png");

 for(int y=0;y<8;y++){

  for(int x=0;x<8;x++){
   int xrand=qrand() % 11 + 0;;
   int yrand=qrand() % 8 + 0;;
   //assign a random ID to tile to make it a random tile
   //
     QRect rect((xrand)* 32, (yrand)* 32, 32, 32);
     QPixmap  *cropped = new QPixmap(original.copy(rect));
     *cropped= cropped->scaled(QSize(32*2, 32*2));
     board[y][x]= new Board();
     board[y][x]->setPixmap(*cropped);
     board[y][x]->xpos=(x*64)+128*3;
     board[y][x]->ypos=(y*64)+32*3;
     board[y][x]->setPos( board[y][x]->xpos,board[y][x]->ypos);
      addItem(board[y][x]);
      board[y][x]->x=xrand;
      board[y][x]->y=yrand;

      //qDebug()<<board[y][x]->x;
  }
 }
 //delete board[1][1];
// QGraphicsPixmapItem *c = qgraphicsitem_cast<QGraphicsPixmapItem*>(board[1][1]);
 //QGraphicsPixmapItem* enemy = qgraphicsitem_cast<QGraphicsPixmapItem*> (board[1][1]);
    //if(enemy)removeItem(board[1][1]);
  //if(QGraphicsPixmapItem *c != qgraphicsitem_cast<QGraphicsPixmapItem*>(board[1][1]))  removeItem(board[1][1]);
if(board[1][1]==NULL){
 removeItem(board[1][1]);

}
//removeItem(board[1][1]);

//currently selected tile, changed with arrow keys
   // selectedTile = board[6][0];
selectedTile=new MyRect();
selectedTile->init(board[yp][xp]->xpos,board[yp][xp]->ypos);
addItem(selectedTile);

}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up){
        if(yp>0){
        if(selectedTile->scene()!= 0 ){
         removeItem(selectedTile);
        }
        MyRect *r=new MyRect();
          r->setZValue(1);
        //qDebug()<<"top";
        yp--;
        selectedTile = r;
        r->init(board[yp][xp]->xpos,board[yp][xp]->ypos);
        addItem(r);
        }
    }else if(event->key()==Qt::Key_Down){
        if(yp<7){
        if(selectedTile->scene()!= 0 ){
         removeItem(selectedTile);
        }
        yp++;
        MyRect *r=new MyRect();
          r->setZValue(1);
        selectedTile = r;
        r->init(board[yp][xp]->xpos,board[yp][xp]->ypos);
        addItem(r);
        }
    }else if(event->key()==Qt::Key_Right){
        if(xp<7){
        if(selectedTile->scene()!= 0 ){
         removeItem(selectedTile);
        }
        xp++;
        MyRect *r=new MyRect();
        r->setZValue(1);
        selectedTile = r;
        r->init(board[yp][xp]->xpos,board[yp][xp]->ypos);
        addItem(r);
        }
    }else if(event->key()==Qt::Key_Left){
        if(xp>0){
        if(selectedTile->scene()!= 0){
         removeItem(selectedTile);
         }
        xp--;
        MyRect *r=new MyRect();
          r->setZValue(1);
        selectedTile = r;
        r->init(board[yp][xp]->xpos,board[yp][xp]->ypos);
        addItem(r);
        }
    }else if(event->key()== Qt::Key_Enter||event->key()==Qt::Key_Return){
      timer.start();

    }else if(event->key()== Qt::Key_W){
      // board[yp][xp]->setPos(board[yp][xp]->xpos,board[yp][xp]->ypos);
        // if(board[yp][xp]->scene()!= 0)
        //getFallingTiles(yp,xp);
        // removeItem(board[yp][xp]);
        emptySels();
    }
}

void MyScene::calculateMatches()
{
    //horizontal matches first

    for(int y=0;y<8;y++){

     for(int x=1;x<8;x++){
      if(board[y][x]->x==board[y][x-1]->x  &&
          (board[y][x]->y==board[y][x-1]->y &&
           board[y][x]->x==board[y][x-1]->x &&
           board[y][x]->y==board[y][x-1]->y )){
         //qDebug()<<"match";
         removeItem(board[y][x]);
         removeItem(board[y][x-1]);
        // removeItem(board[y][x-2]);
      }
      if(board[y][x]->scene()== 0){
              //qDebug()<<"nill";

             //getFallingTiles(y,x-1);
      }
     }
    }

    //vertical matches
 for(int x=0;x<8;x++){
   // if(board[0][x]->scene()!= 0){
    int colorToMatchx = board[0][x]->x;
    int colorToMatchy = board[0][x]->y;
    int matchNum=1;

    //every vertical tile
     for(int y=1;y<8;y++){
      if(board[y][x]->x == colorToMatchx && board[y][x]->y == colorToMatchy){
         if(board[y-1][x]->scene()!= 0&&colorToMatchx<12&&colorToMatchx>=0&&colorToMatchy<9&&colorToMatchy>=0)
         matchNum++;
      }else{
        colorToMatchx = board[y][x]->x;
        colorToMatchy = board[y][x]->y;
        if(matchNum >=2){
            int y2 = y - 1;
          for(matchNum; matchNum>=1; matchNum--){
            removeItem(board[y2--][x]);

qDebug()<<"deeleted";

          }
        }
         matchNum=1;
      }

//     }
 }
 }
 emptySels();
}

void MyScene::getFallingTiles(int y,int pos)
{

   //
     for(int x=0;x<8;x++){
         int y=7;
          while(y>0){
                if(board[y-1][x]->scene()!=0&&board[y][x]->scene()== 0) {

                    int xtemp=board[y][x]->xpos;
                    int ytemp=board[y][x]->ypos;

                    Board*b=new Board();
                    b->setPixmap(board[y-1][x]->pixmap());
                    b->setPos(xtemp,ytemp);
                    b->x=board[y-1][x]->x;
                    b->y=board[y-1][x]->y;
                    b->xpos=xtemp;
                    b->ypos=ytemp;

                   removeItem(board[y-1][x]);
                   delete board[y][x];

                     board[y][x]=b;
                     addItem(board[y][x]);
                    if(board[y-1][x]->scene()== 0) {qDebug()<<"dont work";


                    }
                }
                y--;
           }

     }
}

void MyScene::emptySels()
{
    for(int ypos=1;ypos<7;ypos++){

    for(int x=0;x<8;x++){
        int y=ypos;
         while(y>0){
               if(board[y-1][x]->scene()!=0&&board[y][x]->scene()== 0) {

                   int xtemp=board[y][x]->xpos;
                   int ytemp=board[y][x]->ypos;

                   Board*b=new Board();
                   b->setPixmap(board[y-1][x]->pixmap());
                   b->setPos(xtemp,ytemp);
                   b->x=board[y-1][x]->x;
                   b->y=board[y-1][x]->y;
                   b->xpos=xtemp;
                   b->ypos=ytemp;

                  removeItem(board[y-1][x]);
                  delete board[y][x];

                    board[y][x]=b;
                    addItem(board[y][x]);

               }
               y--;
          }
      }
    }
    //create replacement tiles at the top of the screen
 for(int x=0;x<8;x++){
     for(int y=7;y>=0;y--){
         //if the tile is 0, we need to add a new one
        if(board[y][x]->scene()==0){
        if(board[y][x])
         delete board[y][x];
         makeTile(x,y);
        }
  }
 } //end for loop x

}


void MyScene::update()
{
    //pressing enter highlights a tile if none is highlighted and swaps two tiles
    //if one is already
    if(highlightedTile==false){
        highlightedTile = true;
        highlightedX=xp;highlightedY=yp;
    }else{
       // qDebug()<<"enter";
          //swap tiles

         //unhighlight
         highlightedTile = false;

         QPixmap  pm;
         pm=board[highlightedY][highlightedX]->pixmap();
         int xtemp=board[highlightedY][highlightedX]->x;
         int ytemp=board[highlightedY][highlightedX]->y;
         //swap


        board[highlightedY][highlightedX]->setPixmap(board[yp][xp]->pixmap());
        board[highlightedY][highlightedX]->x= board[yp][xp]->x;
        board[highlightedY][highlightedX]->y= board[yp][xp]->y;
        board[yp][xp]->setPixmap(pm);
        board[yp][xp]->x=xtemp;
        board[yp][xp]->y=ytemp;

    }
calculateMatches();

timer.stop();
}

void MyScene::makeTile(int x, int y)
{
    //qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    QPixmap  original(":/pics/match3.png");
    int xrand=qrand() % 11 + 0;;
    int yrand=qrand() % 8 + 0;;
    //assign a random ID to tile to make it a random tile
    //
      QRect rect((xrand)* 32, (yrand)* 32, 32, 32);
      QPixmap  *cropped = new QPixmap(original.copy(rect));
      *cropped= cropped->scaled(QSize(32*2, 32*2));
      board[y][x]= new Board();
      board[y][x]->setPixmap(*cropped);
      board[y][x]->xpos=(x*64)+128*3;
      board[y][x]->ypos=(y*64)+32*3;
      board[y][x]->setPos( board[y][x]->xpos,board[y][x]->ypos);
       addItem(board[y][x]);
       board[y][x]->x=xrand;
       board[y][x]->y=yrand;
}

