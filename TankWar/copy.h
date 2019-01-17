#ifndef COPY_H
#define COPY_H

#include <QMainWindow>
#include<QPainter>
#include"main.h"
#include"gamemap.h"

namespace Ui {
class copy;
}

class copy : public QMainWindow
{
    Q_OBJECT

public:
    enum Gamestatus{maedit = 520,gameing,pause};
    explicit copy(QWidget *parent = 0);
    ~copy();

private slots:
    void paintEvent(QPaintEvent *envent);

private:
    void setgame(Gamestatus status){gamestatus=status;}
    Gamestatus gamestatus;
    GameMap gamemap;
   // Ui::copy *ui;
};

#endif // COPY_H
