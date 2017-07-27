#include "Prop.h"
#include "GameMap.h"
#include "gamelib.h"
#include "face.h"
#include "player.h"
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <conio.h>

extern Weapon warray[];					//武器数组
extern Armor aarray[];					//防具数组
extern int weaponlen;						//武器数组长度
extern int arraylen;						//防具数组长度

extern GameMap maparray[8][8];				//地图
extern Martial martials[];

int main(){

	Player god(9527, "华安", 10000, 3, 1, 10000, 500, 900, 10000, { 3, 1 }, aarray[0], warray[0],martials[0]);	//测试用玩家
	char key;							//获取按键
	SetConsoleTitle(L"这是个游戏！");											//这里前面加了个L
	setcolor(9, 0);
	showWelecom();
	showMap(god.getcoordX(), god.getcoordY());
	showInformation();
	showmain();
	while (1){
		key = _getch();									//_getch是库里的，getch不是，其实无所谓
		if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' ){
			dealmain(&god,key);
			continue;
		}
		else if(key == 72){									//按了上键
			god.setcoord(god.getcoordX(), god.getcoordY()-1);
		}
		else if (key == 77){									//按了右键
			god.setcoord(god.getcoordX()+1, god.getcoordY());
		}
		else if (key == 80){									//按了下键
			god.setcoord(god.getcoordX(), god.getcoordY() + 1);
		}
		else if (key == 75){									//按了左键
			god.setcoord(god.getcoordX() - 1, god.getcoordY());
		}
		if (god.getcoordX() > 7){
			god.setcoord(0,god.getcoordY()) ;
		}
		if (god.getcoordX() < 0){
			god.setcoord(7, god.getcoordY());
		}
		if (god.getcoordY() > 7){
			god.setcoord(god.getcoordX(), 0);
		}
		if (god.getcoordY() < 0){
			god.setcoord(god.getcoordX(), 7);
		}
		showMap(god.getcoordX(), god.getcoordY());				//重新显示地图
	}
}
