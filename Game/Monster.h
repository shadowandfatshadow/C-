#ifndef _MONSTER_H
#define _MONSTER_H

#include <iostream>
#include <windows.h>
using namespace std;
class Monster
{
private:
	int id;								//怪物的id
	string name;
	int level;
	int hp;
	int att;
	int den;
	int minmoney;							//杀死怪物获得的最小金钱
	int maxmoney;							//杀死怪物获得的最大金钱
	int exp;								//杀死怪物获得的经验值
	int state;							//怪物当前状态，0表示已死，非0表示活着
	COORD coord;							//怪物坐标

public:
	Monster(int id, string name, int level, int hp, int att, int den,
		int minmoney, int maxmoney, int exp, int state, COORD coord)
		:id(id), name(name), level(level), hp(hp), att(att), den(den), minmoney(minmoney),
		maxmoney(maxmoney), exp(exp), state(state), coord(coord){}
	int gethp(){
		return hp;
	}

	int getcoordx(){
		return coord.X;
	}
	int getcoordy(){
		return coord.Y;
	}
	int getstate(){
		return state;
	}
	string getname(){
		return name;
	}
	int getlevel(){
		return level;
	}
	int getid(){
		return id;
	}
	int getatt(){
		return att;
	}
	int getden(){
		return den;
	}
	int getmaxmoney(){
		return maxmoney;
	}
	int getexp(){
		return exp;
	}
	//set
	void sethp(int hp){
		this->hp = hp;
	}
};


#endif