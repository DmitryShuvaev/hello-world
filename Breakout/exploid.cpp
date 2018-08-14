#include "exploid.h"

Exploid::Exploid(QGraphicsItem *parent) :
    QGraphicsEllipseItem(parent)
{
 m_explosion=false;

}
void Exploid::explode(int x,int y)
{

     setBrush(QColor(252, 253, 151));
     setRect(x, y, 50, 50);

       QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
      //QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);

       QPropertyAnimation *scaleAnimation = new QPropertyAnimation(this, "rect");
       scaleAnimation->setDuration(700);
      //
       scaleAnimation->setStartValue(QRect(x, y, 50, 50));
       scaleAnimation->setEndValue(QRect(x, y, 50, 50));
       scaleAnimation->setEasingCurve(QEasingCurve::OutQuart);
       group->addAnimation(scaleAnimation);
      //
       QPropertyAnimation *scaleAnimation1 = new QPropertyAnimation(this, "rect");
       scaleAnimation1->setDuration(700);
       scaleAnimation1->setStartValue(QRect(x, y, 50, 50));
       scaleAnimation1->setEndValue(QRect(x, y+100, 30, 30));
       scaleAnimation1->setEasingCurve(QEasingCurve::OutQuart);
       group->addAnimation(scaleAnimation1);
       QPropertyAnimation *fadeAnimation = new QPropertyAnimation(this, "opacity");
       fadeAnimation->setDuration(700);
       fadeAnimation->setStartValue(1);
       fadeAnimation->setEndValue(0);
       fadeAnimation->setEasingCurve(QEasingCurve::OutQuart);
       group->addAnimation(fadeAnimation);

       connect(group, &QParallelAnimationGroup::finished,
               this, &Exploid::deleteLater);
       group->start();
}
