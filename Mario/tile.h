#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>


class Tile: public QGraphicsPixmapItem
{
public:
    Tile(QGraphicsItem *parent = 0);
    bool TILE_ID_GROUND=false;
    int x,y;
};

#endif // TILE_H
