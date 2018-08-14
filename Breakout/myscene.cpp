#include "myscene.h"
#include <stdlib.h>
#include "sounds.h"

extern Sounds sound;

MyScene::MyScene(QObject *parent):QGraphicsScene(parent),Constants()
{
 setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  //
state=States::serve;
 timer=new QTimer();
timer->setInterval(10);

 background = new QGraphicsPixmapItem(scaled);
 //background->set

 addItem(background);
 background->setPos(0, 0);
//paddle
 paddle=new Paddle();
 connect(timer, &QTimer::timeout, this, &MyScene::update);

 title=new Title();

 start=new Title();

 hirgh_scores=new Title();


 serve();
 //
 ball=new Ball();

  timerBall=new QTimer();
  timerBall->setInterval(10);
  connect(timerBall, &QTimer::timeout, this, startBall);



  //
    //Brick*  b=new Brick();
  //qDebug()<<bricks.size() * sizeof(Brick);
}

void MyScene::clearBricks()
{

    for(int i=0;i<bricks.size();i++){
      if(bricks[i]->scene()!= 0 ){
      removeItem(bricks[i]);
      bricks.remove(i);
      }
    }
    if(bricks.size()>0)clearBricks();
}

void MyScene::addBricks()
{
    LevelMaker lm;
    bricks=lm.makeLevel(1);
    for(int i=0;i<bricks.size();i++){
      if(bricks[i]->scene()== 0 )
       addItem(bricks[i]);

    }
}

void MyScene::serve()
{
    title->init("BREAKOUT",WINDOW_HEIGHT / 3,60);
    if(title->scene()== 0 )
    addItem(title);
    start->init("START",WINDOW_HEIGHT / 2 + 200,30);
    if(start->scene()== 0 )
    addItem(start);
    hirgh_scores->init("HIGH SCORES",WINDOW_HEIGHT / 2 + 260,30);
    addItem(hirgh_scores);
}

void MyScene::addHealth()
{
    //health
     for(int i=1;i<=3;i++){
        health[i-1].setPos(health[i-1].x+30*i, health[i-1].y);
        addItem(&health[i-1]);
     }
}



void MyScene::update()
{

   paddle->update();
   if(canMoove){
  ball->start(paddle->x+paddle->width/2-ball->width,paddle->y-ball->width);


  }


}

