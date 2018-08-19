#include "constants.h"

Constants consv;
Constants::Constants()
{

}
int Constants::randNum(int max, int min)
{

    srand(time(NULL)); // Seed the time

    int randNum = rand()%(max-min + 1) + min;
qDebug()<<randNum;
    return randNum;

}
