#include "mainwindow.h"
#include"QRect"
#include<QDialog>
#include<QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   //
    QFont font;
    font.setPointSize(32);
    paint.setFont(font);
    paint.setPen(QColor(255,0,0));
    glo.framei=0;
    glo.status=new Status();
    glo.blockimage=new QImage(":/images/map_block.png");
    glo.tankimage=new QImage(":/images/player_tank.png");
    glo.bulletimage=new QImage(":/images/bullet.png");
    glo.fireimage=new QImage(":/images/fire.png");
    glo.gamemap=new GameMap();
    glo.player=new Tank();
    Tank *tmp=new Tank(2,2,UP,1);
    glo.badtanks.append(tmp);
    tmp=new Tank(10,2,DOWN,1);
    glo.badtanks.append(tmp);
    tmp=new Tank(10,15,DOWN,1);
    glo.badtanks.append(tmp);
    tmp=new Tank(3,2,RIGHT,1);
    glo.badtanks.append(tmp);
    tmp=new Tank(2,16,LEFT,1);
    glo.badtanks.append(tmp);
    //
    gamestatus=gameing;
    laststyle=0;
    leftorright=1;
    time_Start = (double)clock();
    timer=new QTimer(this);
    timer->setInterval(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefun()));
    timer->start();


}

MainWindow::~MainWindow()
{
timer->stop();
delete timer;


}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

setFixedSize(WIDTH,HEIGHT);

paint.begin(this);
glo.gamemap->Display(paint);
glo.player->Display(paint);
glo.status->Display(paint);
for(int i=0;i<glo.badtanks.count();i++)
glo.badtanks.at(i)->Display(paint);

paint.end();
}




void MainWindow::keyPressEvent(QKeyEvent *event){
    qDebug("key:--------------------------%d ",event->key());
//当按键为M时设置游戏状态为mapedit
    if(gamestatus==gameing){
        if(glo.badtanks.empty()) {
            timer->stop();
            QDialog *dialog=new QDialog(this);
            QLabel *label=new QLabel(dialog);
            label->setText(QString::number(glo.status->cal(time_Start)/1000));
            dialog->show();
        }
        if(glo.player->life==0) {
            timer->stop();
            QDialog *dialog=new QDialog(this);
            QLabel *label=new QLabel(dialog);
            label->setText("游戏失败！");
            dialog->show();
       }
    }
    if(event->key()==Qt::Key_M)
        {
            gamestatus=mapedit;
        }else if(event->key()==Qt::Key_G){
            gamestatus=gameing;
        }

    if(gamestatus==mapedit){
        if(event->key()==Qt::Key_N)
            {
                 glo.gamemap->savemap("1.dat");
             }
        else if(event->key()==Qt::Key_L)
            {
                glo.gamemap->loadmap("1.dat");
             }

     }else if(gamestatus==gameing){
          if(event->key()==Qt::Key_S)
             {
                 glo.player->setdir(DOWN);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_A)
            {
                 glo.player->setdir(LEFT);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_W)
             {
               glo.player->setdir(UP);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_D)
          {
              glo.player->setdir(RIGHT);glo.player->startmove();

          }else if(event->key()==Qt::Key_J){
                 glo.player->startfire();

          }
     }
update();
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
   if(event->key()==Qt::Key_J)
   glo.player->stopfire();
   else
       glo.player->stopmove();

}

// 鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event){
if(gamestatus==mapedit){
    int i,j;
glo.gamemap->cal(event->x(),event->y(),i,j);
if(leftorright==1){
glo.gamemap->setstyle(i,j,laststyle);
}
else{
 glo.gamemap->deletecell(i,j);

}

}

update();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
int i,j;//地图块的二维编号地址
if(gamestatus==mapedit){
glo.gamemap->cal(event->x(),event->y(),i,j);

if(event->button()==Qt::LeftButton){

    leftorright=1;
laststyle=glo.gamemap->switchstyle(i,j);
}
else{
glo.gamemap->deletecell(i,j);
leftorright=2;
}
}
update();
}

void MainWindow::timefun(){
  if(gamestatus!=gameing)return;
    glo.framei++;
    Dir tmpdir;int tmp;
    if(qrand()%500==0){
        Tank *tmp=new Tank(2,1,DOWN,1);
        glo.badtanks.append(tmp);
    }
    if(qrand()%350==0){
        Tank *tmp=new Tank(9,15,LEFT,1);
        glo.badtanks.append(tmp);
    }
    if(qrand()%400==0){
        Tank *tmp=new Tank(1,16,DOWN,1);
        glo.badtanks.append(tmp);
    }
    if(qrand()%150==0){
        Tank *tmp=new Tank(9,1,DOWN,1);
        glo.badtanks.append(tmp);
    }
    if(qrand()%250==0){
        Tank *tmp=new Tank(1,6,DOWN,1);
        glo.badtanks.append(tmp);
    }
    for(int i=0;i<glo.badtanks.count();i++){
    if(qrand()%5==0)
    {glo.badtanks.at(i)->startmove();glo.badtanks.at(i)->startfire();}
   if(qrand()%10==0)
       glo.badtanks.at(i)->stopmove();
   if(qrand()%10==0)
       glo.badtanks.at(i)->stopfire();
   if(qrand()%10==0){
       tmp=qrand()%4;
          switch(tmp){
          case 0:
              tmpdir=UP;
            break;
          case 1:
              tmpdir=DOWN;
            break;

           case 2:
              tmpdir=LEFT;
              break;

          case 3:
              tmpdir=RIGHT;
              break;
          }
         glo.badtanks.at(i)->setdir(tmpdir);
           }
    }
glo.player->Move();
glo.player->fire();
for(int i=0;i<glo.badtanks.count();i++)
{glo.badtanks.at(i)->Move();glo.badtanks.at(i)->fire();}

qDebug("timeout");
update();
}
