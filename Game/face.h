/*��Ϸ����*/
#ifndef _FACE_H
#define _FACE_H

#include <iostream>
#include <windows.h>
#include <iomanip>
#include "Prop.h"
#include "gamelib.h"
#include "GameMap.h"
#include "player.h"
#include "Monster.h"
#include <conio.h>

using namespace std;

#define SEP "-----------------------------------------------------------------------"		
#define COL 78   
#define MARGIN_LEFT 5									//��߾�

extern GameMap maparray[8][8];
extern Monster monsterarr[8];
extern Weapon warray[9];					//��������
extern Armor aarray[9];					//��������

void showWelecom();						//��ʾ��ӭ��Ϣ
void showMap(int x,int y);					//��ʾ��ͼ
void showMapInfo(int x,int y);				//��ʾ��ǰ��ͼ����Ϣ
void showInformation();					//��ʾ�ص���Ϣ
void showmain();							//��ʾ��ѡ��
void dealmain(Player*,char);				//�������˵�
void showpalyerinfo(Player*);				//��ʾ�����Ϣ

void showmonster(Player*);					//��ʾ������Ϣ
void Fight(Player*, Monster*);				//�Ծ�����

void moveback(Player*);					//�س�
void showTread(Player*);					//ó��
#endif
