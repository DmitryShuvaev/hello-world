#include "pipepair.h"

PipePair::PipePair()
{
 upper=new Pipe();
 lower=new Pipe();
 scored=false;
}

void PipePair::init(float y)
{
    //initialize pipes past the end of the screen

    //y value is for the topmost pipe; gap is a vertical shift of the second lower pipe
    this->y = y;
    upper->init(y);
    upper->setDirection(-1);
    lower->init(y + GAP_HEIGHT);
    lower->setDirection(1);
    x = upper->x;
    //qDebug() <<y;
}

void PipePair::update()
{
 upper->update();
 lower->update();
  x = upper->x;
}
