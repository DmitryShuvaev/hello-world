#ifndef TITLE_H
#define TITLE_H

#include <QGraphicsTextItem>
#include "constants.h"
#include <QFont>

class Title:public QGraphicsTextItem,Constants
{
public:
    Title(QGraphicsItem* parent=0);
    void init(QString title,int y,int fontSize);
    QString title;
};

#endif // TITLE_H
