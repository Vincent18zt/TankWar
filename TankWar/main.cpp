#include "copy.h"
#include <QApplication>

QImage blockimage = QImage("/Users/zhongteng/copy/tankimages/map_block.png");

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    copy w;
    w.show();

    return a.exec();
}
