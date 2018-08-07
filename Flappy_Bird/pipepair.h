#ifndef PIPEPAIR_H
#define PIPEPAIR_H

#include "pipe.h"

class PipePair:public Constants
{
public:
    PipePair();
    void init(float y);
    //size of the gap between pipes
    float GAP_HEIGHT = 90;
    void update();
    float x;
    float y;
    Pipe *upper;
    Pipe *lower;
    bool scored;
};

#endif // PIPEPAIR_H
