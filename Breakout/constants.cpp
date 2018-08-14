#include "constants.h"
Constants *consv;


Constants::Constants()
{


 //qDebug()<<backgroundWidth;
 if (!QPixmapCache::find("breakout", &original)) {
     original.load(":/graphics/graphics/breakout.png");
     QPixmapCache::insert("breakout", original);

 }
 if (!QPixmapCache::find("background", &bgPixmap)) {
     bgPixmap.load(":/graphics/graphics/background.png");
     scaled = bgPixmap.scaled(QSize(WINDOW_WIDTH+2, WINDOW_HEIGHT+5));
     QPixmapCache::insert("background", bgPixmap);
     backgroundWidth=bgPixmap.width();
 }
  //":/graphics/graphics/breakout.png");



}
float Constants::randNum(int max, int min)

{
    srand(time(NULL)); // Seed the time
    int randNum = rand()%(max-min + 1) + min;

    return randNum;

}
