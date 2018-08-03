#include "ball.h"

Ball::Ball()
{
    srand( time(NULL) ); //seeding for the first time only!
    //setPen(QPen(QColor(241, 190, 56), 2));
    setBrush(QColor(252, 253, 151));
    setRect(-12, -12, 24, 24);
    //connect
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //range num
    int range = 2 - 1 + 2;
    int num = rand() % range + 1;

    if(num==1){
    ballDY=rand()%50;
    }
    else if(num==2){
    ballDY=-rand()%50;

    }
    ballX=1280/2;
    ballY=720/2;
    setPos(ballX,ballY);
    // either going to be 1 or 2; whomever is scored on gets to serve the
    // following turn
    servingPlayer = 1;
    ballDX=30;
    gameState = "start";
     //qDebug()<<gameState;
    score=new Score();

       infor=new StatusInfor();
       player=new QMediaPlayer();
}

void Ball::start()
{ //if(gameState=="play")
    timer->start(10);
}

void Ball::reset()
{
    int range = 2 - 1 + 2;
    int num = rand() % range + 1;


    if(gameState=="serve"){
        if(num==1){
        ballDY=rand()%50;

        }
        else if(num==2){
        ballDY=-rand()%50;

        }
        if(servingPlayer == 1){
           ballDX=30;
        }else{
           ballDX=-30;
        }
    }
    ballX=1280/2;
    ballY=720/2;
    setPos(ballX,ballY);
    //score->update();
    timer->stop();
}
void Ball::move()
{

     //infor->update("Welcome to Pong!","Press Enter to begin!");

    ballX = ballX + ballDX*0.05;
    ballY = ballY + ballDY*0.05;
    setPos(ballX,ballY);
    collides();
    score->update();
    /*
    if(ballY>720||ballX>1280||ballX<0){
        scene()->removeItem(this);
        delete this;
    }
    */
}

void Ball::collides()
{  QList<QGraphicsItem*>colliding_items=collidingItems();
    for(int i=0,n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Right_padle)){
        // Right_padle*padle= colliding_items[i];
     if(ballX+rect().width()>colliding_items[i]->x()){
         //play sound
         player->setMedia(QUrl("qrc:/sounds/paddle_hit.wav"));
         player->play();
         ballDX=-ballDX* 1.03;
         if(ballDY<0)ballDY=-(10 + rand() % (( 50 + 1 ) - 10));
         else ballDY=(10 + rand() % (( 50 + 1 ) - 10));
         ballX=colliding_items[i]->x()-(15);
         //timer->stop();

        }
    }else if(typeid(*(colliding_items[i]))==typeid(Left_padle)){
            if(ballX-rect().width()/2<colliding_items[i]->x()+5*10){
                //play sound
                player->setMedia(QUrl("qrc:/sounds/paddle_hit.wav"));
                player->play();
                   ballDX=-ballDX* 1.03;
                   ballX=colliding_items[i]->x()+((5*10)+15);
                   //timer->stop();
                if(ballDY<0)ballDY=-(10 + rand() % (( 50 + 1 ) - 10));
                 else ballDY=(10 + rand() % (( 50 + 1 ) - 10));
        }

  }
    }
    if(ballY+rect().width()/2>=720){
    //play sound
    player->setMedia(QUrl("qrc:/sounds/wall_hit.wav"));
    player->play();
       ballDY=-ballDY;
    }else if(ballY<=0){
        //play sound
        player->setMedia(QUrl("qrc:/sounds/wall_hit.wav"));
        player->play();
       ballDY=-ballDY;
    }
    //if we reach the left or right edge of the screen,
    // go back to start and update the score
    if(ballX<0){
        servingPlayer = 1;
        score->player2Score = score->player2Score + 1;
        //play sound
        player->setMedia(QUrl("qrc:/sounds/score.wav"));
        player->play();
        if (score->player2Score == 2){
            winningPlayer = 2;
            gameState = "done";
            QString s=QString::number(winningPlayer)+" wins!\nPress Enter to continue!";
            infor->update("Player ",s);
              timer->stop();
              //hide ball
              hide();
        }else{
            gameState="serve";
            reset();
            QString s=QString::number(servingPlayer)+"'s serve!";
            infor->update("Player ",s);
        }
    }else if(ballX+rect().width()>1280){
        servingPlayer = 2;
        score->player1Score = score->player1Score + 1;
        //play sound
        player->setMedia(QUrl("qrc:/sounds/score.wav"));
        player->play();
        if (score->player1Score == 2){
            winningPlayer = 1;
            gameState = "done";
            QString s=QString::number(winningPlayer)+" wins! \nPress Enter to continue!";
            infor->update("Player ",s);
              timer->stop();
              //hide ball
              hide();

        }else{
            gameState="serve";
            reset();
            QString s=QString::number(servingPlayer)+"'s serve!";
            infor->update("Player ",s);
        }

    }
    //if(gameState=="start")qDebug()<<"game started "<<player1Score;
//qDebug()<<score->player1Score;
}



