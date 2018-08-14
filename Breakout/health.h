#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>


class Health: public QGraphicsPixmapItem
{
public:
    Health(QGraphicsItem *parent = 0);
    int x = 968;
    int y = 12;
};

#endif // HEALTH_H
