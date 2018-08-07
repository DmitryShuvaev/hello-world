#ifndef CONSTANTS_H
#define CONSTANTS_H


class Constants
{
public:
    Constants();
    enum class Player {
      Invalid, play, stop, CountdownState
    };
   const int VIRTUAL_WIDTH = 512;
   const int VIRTUAL_HEIGHT = 288;
   //height of pipe image, globally accessible
   const float PIPE_HEIGHT = 288;
   const float PIPE_WIDTH = 70;
};

#endif // CONSTANTS_H
