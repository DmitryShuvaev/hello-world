#include "levelmaker.h"

LevelMaker::LevelMaker()
{
    //randomly choose the number of rows
     numRows = randNum(5, 2);

    //randomly choose the number of columns
     numCols = randNum(13, 7);
     if(numCols % 2 == 0){
          numCols =numCols+1;
     }

}

QVector<Brick*> LevelMaker::makeLevel(int level)
{
 int temp=0;
 int highestTier =qBound(3, (int)floor(level / 5),5);
//qDebug()<<highestTier;
  for(int y=1;y<numRows;y++){
      //whether we want to enable skipping for this row
      int rn=randNum(2, 1);
      bool skipPattern=false;
      if(rn==1){
          skipPattern=true;
      }
      bool skipFlag=false;
      rn=randNum(2, 1);
      if(rn==1){
        skipFlag=true;

      }
      //whether we want to enable alternating colors for this row
       bool alternatePattern=false;
       rn=randNum(2, 1);
       if(rn==1){
         alternatePattern=true;

       }
       bool alternateFlag=false;
       rn=randNum(2, 1);
       if(rn==1){
         alternateFlag=true;

       }


       int alternateColor1=randNum(5, 0);
       while (alternateColor1==temp) {
           alternateColor1=randNum(5, 0);
       }
       int alternateColor2=randNum(5, 0);
       while (alternateColor1==alternateColor2) {
          alternateColor2=randNum(5, 0);
       }
       int solidColor=randNum(2, 1);
       int alternateTier1 = randNum(highestTier, 0);
       int alternateTier2 = randNum(highestTier, 0);
       int solidTier = randNum(highestTier, 0);
  //qDebug()<<alternateColor1;
      for(int x=1;x<numCols;x++){
          if(skipPattern && skipFlag){
            //turn skipping off for the next iteration
            skipFlag =!skipFlag ;
            continue;
          }else{
            //flip the flag to true on an iteration we don't use it
            skipFlag =!skipFlag ;
          }
          Brick *b=new Brick();
          b->init((x-1)*b->width+b->height+(16)+ (13 - numCols) * (b->height),y*b->height);
          //if we're alternating, figure out which color/tier we're on
          if(alternatePattern && alternateFlag){
             b->setColor(alternateColor1);
             b->color = alternateColor1;
             b->tier = alternateTier1;
             alternateFlag=!alternateFlag;
          }else{
             b->color = alternateColor2;
             b->tier = alternateTier2;
             b->setColor(alternateColor2);
             alternateFlag=!alternateFlag;
          }
          if(!alternatePattern){
              b->color = solidColor;
              b->tier = solidTier;
             b->setColor(solidColor);
          }

          //qDebug()<<"afterLoop";
         //qDebug()<<alternateColor1;
       bricks.push_back(b);
       temp=alternateColor1;
      }
  }
  //qDebug()<<numRows;
  return bricks;
}
