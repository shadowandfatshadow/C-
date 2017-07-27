#ifndef _PROP_H
#define _PROP_H

#include <iostream>
#include <string.h>
#include <string>
#include <windows.h>
using namespace std;


/*-----------------类型定义-----------------------*/
//道具
class Prop
{
private:
	int id;					//道具id
	string name;				//道具名
	int level;				//道具级别
	int stock;				//道具库存或背包中的叠加数量
	double price;				//道具单价
	string desc;				//道具功能描述

public:
	Prop(){}
	Prop(int id, string name, int level, int stock, double price, string desc) :
		id(id), name(name), level(level), stock(stock), price(price), desc(desc){}
	virtual void show(){									//显示
			cout << "编号\t名称\t等级\t库存\t单价\t描述\t" << endl;
			cout << id << "\t" << name << "\t" << level << "\t" << stock << "\t" << price << "\t" << desc << "\t" ;
		
	}
	//get
	virtual string getname(){
		return name;
	}
	virtual int getid(){
		return id;
	}
	virtual int getstock(){
		return stock;
	}
	virtual double getprice(){
		return price;
	}

	//set
	virtual void setstock(int i){
		stock = i;
	}
	virtual void setname(string name){
		this->name = name;
	}
};
//武器
class Weapon:public Prop{
private:
	int attack;				//攻击力
public:
	Weapon(){}
	Weapon(int id, string name, int level, int stock, double price, string desc, int attack):
			Prop(id, name, level, stock, price, desc){
		this->attack = attack;
	}
	void show(){									//显示
		Prop::show();
		cout << "攻击力:"<<attack << endl;
	}
	int getattack(){
		return attack;
	}
};
//防具
class Armor :public Prop{
private:
	int defence;				//防御力
public:
	Armor(){}
	Armor(int id, string name, int level, int stock, double price, string desc, int defence) :
		Prop(id, name, level, stock, price, desc){
		this->defence = defence;
	}
	void show(){									//显示
		Prop::show();
		cout << "防御力:" << defence << endl;
	}
	int getdef(){
		return defence;
	}
};
//消耗品
class Con :public Prop{ 
private:
	int power;				//增加的能量值
public:
	Con(int id, string name, int level, int stock, double price, string desc, int power) :
		Prop(id, name, level, stock, price, desc){
		this->power = power;
	}
	void show(){									//显示
		Prop::show();
		cout << "回复值:" << power << endl;
	}
};

//血瓶
class Blood :public Con{
public:
	Blood(int id, string name, int level, int stock, double price, string desc, int power) :
		Con( id,  name,  level,  stock,  price, desc, power){}
};

//蓝瓶
class Energy :public Con{
public:
	Energy(int id, string name, int level, int stock, double price, string desc, int power) :
		Con(id, name, level, stock, price, desc, power){}
};

#endif
