#ifndef _BAG_H
#define _BAG_H

#include "Prop.h"

class Bag
{
private:
	int playerId;       //所属玩家编号
	int propCount;      //当前道具的总数
	int propMax;        //背包中最大道具数
	Prop props[6];      //背包中的道具数组
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

	//get方法
	int getpropCount(){
		return propCount;
	}

	//set方法
	void setprop(int i, Prop prop){
		props[i] = prop;
	}
	void setpropCount(int i){
		propCount = i;
	}
};
#endif
