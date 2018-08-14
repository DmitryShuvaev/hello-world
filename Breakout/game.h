#ifndef GAME_H
#define GAME_H

#include <QtOpenGL/QtOpenGL>
#include <QGraphicsView>

#include "myscene.h"

class Game
{
public:
    Game();

    MyScene *scene;
    QGraphicsView *view;
};

#endif // GAME_H
