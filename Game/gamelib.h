#ifndef _GAME_H_INCLUDE
#define _GAME_H_INCLUDE

/*ʵ��һЩ��ʽ���趨*/
#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
using namespace std;

//����������ɫ
/* 
* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
* 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
*/
void setcolor(int forecolor, int backcolor);
//���ù��λ��
void setposition(int x,int y);
//��մ���
void Clear(int x, int y, int rows);				//��rows��


#endif
