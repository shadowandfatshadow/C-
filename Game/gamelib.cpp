#include "gamelib.h"

void setcolor(int forecolor, int backcolor){
	HANDLE myhandle;									//句柄
	myhandle = GetStdHandle(STD_OUTPUT_HANDLE);			//得到控制台窗口
	//设置文字颜色
	SetConsoleTextAttribute(myhandle, forecolor + backcolor * 0x10);
}


void setposition(int x, int y){
	HANDLE myhandle;
	COORD pos = { x, y };
	myhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(myhandle, pos);			//设置光标位置
}

void Clear(int x,int y,int rows){
	//打印空格
	for (int i = 0; i < rows; i++){
		setposition(x, y + i);
		for (int j = 0; j < 69; j++){
			cout << " ";
		}
	}
}
