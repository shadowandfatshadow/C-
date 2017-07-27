/*地图类*/
#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include <iostream>
#include <string.h>
#include <string>
#include <windows.h>
using namespace std;

class GameMap{
private:
	int id;							//地图编号
	string name;						//地图名称
	int minLevel;						//进入地图的最小等级
	COORD coord;						//坐标结构，系统自带
	string desc;						//地图介绍
public:
	GameMap(int id,string name,int minLevel,COORD coord,string desc):
		id(id), name(name), minLevel(minLevel), coord(coord), desc(desc){}
	string getname(){
		return name;
	}
	string getdesc(){
		return desc;
	}
};



#endif
