#include "myrect.h"

MyRect::MyRect()
{
    //Ball
    ball=new Ball();
    //Right padle
    right_padle=new Right_padle();
    //Left padle
    left_padle=new Left_padle();
    left_padle->init(1280,720,5*10,20*10);
    right_padle->init(1280,720,5*10,20*10);

}

void MyRect::keyPressEvent(QKeyEvent *event)
{

 // qDebug()<<"MyRect knows that you pressed a key";
 if(event->key()==Qt::Key_Up){

   left_padle->move(-15);
 } else if((event->key()==Qt::Key_Enter) || (event->key()==Qt::Key_Return)){
     //qDebug()<<"enter";
  if(ball->gameState=="start"){ ball->gameState="serve";
      QString s=QString::number(ball->servingPlayer)+"'s serve!";
      ball->infor->update("Player ",s);
  }
  else if(ball->gameState=="serve"){
      QString s=QString::number(ball->servingPlayer)+"'s serve!";
      ball->infor->update("Player ",s);
     ball->gameState="play";
     ball->start();
  }else if(ball->gameState=="done"){
       qDebug()<<ball->gameState;
     ball->gameState="serve";
     QString s=QString::number(ball->servingPlayer)+"'s serve!";
     ball->infor->update("Press Enter to restart!\n",s);
     ball->score->player1Score = 0;
     ball->score->player2Score = 0;
          ball->reset();
          ball->show();
      ball->score->update();
     if(ball->winningPlayer==1)ball->servingPlayer=2;
     else ball->servingPlayer=1;
  }
//ball->gameState="start";
}
  else if(event->key()==Qt::Key_Down){
   left_padle->move(15);
  }
 else if(event->key()==Qt::Key_Space){
  //qDebug()<<"MyRect knows that you pressed a key";
   ball->start();

 }
  else if(event->key()==Qt::Key_Escape){
   qDebug()<<"MyRect knows that you pressed a key";
   QApplication::quit();

  }
 else if(event->key()==Qt::Key_W)
   right_padle->move(-15);
 else if(event->key()==Qt::Key_S)
   right_padle->move(15);

}

