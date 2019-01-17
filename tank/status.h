#ifndef STATUS_H
#define STATUS_H
/*
源代码分析戳这里：http://blog.csdn.net/qq_26046771/article/details/72636320

  */
#include"base.h"
#include<sys/time.h>
class Status
{
public:
    double time_Start;
    float life;
    Status(){
        life=100;
        time_Start=(double)clock();
    }
    double cal(double ts);
    void Display(QPainter &paint);
};

#endif // STATUS_H