void MyScene::startBall()
{
    ball->update();
   if(ball->collides(paddle)){//qDebug()<<"colision";//timerBall->stop();
    //raise ball above paddle in case it goes below it, then reverse dy
    ball->dy = -ball->dy  ;
    ball->y = paddle->y - 24;
    //if we hit the paddle on its left side while moving left...
     if(ball->x <paddle->x + ((paddle->width-20)/ 2)&& paddle->dx < 0){
      ball->dx = -(50 + -(4 * (paddle->x + 64 / 2 - ball->x)))/100;
      //qDebug()<<ball->dx;
     }
      else if(ball->x >paddle->x + ((paddle->width-20) / 2)&& paddle->dx > 0){
      ball->dx = (50 + (4 *abs(paddle->x + 64 / 2 - ball->x)))/100;
      //qDebug()<<ball->dx;
     }
   }
   for(int i=0;i<bricks.size();i++){
       if(ball->collides(bricks[i])){
        //qDebug()<<bricks[i]->x;
       // timerBall->stop();
           /*we check to see if the opposite side of our velocity is outside of the brick;
            if it is, we trigger a collision on that side. else we're within the X + width of
            the brick and should check to see if the top or bottom edge is outside of the brick,
            colliding on the top or bottom accordingly
           */

           //left edge; only check if we're moving right
           if(ball->x + 2 < bricks[i]->x && ball->dx > 0){
               //flip x velocity and reset position outside of brick
               ball->dx = -ball->dx;
               ball->x = bricks[i]->x - 8;
           }
           //right edge; only check if we're moving left
           else if(ball->x + 6 > bricks[i]->x + bricks[i]->width && ball->dx < 0){
               //flip x velocity and reset position outside of brick
               ball->dx = -ball->dx;
               ball->x = bricks[i]->x + bricks[i]->width;
           }
           //top edge if no X collisions, always check
           else if(ball->y < bricks[i]->y){

               //flip y velocity and reset position outside of brick
               ball->dy = -ball->dy;
               ball->y = bricks[i]->y - 8;
           }
           //bottom edge if no X collisions or top collision, last possibility
                   else{

                       //flip y velocity and reset position outside of brick
                       ball->dy = -ball->dy;
                       ball->y = bricks[i]->y + 48;
                      //qDebug()<<"hit bot";
           }
           qDebug()<<bricks[i]->color;
         if(bricks[i]->inPlay==false){
           if(bricks[i]->scene()!= 0 )
           removeItem(bricks[i]);
           bricks.remove(i);
           //play a second layer sound if the brick is destroyed
             sound.player[5]->play();

             Exploid *ep=new Exploid();
             addItem(ep);
             ep->explode(ball->x,ball->y);
           }else{
           bricks[i]->hit();
           Exploid *ep=new Exploid();
           addItem(ep);
           ep->explode(ball->x,ball->y);
           }
       }
   }
   //if ball goes below bounds, revert to serve state and decrease health
   if(ball->y >= WINDOW_HEIGHT){
     healthSize--;
     removeItem(&health[healthSize]);
     sound.player[5]->play();

     //
     timerBall->stop();
     canMoove=true;
     ball->start(paddle->x+paddle->width/2-ball->width,paddle->y-ball->width);
     if(healthSize == 0){
      state=States::game_over;
      //remove items
      if(state==States::game_over){
       title->init("GAME OVER",WINDOW_HEIGHT / 3,60);
       addItem(title);
       start->init("Press Enter",WINDOW_HEIGHT / 2 + 200,30);
       addItem(start);
       clearBricks();
       //
       removeItem(paddle);
       if(ball->scene()!= 0 )removeItem(ball);
       healthSize=3;
      }
     }else{
         title->init("Press Enter to serve!",WINDOW_HEIGHT / 3,60);
         if(title->scene()== 0 )
          addItem(title);
     }
   }

}

void MyScene::keyPressEvent(QKeyEvent *event)
{

       switch (event->key()) {
       case Qt::Key_Up:
        sound.player[0]->play();
        highlighted=1;

        start->setColor();
        hirgh_scores->setDefaultTextColor(Qt::white);
           break;
       case Qt::Key_Down:
        sound.player[0]->play();
        highlighted=2;
        hirgh_scores->setColor();
        start->setDefaultTextColor(Qt::white);
           break;
       case Qt::Key_Enter:
       case Qt::Key_Return:
        if (event->isAutoRepeat()){
               return;
           }
        if(state==States::game_over){
            state=States::serve;
            serve();
            return;
        }
       if(state==States::serve){
      ball->start(paddle->x+paddle->width/2-ball->width,paddle->y-ball->width);
       //qDebug()<<"serve";
       if(highlighted==1){
           addBricks();
           addHealth();
           state=States::play;
         canMoove=true;
         if(ball->scene()== 0 )
         addItem(ball);
         sound.player[1]->play();
         if(paddle->scene()== 0 )
          addItem(paddle);
         if(hirgh_scores->scene()!= 0 )
          removeItem(hirgh_scores);
 title->init("Press Enter to serve!",WINDOW_HEIGHT / 3,60);
         if(start->scene()!= 0 )
          removeItem(start);
          //highlighted=0;
            }
       return;
       }
       else if(state==States::play){
           //qDebug()<<"timerBall";
           if(title->scene()!= 0 )
            removeItem(title);
           timerBall->start();
          canMoove=false;
       }

           break;
       case Qt::Key_Left:
          paddle->dx =-PADDLE_SPEED;
          paddle->update();
           timer->start();
           break;
       case Qt::Key_Right:
          paddle->dx =PADDLE_SPEED;
          paddle->update();
           timer->start();
           break;
       case Qt::Key_Escape:

        QApplication::quit();

       default:

           break;

       }
}

void MyScene::keyReleaseEvent(QKeyEvent *event)
{
       switch (event->key()) {
       case Qt::Key_Left:
       case Qt::Key_Right:
         timer->stop();
           break;
       }
}
