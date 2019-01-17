#include "main.h"
#include "mainwindow.h"
#include <QApplication>
Glo glo;
/*
源代码分析戳这里：http://blog.csdn.net/qq_26046771/article/details/72636320

  */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
