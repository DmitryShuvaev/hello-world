#ifndef BIRD_H
#define BIRD_H
#include <QGraphicsPixmapItem>

class Board: public QGraphicsPixmapItem
{
public:
    Board(QGraphicsItem *parent = 0);

    int tile = 0;
    int x=0;
    int y=0;
    int xpos=0;
    int ypos=0;
    void init(int,int);


};

#endif // BIRD_H


