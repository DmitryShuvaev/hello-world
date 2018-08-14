#include "sounds.h"
Sounds sound;

Sounds::Sounds()
{
    if(player.size()==0){
   playlist = new QMediaPlaylist();
   playlist->addMedia(QUrl("qrc:/sounds/sounds/paddle_hit.wav"));
   playlist->addMedia(QUrl("qrc:/sounds/sounds/confirm.wav"));
    player.push_back(new QMediaPlayer());
    player.push_back(new QMediaPlayer());
    player.push_back(new QMediaPlayer());
    player.push_back(new QMediaPlayer());
    player.push_back(new QMediaPlayer());
    player.push_back(new QMediaPlayer());
    player.push_back(new QMediaPlayer());
    player[0]->setMedia(QUrl("qrc:/sounds/sounds/paddle_hit.wav"));
    player[1]->setMedia(QUrl("qrc:/sounds/sounds/confirm.wav"));
    player[2]->setMedia(QUrl("qrc:/sounds/sounds/paddle_hit.wav"));
    player[3]->setMedia(QUrl("qrc:/sounds/sounds/wall_hit.wav"));
    player[4]->setMedia(QUrl("qrc:/sounds/sounds/brick-hit-2.wav"));
    player[5]->setMedia(QUrl("qrc:/sounds/sounds/hurt.wav"));
    player[6]->setMedia(QUrl("qrc:/sounds/sounds/brick-hit-1.wav"));
    //qDebug()<<"in player";
     //qDebug()<<(sizeof(player));
  }
}
