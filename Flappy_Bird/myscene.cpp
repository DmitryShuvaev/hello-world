#include "myscene.h"

MyScene::MyScene(QObject *parent):QGraphicsScene(parent),backgroundScroll(0),groundScroll(0),count(3)
{
     m_timer.setInterval(10);
      timer1.setInterval(1000);
     // timer2.setInterval(800);
      connect(&m_timer, &QTimer::timeout, this, &MyScene::move);
      initPlayField();
      state=Player::Invalid;
      connect(&timer1, &QTimer::timeout, this, &MyScene::update);

      colis=false;

}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return;
    }
    switch (event->key()) {

    case Qt::Key_Space:
       bird->dy=-1.3;

      //jumping->play();
         qDebug() <<jumping->errorString();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
    if(state==Player::Invalid){
        //state=Player::CountdownState;
        removeItem(title);
        removeItem(titleEnter);
        addItem(s);
        s->update(count);
        play();
    }else if(state==Player::CountdownState){
        removeItem(title);
        removeItem(titleEnter);
        addItem(s);
        s->update(count);
        score->score=0;
        bird->x=VIRTUAL_WIDTH / 2 - bird->boundingRect().width() / 2;
        bird->y=VIRTUAL_HEIGHT / 2 - bird->boundingRect().height()/2;
        bird->setPos(bird->x,bird->y);
        bird->dy=0;
        play();
            qDebug() <<"play";
    }
        break;
    case Qt::Key_Escape:
     QApplication::quit();
    default:
        break;
    }
}

float MyScene::randNum(int max, int min)
{
    int randNum = rand()%(max-min + 1) + min;
    return randNum;
}

void MyScene::collides()
{
    /*
    for(QGraphicsItem* item: collidingItems(bird)) {
        Pipe *c = qgraphicsitem_cast<Pipe*>(item);

           if(typeid(*(c))==typeid(Pipe)){
               qDebug() <<c->x;
              m_timer.stop();
           }

    }
*/
    if(bird->y+24>VIRTUAL_HEIGHT-16){
        m_timer.stop();
         colis=true;
    }
    //way 2 to check colis
   for(int i=0;i<pipePairs.size();i++){
       if(pipePairs[i]->upper->y-2 > bird->y&&(bird->x+38 >= pipePairs[i]->upper->x && bird->x<=pipePairs[i]->upper->x+PIPE_WIDTH)){
         //  qDebug() <<bird->y;
              m_timer.stop();

               colis=true;
       }
       if(pipePairs[i]->lower->y<bird->y+24&&
               (bird->x+38 >= pipePairs[i]->lower->x && bird->x<=pipePairs[i]->lower->x+PIPE_WIDTH)){
          // qDebug() <<bird->y;
              m_timer.stop();
               colis=true;
       }

   }
   if(colis){
      gameStatus();
      colis=false;

   }
}

void MyScene::play()
{
    if(!m_timer.isActive()){
        m_timer.start();
    }
      update();
    //addItem(score);
    score->update();
}

void MyScene::gameStatus()
{
    title->init("Oof! You lost!",64,40);
    QString st="Score: "+QString::number(score->score);
    titleEnter->init(st,120,20);
     addItem(title);addItem(titleEnter);
     state=Player::CountdownState;
     removeItem(bird);
     removeItem(score);
/*

*/
     clearCallBack();

     qDebug() <<pipePairs.size();
}

