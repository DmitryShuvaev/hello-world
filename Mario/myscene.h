#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <cmath>        // std::abs
#include <typeinfo>
#include "tile.h"
#include "player.h"
#include "animation.h"
#include "levelmaker.h"
#include "snail.h"

class MyScene: public QGraphicsScene
{
 public:
    MyScene(QObject *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void generateToptiles(QGraphicsPixmapItem *tile);
    void generatetiles(QGraphicsPixmapItem *tile);
    void SnailMovingState();
    void SnailMove();
    void SnailChaise();
     bool collidesLeftSnail();
     bool collidesRightSnail();
    bool collidesLeft();
    bool collidesRight();
    bool collidesTop();
    bool colid();

public slots:
    void update();

    QGraphicsPixmapItem*tile;
    Player *character;
   QTimer*  timer;
    QTimer*  fallTimer;
   Animation an;
   float characterDY=0;
   int JUMP_VELOCITY = -200;
   int GRAVITY=1;
   bool jumpAnimation=false;
   float jumtimer=0;
   int tileofset=32;
   float dyFall=2;
   bool colleft=false;
   bool falling=false;
   Levelmaker ml;

};

#endif // MYSCENE_H
