/*游戏界面*/
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
#define MARGIN_LEFT 5									//左边距

extern GameMap maparray[8][8];
extern Monster monsterarr[8];
extern Weapon warray[9];					//武器数组
extern Armor aarray[9];					//防具数组

void showWelecom();						//显示欢迎信息
void showMap(int x,int y);					//显示地图
void showMapInfo(int x,int y);				//显示当前地图的信息
void showInformation();					//显示地点信息
void showmain();							//显示主选单
void dealmain(Player*,char);				//处理主菜单
void showpalyerinfo(Player*);				//显示玩家信息

void showmonster(Player*);					//显示怪物信息
void Fight(Player*, Monster*);				//对决怪物

void moveback(Player*);					//回城
void showTread(Player*);					//贸易
#endif
