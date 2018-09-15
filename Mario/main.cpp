
#include "myscene.h"

#include <QApplication>
#include <QOpenGLWidget>
#include <QtOpenGL/QGLWidget>
#include <QGraphicsView>



int main(int argc, char *argv[])

{

    QApplication a(argc, argv);

    MyScene  *scene=new MyScene();
    QGraphicsView  *view=new QGraphicsView();
      view->setViewport(new QOpenGLWidget());
      view->setRenderHint(QPainter::Antialiasing);
      view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      view->setScene(scene);
      view->setFixedSize(scene->sceneRect().size().toSize());
      view->show();
    return a.exec();

}
