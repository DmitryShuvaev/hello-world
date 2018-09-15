#include "animation.h"

Animation::Animation()
{

}

void Animation::init(int frames)
{
    timer = 0;
    currentFrame = 0;
    interval = 0.2;
    this->frames=frames;

}

void Animation::update(int direction)
{
   // if(currentFrame>=2)
    //no need to update if animation is only one frame
    if (frames > 1){

        if(timer>=0&&timer<0.2){
       timer = timer + 0.01;
        currentFrame=2;
        //qDebug()<<timer;
        }
       else if(timer >=0.2&&timer<0.4){

//currentFrame=qBound(1, (currentFrame + 1) % (frames + 1),2);
          timer = timer + 0.01;
         currentFrame=1;
            //currentFrame = math.max(1, (currentFrame + 1) % (frames + 1));
        }
         else if(timer >0.4){
         timer =0;
         }

    }
}
