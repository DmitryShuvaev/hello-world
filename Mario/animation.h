#ifndef ANIMATION_H
#define ANIMATION_H
#include <QtGlobal>
#include <QDebug>

class Animation
{
public:
    Animation();
   void init(int frames);
   void update(int dt);
   float timer;
   int currentFrame;
   float interval;
   int frames;
};

#endif // ANIMATION_H
