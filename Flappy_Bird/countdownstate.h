#ifndef COUNTDOWNSTATE_H
#define COUNTDOWNSTATE_H
#include <QGraphicsTextItem>
#include "constants.h"
#include <QFont>
#include <QTimer>

class CountdownState:public QGraphicsTextItem,Constants
{
public:
    CountdownState(QGraphicsItem* parent=0);

   // Constants::Player setState();

   void update(int count);
    Constants::Player state;
   public slots:

};

#endif // COUNTDOWNSTATE_H
