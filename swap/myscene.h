#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QDateTime>
#include <QTimer>
#include <QString>
#include <typeinfo>
#include <QKeyEvent>
#include <QPropertyAnimation>
#include "constants.h"
#include "Board.h"
#include "myrect.h"

extern Constants consv;


class MyScene: public QGraphicsScene
{
public:
    MyScene(QObject *parent = 0);
    struct Dist{
        int x=0;int y=0;bool reached=false;
    };
 void keyPressEvent(QKeyEvent *event);
void calculateMatches();
void getFallingTiles(int pos,int x);
void emptySels();
void makeTile(int x,int y);
public slots:

    void update();
    //var
     const static int sizex=12,sizey=9;
     Board *board[sizey][sizex];
     QTimer timer;
     //Dist destinations[5];

MyRect *selectedTile;
int yp=0;
int xp=0;
bool highlightedTile=false;
int highlightedX=0, highlightedY=0;
int conter=0;

};

#endif // MYSCENE_H
