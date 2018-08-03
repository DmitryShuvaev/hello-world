#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QDebug>
#include <QApplication>
#include "ball.h"
#include "right_padle.h"
#include "left_padle.h"
#include "score.h"

class MyRect:public QObject, public QGraphicsRectItem
{
public:
    MyRect();
    void keyPressEvent(QKeyEvent *event);
    Ball *ball;
    Right_padle*right_padle;
    Left_padle*left_padle;


};

#endif // MYRECT_H
