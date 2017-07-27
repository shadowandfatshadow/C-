#ifndef _PLAYER_H
#define _PLAYER_H

#include "Prop.h"
#include "Bag.h"


class Martial{								//����
private:
	int id;         //���ɱ��
	string name;  //��������
	string type;  //�������ͣ����ɡ�а�ɡ�������а
	COORD hqCoord;  //�ܲ����꣨X-�У�Y-�У����������������෴
	int isOpen;     //�Ƿ񿪷�
	string desc;//��������
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
	int id;							//��ұ��
	string name;						//�������
	int life;						//����ֵ
	int level;						//�ȼ�
	int exp;							//����ֵ
	int hp;							//Ѫ��
	int mp;							//����
	int mpmax;						//�������ֵ
	int gold;						//���
	COORD coord;						//��ǰ����
	Armor ammor;						//װ���ķ���
	Weapon weapon;					//װ��������
	Martial martial;					//��������
	Bag bag;							//������Ϣ
public:
	Player(int id, string name, int life, int level, int exp,
		int hp, int mp, int mpmax, int gold, COORD coord, Armor ammor, Weapon weapon,Martial martial) :
		id(id), name(name), life(life), level(level), exp(exp),
		hp(hp), mp(mp), mpmax(mpmax), gold(gold), coord(coord),ammor(ammor),weapon(weapon),martial(martial),
		bag(id,0,6){}

	//get����
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
	int getcoordX(){								//�õ���ҵ�ǰX����
		return coord.X;
	}
	int getcoordY(){								//�õ���ҵ�ǰY����
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
	//set����
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
