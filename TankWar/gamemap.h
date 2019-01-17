#ifndef GAMEMAP_H
#define GAMEMAP_H

#include"mapcell.h"
#include<QRect>
#include"main.h"
#include<fstream>
class GameMap
{
private:
Mapcell *cells[INUM][JNUM];
public:
    GameMap();
    ~GameMap();
    void Display(QPainter &paint);
    int switchstyle(int i,int j);//改变cells[i][j]地图块的样式
    void setstyle(int i,int j,int style);//设置cells[i][j]地图块的样式
    void deletecell(int i,int j);//删除cells[i][j]处地图块
        //save map
    void savemap(const char *str);//保存地图
        //load map
    void loadmap(const char *str);//载入地图
    void cal(int x,int y,int &i,int &j);//根据鼠标点击位置计算出地图块的二维编号地址
};

#endif // GAMEMAP_H
