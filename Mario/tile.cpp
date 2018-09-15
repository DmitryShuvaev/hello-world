#include "tile.h"

Tile::Tile(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
/*
    QPixmap pixmap(":/pic/tiles.png");
    setPixmap(pixmap);
      pixmap= pixmap.scaled(QSize(32*4, 32*4));
    x=pixmap.width() / 2;
    y=pixmap.height() / 2;
    setPos(0,0);
    */
    x=0;y=0;
}
