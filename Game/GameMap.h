/*��ͼ��*/
#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include <iostream>
#include <string.h>
#include <string>
#include <windows.h>
using namespace std;

class GameMap{
private:
	int id;							//��ͼ���
	string name;						//��ͼ����
	int minLevel;						//�����ͼ����С�ȼ�
	COORD coord;						//����ṹ��ϵͳ�Դ�
	string desc;						//��ͼ����
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
