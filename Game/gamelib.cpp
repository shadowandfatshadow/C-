#include "gamelib.h"

void setcolor(int forecolor, int backcolor){
	HANDLE myhandle;									//���
	myhandle = GetStdHandle(STD_OUTPUT_HANDLE);			//�õ�����̨����
	//����������ɫ
	SetConsoleTextAttribute(myhandle, forecolor + backcolor * 0x10);
}


void setposition(int x, int y){
	HANDLE myhandle;
	COORD pos = { x, y };
	myhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(myhandle, pos);			//���ù��λ��
}

void Clear(int x,int y,int rows){
	//��ӡ�ո�
	for (int i = 0; i < rows; i++){
		setposition(x, y + i);
		for (int j = 0; j < 69; j++){
			cout << " ";
		}
	}
}
