#ifndef _PLAYER_H
#define _PLAYER_H

#include "Prop.h"
#include "Bag.h"


class Martial{								//门派
private:
	int id;         //门派编号
	string name;  //门派名称
	string type;  //门派类型：正派、邪派、亦正亦邪
	COORD hqCoord;  //总部坐标（X-行，Y-列），与正常坐标轴相反
	int isOpen;     //是否开放
	string desc;//门派描述
public:
	Martial(int id,string name,string type,COORD hqCoord,int isOpen,string desc):
		id(id), name(name), type(type), hqCoord(hqCoord), isOpen(isOpen), desc(desc){}
	//get
	string getname(){
		return name;
	}
	string gettype(){
		return type;
	}
	int getx(){
		return hqCoord.X;
	}
	int gety(){
		return hqCoord.Y;
	}

};


class Player{
private:
	int id;							//玩家编号
	string name;						//玩家姓名
	int life;						//生命值
	int level;						//等级
	int exp;							//经验值
	int hp;							//血量
	int mp;							//内力
	int mpmax;						//最大内力值
	int gold;						//金币
	COORD coord;						//当前坐标
	Armor ammor;						//装备的防具
	Weapon weapon;					//装备的武器
	Martial martial;					//所属门派
	Bag bag;							//背包信息
public:
	Player(int id, string name, int life, int level, int exp,
		int hp, int mp, int mpmax, int gold, COORD coord, Armor ammor, Weapon weapon,Martial martial) :
		id(id), name(name), life(life), level(level), exp(exp),
		hp(hp), mp(mp), mpmax(mpmax), gold(gold), coord(coord),ammor(ammor),weapon(weapon),martial(martial),
		bag(id,0,6){}

	//get方法
	string getname(){
		return name;
	}
	int getlife(){
		return life;
	}
	int getlevel(){
		return level;
	}
	int getexp(){
		return exp;
	}
	int gethp(){
		return hp;
	}
	int getmp(){
		return mp;
	}
	int getmpmax(){
		return mpmax;
	}
	int getgold(){
		return gold;
	}
	int getcoordX(){								//得到玩家当前X坐标
		return coord.X;
	}
	int getcoordY(){								//得到玩家当前Y坐标
		return coord.Y;
	}
	Armor getarmor(){
		return ammor;
	}
	Weapon getweapon(){
		return weapon;
	}
	Martial getmartial(){
		return martial;
	}
	Bag getbag(){
		return bag;
	}
	//set方法
	void setlife(int life){
		this->life = life;
	}
	void setexp(int exp){
		this->exp = exp;
	}
	void sethp(int hp){
		this->hp = hp;
	}
	void setmp(int mp){
		this->mp = mp;
	}

	void setgold(int gold){
		this->gold = gold;
	}
	void setcoord(int x, int y){
		coord.X = x;
		coord.Y = y;
	}
	void setweapon(Weapon weapon){
		this->weapon = weapon;
	}
	void setarmor(Armor armor){
		this->ammor = armor;
	}
	void setbag(Prop p){
		bag.setprop(bag.getpropCount(),p);
		bag.setpropCount(bag.getpropCount() + 1);
	}
};


#endif