void MyScene::ScoreCheck(PipePair *pair)
{
    //be sure to ignore it if it's already been scored
    if(!pair->scored){
    //score a point if the pipe has gone past the bird to the left all the way
    if(pair->x + PIPE_WIDTH < bird->x){
        jumping->play();
      score->score = score->score + 1;
      score->update();
      pair->scored=true;
      //jumping->stop();
     }
    }
}
void MyScene::initPlayField()
{
    srand(time(NULL)); // Seed the time
    setSceneRect(0, 0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT);
    spawnTimer=0;
    m_timer.start();
    background = new QGraphicsPixmapItem(QPixmap(":/pics/background.png"));
    addItem(background);
    background->setPos(0, 0);
    ground = new QGraphicsPixmapItem(QPixmap(":/pics/ground.png"));
    ground->setZValue(1);
    addItem(ground);
    ground->setPos(0, VIRTUAL_HEIGHT-16);
    HORIZONTAL_GAP=randNum(200, 150);
    bird=new Bird();
    //position bird in the middle of the screen
    bird->x=VIRTUAL_WIDTH / 2 - bird->boundingRect().width() / 2;
    bird->y=VIRTUAL_HEIGHT / 2 - bird->boundingRect().height()/2;
    bird->setPos(bird->x,bird->y);
    bird->setZValue(1);
    score=new Score();
    s=new CountdownState();
    scoreTitel=new Title();
   // scoreTitel->init("Oof! You lost!",64,40);
    title=new Title();
    title->init("Fifty Bird",64,40);
    addItem(title);
    titleEnter=new Title();
    titleEnter->init("Press Enter",130,20);
    addItem(titleEnter);

    player=new QMediaPlayer();
    playlist= new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/marios_way.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);

     player->play();
    //play sound
      QPointer <QMediaPlayer> mp3backgroundplayer = new QMediaPlayer (this);
      mp3backgroundplayer->setMedia(QUrl("qrc:/sounds/jump.wav"));
      mp3backgroundplayer->setVolume(100);

     mp3backgroundplayer->play();
       connect(&timer1, &QTimer::timeout, this, &MyScene::playscore);
       //connect(this,SIGNAL(playmp3background()),mp3backgroundplayer.data(),SLOT(play()));
    jumping=new QMediaPlayer(this);
    playlist2= new QMediaPlaylist();
    playlist2->addMedia(QUrl("qrc:/sounds/score.wav"));
    playlist2->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    //jumping->setMedia(QUrl("qrc:/sounds/jump.wav"));
    jumping->setPlaylist(playlist2);
//jumping->setPosition(-2);
     qDebug() <<jumping->state();
}

void MyScene::clearCallBack()
{
    for(int i=0;i<pipePairs.size();i++){
             removeItem(pipePairs[i]->upper);
             removeItem(pipePairs[i]->lower);
             pipePairs.remove(i);

       }
    if(pipePairs.size()>0){

        clearCallBack();//callback
    }
}

void MyScene::move()
{

     //
    if(state==Player::play &&colis==false){
     collides();

     if(spawnTimer>HORIZONTAL_GAP){
         PipePair *pair=new PipePair();
          float v=20;
          float v2=VIRTUAL_HEIGHT - 110;
         float y=qBound(v, lastY + randNum(20, -20), v2);
         while(y==lastY)y=qBound(v, lastY + randNum(20, -20), v2);
         if(y>140)y=qBound(v, lastY + randNum(-10, -20), v2);

         lastY = y;
         pair->init(y);
         pipePairs.push_back(pair);
          spawnTimer=0;
         HORIZONTAL_GAP=randNum(200, 150);
           addItem(pair->lower);
           addItem(pair->upper);
     }

     //if pipe is no longer visible past left edge, remove it from scene
     for(int i=0;i<pipePairs.size();i++){
         if(pipePairs[i]->x < -PIPE_WIDTH){
             removeItem(pipePairs[i]->upper);
             removeItem(pipePairs[i]->lower);
             pipePairs.remove(i);
          //qDebug() <<pipePairs.size();
         }
       }

      spawnTimer+=1;
      bird->update();
      for(int i=0;i<pipePairs.size();i++){
       ScoreCheck(pipePairs[i]);
       pipePairs[i]->update();
      }

    }
     //background
    backgroundScroll = (backgroundScroll + 10*BACKGROUND_SCROLL_SPEED);//% BACKGROUND_LOOPING_POINT;
    if(backgroundScroll>=412)backgroundScroll=0;
     background->setX(-backgroundScroll);
     //scroll ground by preset speed * dt, looping back to 0 after the screen width passes
     groundScroll = (groundScroll + 20*BACKGROUND_SCROLL_SPEED);
     if(groundScroll>=VIRTUAL_WIDTH)groundScroll=0;
     ground->setX(-groundScroll);
     //qDebug() <<spawnTimer;

}

void MyScene::update()
{
    if(!timer1.isActive()){
        timer1.start();
    }
       if(count==0){
         count=3;
         state= Player::play;
         timer1.stop();
         removeItem(s);
         if(bird->scene()== 0 )
          addItem(bird);
          if(score->scene()== 0 )
          addItem(score);
         return ;
       }else{
          count--;
        jumping->play();
       }

}

void MyScene::playscore()
{ //
    // jumping->play();

     s->update(count);
     jumping->stop();
}
