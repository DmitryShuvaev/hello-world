#ifndef STATUSINFOR_H
#define STATUSINFOR_H
#include <QGraphicsTextItem>
#include <QFont>

class StatusInfor:public QGraphicsTextItem
{
public:
    StatusInfor(QGraphicsItem* parent=0);
    void update(QString st1,QString st2);
};

#endif // STATUSINFOR_H
