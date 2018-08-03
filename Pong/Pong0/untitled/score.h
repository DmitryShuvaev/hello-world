#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QFont>

class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent=0);
    int player1Score;
    int player2Score;
    void update();
private:

};

#endif // SCORE_H
