#ifndef _PROP_H
#define _PROP_H

#include <iostream>
#include <string.h>
#include <string>
#include <windows.h>
using namespace std;


/*-----------------���Ͷ���-----------------------*/
//����
class Prop
{
private:
	int id;					//����id
	string name;				//������
	int level;				//���߼���
	int stock;				//���߿��򱳰��еĵ�������
	double price;				//���ߵ���
	string desc;				//���߹�������

public:
	Prop(){}
	Prop(int id, string name, int level, int stock, double price, string desc) :
		id(id), name(name), level(level), stock(stock), price(price), desc(desc){}
	virtual void show(){									//��ʾ
			cout << "���\t����\t�ȼ�\t���\t����\t����\t" << endl;
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
//����
class Weapon:public Prop{
private:
	int attack;				//������
public:
	Weapon(){}
	Weapon(int id, string name, int level, int stock, double price, string desc, int attack):
			Prop(id, name, level, stock, price, desc){
		this->attack = attack;
	}
	void show(){									//��ʾ
		Prop::show();
		cout << "������:"<<attack << endl;
	}
	int getattack(){
		return attack;
	}
};
//����
class Armor :public Prop{
private:
	int defence;				//������
public:
	Armor(){}
	Armor(int id, string name, int level, int stock, double price, string desc, int defence) :
		Prop(id, name, level, stock, price, desc){
		this->defence = defence;
	}
	void show(){									//��ʾ
		Prop::show();
		cout << "������:" << defence << endl;
	}
	int getdef(){
		return defence;
	}
};
//����Ʒ
class Con :public Prop{ 
private:
	int power;				//���ӵ�����ֵ
public:
	Con(int id, string name, int level, int stock, double price, string desc, int power) :
		Prop(id, name, level, stock, price, desc){
		this->power = power;
	}
	void show(){									//��ʾ
		Prop::show();
		cout << "�ظ�ֵ:" << power << endl;
	}
};

//Ѫƿ
class Blood :public Con{
public:
	Blood(int id, string name, int level, int stock, double price, string desc, int power) :
		Con( id,  name,  level,  stock,  price, desc, power){}
};

//��ƿ
class Energy :public Con{
public:
	Energy(int id, string name, int level, int stock, double price, string desc, int power) :
		Con(id, name, level, stock, price, desc, power){}
};

#endif
