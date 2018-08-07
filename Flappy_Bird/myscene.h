#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QApplication>
#include <QElapsedTimer>
#include <QVector>
#include "constants.h"
#include "bird.h"
#include "pipepair.h"
#include <typeinfo>
#include "title.h"
#include "score.h"
#include <time.h>
#include "countdownstate.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPointer>

class MyScene: public QGraphicsScene,public Constants
{
public:
    MyScene(QObject *parent = 0);
    void keyPressEvent(QKeyEvent *event);

    float randNum(int max,int min);
    void collides();
    void play();
    void gameStatus();
    void ScoreCheck(PipePair *pair);
private slots:
     void move();
     void update();
     void playscore();
signals:
     void playmp3background();
private:
    void initPlayField();
    void clearCallBack();
    QGraphicsPixmapItem *background;
    QGraphicsPixmapItem *ground;
    int spawnTimer;
    QElapsedTimer timer;
    int HORIZONTAL_GAP;
    float backgroundScroll;
    float groundScroll;
    //point at which we should loop our background back to X 0
    float BACKGROUND_LOOPING_POINT = 413;
    QTimer m_timer;
    QTimer timer1;
    QTimer timer2;
    float BACKGROUND_SCROLL_SPEED = 0.05;
    Bird*bird;
    QVector<PipePair*>pipePairs;
    float lastY=0;
    Title *title;
    Title *titleEnter;
    Title *scoreTitel;
     Constants::Player state;
     Score*score;
     CountdownState *s;
      int count;
      bool colis;
      QMediaPlayer*player;
      QMediaPlayer*jumping;
      QMediaPlaylist *playlist;
      QMediaPlaylist *playlist2;
      QPointer <QMediaPlayer> mp3backgroundplayer;
};

#endif // MYSCENE_H
