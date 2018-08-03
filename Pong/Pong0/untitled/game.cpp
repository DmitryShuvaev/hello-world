#include "game.h"
#include "myrect.h"


Game::Game()
{
    scene=new QGraphicsScene();
    //create an item to put into the scene
    MyRect *rect=new MyRect();
    //rect->setRect(0,0,5*10,20*10);
    //rect->setBrush(QColor(255, 255, 255));
    //add the item to the scene
    scene->addItem(rect);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    view=new QGraphicsView(scene);
    view->setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
    rect->setPos(0,view->height()-rect->rect().height());
    scene->addItem(rect->ball->infor);
    scene->addItem(rect->right_padle);
    scene->addItem(rect->left_padle);
    scene->addItem(rect->ball->score);
    scene->addItem(rect->ball);

    view->show();

    //QObject::connect(timer,SIGNAL(timeout()),this,SLOT(keyPressEvent()));


}


