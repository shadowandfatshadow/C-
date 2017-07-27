#ifndef _BAG_H
#define _BAG_H

#include "Prop.h"

class Bag
{
private:
	int playerId;       //������ұ��
	int propCount;      //��ǰ���ߵ�����
	int propMax;        //��������������
	Prop props[6];      //�����еĵ�������
public:
	Bag(int playerId,int propCount,int propMax){
		this->playerId = playerId;
		this->propCount = propCount;
		this->propMax = propMax;
	}
	void show(){
		setposition(15, 17);
		for (int i = 0; i < propCount; i++){
			if (i == 3){
				setposition(15, 18);
			}
			cout << (i + 1) << "." << props[i].getname()<<"  ";
		}
	}

	//get����
	int getpropCount(){
		return propCount;
	}

	//set����
	void setprop(int i, Prop prop){
		props[i] = prop;
	}
	void setpropCount(int i){
		propCount = i;
	}
};
#endif
