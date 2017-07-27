#include "Prop.h"
#include "GameMap.h"
#include "gamelib.h"
#include "face.h"
#include "player.h"
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <conio.h>

extern Weapon warray[];					//��������
extern Armor aarray[];					//��������
extern int weaponlen;						//�������鳤��
extern int arraylen;						//�������鳤��

extern GameMap maparray[8][8];				//��ͼ
extern Martial martials[];

int main(){

	Player god(9527, "����", 10000, 3, 1, 10000, 500, 900, 10000, { 3, 1 }, aarray[0], warray[0],martials[0]);	//���������
	char key;							//��ȡ����
	SetConsoleTitle(L"���Ǹ���Ϸ��");											//����ǰ����˸�L
	setcolor(9, 0);
	showWelecom();
	showMap(god.getcoordX(), god.getcoordY());
	showInformation();
	showmain();
	while (1){
		key = _getch();									//_getch�ǿ���ģ�getch���ǣ���ʵ����ν
		if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' ){
			dealmain(&god,key);
			continue;
		}
		else if(key == 72){									//�����ϼ�
			god.setcoord(god.getcoordX(), god.getcoordY()-1);
		}
		else if (key == 77){									//�����Ҽ�
			god.setcoord(god.getcoordX()+1, god.getcoordY());
		}
		else if (key == 80){									//�����¼�
			god.setcoord(god.getcoordX(), god.getcoordY() + 1);
		}
		else if (key == 75){									//�������
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
		showMap(god.getcoordX(), god.getcoordY());				//������ʾ��ͼ
	}
}
