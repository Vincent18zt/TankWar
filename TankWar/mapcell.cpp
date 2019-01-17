#include "mapcell.h"

QImage Mapcell::blockimage=QImage(":/images/map_block.png"); //linux

Mapcell::Mapcell()
{

}

void Mapcell::Display(QPainter &paint){
int i,j;
cal(style,i,j);
if(!this->IsDisappear())
paint.drawImage(m_rectSphere,blockimage,QRect(j*PICWIDTH,i*PICHEIGHT,PICWIDTH,PICHEIGHT));//优化代码，速度飞一般
//paint.drawImage(m_rectSphere,QImage(":/images/map_block.png"),QRect(j*PICWIDTH,i*PICHEIGHT,PICWIDTH,PICHEIGHT));


}
void Mapcell::Move(){



}

void Mapcell::downlife(float attack,int type=0){
    if(life>0)life-=attack;
    if(life<0){
        m_bDisappear=true;
        life=0;
    }

}
