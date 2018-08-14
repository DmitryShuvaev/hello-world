#ifndef SOUNDS_H
#define SOUNDS_H
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QVector>


class Sounds
{
public:
    Sounds();
    //QMediaPlayer*player[10];
    QVector<QMediaPlayer*>player;
     QMediaPlaylist *playlist;
};

#endif // SOUNDS_H
