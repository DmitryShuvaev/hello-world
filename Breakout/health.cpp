#include "health.h"

Health::Health(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QRect rect(128, 48, 10, 10);
    QPixmap  original(":/graphics/graphics/breakout.png");
    QPixmap  cropped = original.copy(rect);
    cropped= cropped.scaled(QSize(30, 30));
    setPixmap(cropped);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setPos(x,y);

}
