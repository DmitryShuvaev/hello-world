#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QApplication>
#include <QMediaPlayer>
#include <QTimer>
#include <QVector>
#include "constants.h"
#include "title.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "levelmaker.h"
#include "health.h"
#include "exploid.h"

class MyScene: public QGraphicsScene,public Constants
{

public:
    MyScene(QObject *parent = 0);

    enum class States {

      play, serve, game_over

    };
    void clearBricks();
    void addBricks();
    void serve();
    void addHealth();
    States state;
public slots:
    void update();
     void startBall();
private:
    void initPlayField();
    QGraphicsPixmapItem *background;
 void keyPressEvent(QKeyEvent *event);
 void keyReleaseEvent(QKeyEvent *event);
    Title *title;
    Title *hirgh_scores;
    Title *start;
    bool canMoove=false;

    //
    //whether we're highlighting "Start" or "High Scores"
     int highlighted = 1;
    Paddle* paddle;
    Ball*ball;
    int healthSize=3;
    Health health[3];
    QTimer*timer;
    QTimer*timerBall;
  QVector<Brick*>bricks;
};

#endif // MYSCENE_H
