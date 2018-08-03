#ifndef BALL_H
#define BALL_H
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include "right_padle.h"
#include <typeinfo>
#include <QDebug>
#include <time.h>
#include "left_padle.h"
#include "score.h"
#include "statusinfor.h"
#include <QString>
#include <QMediaPlayer>

class Ball:public QObject,public QGraphicsEllipseItem
{
 Q_OBJECT
public:
    Ball();
    void start();
    void reset();
    QString gameState;
      Score *score;
      StatusInfor*infor;
      QMediaPlayer*player;
      int servingPlayer;
      int winningPlayer;
public slots:
    void move();
    void collides();

private:
     QTimer*timer;
     float ballDX;
     float ballDY;
     float ballX;
     float ballY;

};

#endif // BALL_H
