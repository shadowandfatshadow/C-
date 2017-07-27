#ifndef _GAME_H_INCLUDE
#define _GAME_H_INCLUDE

/*实现一些样式的设定*/
#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
using namespace std;

//更改文字颜色
/* 
* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
* 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
*/
void setcolor(int forecolor, int backcolor);
//设置光标位置
void setposition(int x,int y);
//清空窗口
void Clear(int x, int y, int rows);				//清rows行


#endif
