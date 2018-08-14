#ifndef LEVELMAKER_H
#define LEVELMAKER_H
#include "brick.h"
#include "constants.h"
#include <QVector>
#include <math.h>


class LevelMaker:Constants
{
public:
    LevelMaker();
    QVector<Brick*> makeLevel(int);
     int numRows;
     int numCols;
   QVector<Brick*>bricks;

};

#endif // LEVELMAKER_H
