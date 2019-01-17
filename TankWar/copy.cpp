#include "copy.h"
#include "ui_copy.h"
#include"QRect"
copy::copy(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::copy)
{
    //ui->setupUi(this);
    gamestatus=gameing;
}

copy::~copy()
{
    //delete ui;
}

void copy::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    setFixedSize(WIDTH,HEIGHT);
    QPainter paint(this);
    paint.begin(this);
    gamemap.Display(paint);
    paint.end();

}
