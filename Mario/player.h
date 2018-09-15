#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "levelmaker.h"


class Player: public QGraphicsPixmapItem
{
public:
    Player(QGraphicsItem *parent = 0);
    bool checkX(Levelmaker *ml);
    bool checkY(Levelmaker *ml, float characterDY);
    void jump(float jumtimer,Levelmaker *ml);
    void setjumpPixmap(int x);
    void setDir(int);
    void setPix(int x,int y);
    void setTilesx(Levelmaker *ml,float x);
    int  characterX;
    float characterY;
    int m_direction;
    float timer=0;
    float characterDY=-10;
     int GRAVITY=2;
};

#endif // PLAYER_H
