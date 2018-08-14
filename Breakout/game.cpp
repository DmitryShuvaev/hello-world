#include "game.h"

Game::Game()
{

    scene=new MyScene();

    view=new QGraphicsView();

    view->setViewport(new QOpenGLWidget());

    view->setRenderHint(QPainter::Antialiasing);

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setScene(scene);

    view->setFixedSize(scene->sceneRect().size().toSize());

    view->show();
}
