#ifndef LEVELMAKER_H
#define LEVELMAKER_H
#include <QVector>
#include "tile.h"
#include "snail.h"
#include <QGraphicsScene>

class Levelmaker
{
public:
    Levelmaker();
    void init();
    void addtoScene(QGraphicsScene *scene);
     void addtoSceneGroundTiles(QGraphicsScene *scene);
    void updateTiles(bool);
    void deletTiles(QGraphicsScene *scene);
    void deletgroundTiles(QGraphicsScene *scene);
    void setTilesx(float x);
    void addSnail(QGraphicsScene *scene);
    void update_Snail(int dir);
    bool collidesRightSnail();
    bool collidesLeftSnail();
      QVector<Tile*>tiles;
      QVector<Tile*>groundTiles;
       Snail *snail;
       bool chasing=false;
       bool moving=true;
};

#endif // LEVELMAKER_H
