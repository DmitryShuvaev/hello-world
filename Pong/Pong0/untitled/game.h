#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include "ball.h"

class Game:public QObject
{
  Q_OBJECT
public:
    Game();

//public slots:

private:
   int WINDOW_WIDTH = 1280;
   int WINDOW_HEIGHT = 720;
    QGraphicsView *view;
    QGraphicsScene * scene;

};

#endif // GAME_H
