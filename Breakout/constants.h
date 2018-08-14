#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QGraphicsPixmapItem>

#include <QDebug>
#include <QPixmapCache>

#include <QVector>
#include <time.h>

class Constants
{
public:
    Constants();
    float randNum(int max, int min);
    int backgroundWidth ;
    int backgroundHeight;
    //size of our actual window
    int WINDOW_WIDTH = 1280;
    int WINDOW_HEIGHT = 720;
    //paddle movement speed
  const  int PADDLE_SPEED = 20;
    //size we're trying to emulate with push
    int VIRTUAL_WIDTH = 432;
    int VIRTUAL_HEIGHT = 243;
    QPixmap bgPixmap;
     QPixmap original;
    //
    QPixmap scaled ;

};

#endif // CONSTANTS_H
