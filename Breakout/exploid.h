#ifndef EXPLOID_H
#define EXPLOID_H
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QParallelAnimationGroup>
#include <QPen>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QGraphicsObject>

class Exploid: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY(QRectF rect READ rect WRITE setRect)
public:
    explicit Exploid(QGraphicsItem *parent = 0);
     void explode(int x,int y);
    bool m_explosion;
};

#endif // EXPLOID_H
