#include "face.h"
#include <stdlib.h>
#include <time.h>

void showWelecom(){
	setposition(MARGIN_LEFT, 0);
	cout << SEP << endl;
	setposition(MARGIN_LEFT, 1);
	cout << "|";
	setposition(MARGIN_LEFT + 25, 1);
	cout << "��ӭ���������Ϸ" << endl;
	setposition(MARGIN_LEFT + 70, 1);
	cout << "|";
	setposition(MARGIN_LEFT, 2);
	cout << SEP << endl;
}

void showMap(int x,int y){
	int i, j;
	for (i = 0; i < 8;i++){
		setposition(MARGIN_LEFT, 3 + i);
		cout << "|";
		for (j = 0; j < 8; j++){
			if (i == y && j == x){						//��ʾ��ҵ�λ�øĸ���ɫ
				setcolor(14, 8);
			}
			cout << std::left << setw(9) << maparray[i][j].getname();
			setcolor(9, 0);								//���ԭ����
		}
		setposition(75, 3 + i);
		cout << "|";
		cout << endl;
	}
	setposition(MARGIN_LEFT, 11);
	cout << SEP << endl;
	showMapInfo(x,y);
}

void showInformation(){
	//��Ϣ����������
	setposition(MARGIN_LEFT, 12);				//��Ϣ���ڿ�ʼ
	for (int i = 0; i < 7; i++){
		setposition(MARGIN_LEFT, 12+i);
		cout << "|";
		setposition(MARGIN_LEFT + 70, 12+i);
		cout << "|" << endl;;
	}
	setposition(MARGIN_LEFT, 19);
	cout << SEP << endl;
}

void showmain(){
	setposition(MARGIN_LEFT, 20);				//�˵�
	cout << "��Ϸ�˵���";
	setposition(MARGIN_LEFT, 21);
	cout << "1.�������ͣ�";
	setposition(MARGIN_LEFT, 22);
	cout << "2.̽������֣�";
	setposition(MARGIN_LEFT, 23);
	cout << "3.�س�";
	setposition(MARGIN_LEFT, 24);
	cout << "4.����װ��";
	setposition(MARGIN_LEFT, 25);
	cout << "5.��Ŀ������δ��ɣ�";
	setposition(MARGIN_LEFT, 26);
	cout << "6.����һ�Σ�δ��ɣ�";
	setposition(MARGIN_LEFT, 27);
	cout << "7.�˳���Ϸ"<<endl;

}

void showMapInfo(int x,int y){
	//�����Ϣ������Ϣ
	Clear(MARGIN_LEFT + 1,12,7);
	//��ʾ������ڵ�ͼ��Ϣ
	setposition(MARGIN_LEFT + 25, 12);
	cout << "��ǰ�ص㣺" << maparray[y][x].getname();
	setposition(MARGIN_LEFT + 5, 13);
	//��Ҫ����������ʾ��
	string desc = maparray[y][x].getdesc();
	char* d = (char*)desc.c_str();
	int len = strlen(d);
	int j = 0;
	for (int i = 0; i < len; i++){
		if ( i%55 == 0){
			j++;
			setposition(MARGIN_LEFT + 5, 13 + j);
		}
		printf("%c", d[i]);
	}
}

void dealmain(Player* player,char key){
	switch (key)
	{
	case '1':											//�鿴�Լ�������
		showpalyerinfo(player);
		break;
	case '2':
		showmonster(player);
		break;
	case '3':
		moveback(player);
		break;
	case '4':
		showTread(player);
		break;
	case '5':
		break;
	default:
		break;
	}
}

void showpalyerinfo(Player* player){
	Clear(MARGIN_LEFT+1,12,7);
	setposition(MARGIN_LEFT + 15, 12);
	cout << "�����������ɣ�"<<player->getmartial().getname()<<"   �����������£�";
	setposition(MARGIN_LEFT + 10, 13);
	cout << "������" << player->getname() << "          " << "Ѫ��/����ֵ��" << player->gethp() << "/" << player->getlife();
	setposition(MARGIN_LEFT + 10, 14);
	cout << "�ȼ���" << player->getlevel() << "             " << "����/�������" << player->getmp() << "/" << player->getmpmax();
	setposition(MARGIN_LEFT + 10, 15);
	cout << "��ǰ���" << player->getgold() << "     " << "��ǰ����ֵ��" << player->getexp();
	setposition(MARGIN_LEFT + 10, 16);
	cout << "װ��������" << player->getweapon().getname() << "          " << "װ������:" << player->getarmor().getname();
	
	player->getbag().show();
}


void showmonster(Player* player){
	Clear(MARGIN_LEFT + 1, 12, 7);
	//�õ���������
	int monstercount = sizeof(monsterarr) / sizeof(Monster);
	int monsterindex[9];				//���ڴ��Ӧ���������ͼ�Ĺ����±�
	int currentmonstercount = 0;		//��ǰ��ͼ�Ĺ�������
	int i = 0;
	for (i = 0; i < monstercount;i++)
	{
		//�鿴�����ǲ����������ͼ
		if (monsterarr[i].getcoordx() == player->getcoordX() &&
			monsterarr[i].getcoordy() == player->getcoordY() &&
			monsterarr[i].getstate() != 0){
			monsterindex[currentmonstercount] = i;			//��������ŵ��ǹ����ڹ���������±�
			currentmonstercount++;
			if (currentmonstercount == 9)
			{
				break;
			}
		}
	}
	//��ӡ������Ϣ
	setposition(MARGIN_LEFT + 15, 12);
	if (currentmonstercount == 0){
		cout << "��ǰ��ͼûӴ����";
		return;
	}
	cout << "��ǰ�����У�";
	for (int i = 0; i < currentmonstercount;i++)
	{
		if (i % 3 == 0)					//��ӡ������һ��
		{
			setposition(MARGIN_LEFT + 10, 13 + i / 3);
		}
		cout << monsterarr[monsterindex[i]].getid() << "." << monsterarr[monsterindex[i]].getname()
			<< "(" << monsterarr[monsterindex[i]].getlevel() << ")" << "\t";
	}
	setposition(MARGIN_LEFT + 10, 18);
	cout << "������Ҫ�����Ķ����ţ���0���أ�";
	//ѡ������ţ������pk
	int pkMonsterid = 0;					
	cin >> pkMonsterid;								
	Fight(player, &monsterarr[pkMonsterid - 1]);
}

void Fight(Player* player, Monster* monster){
	//����֤���pk�Ĺ������Ƿ����
	int monsterindex = -1;
	int i;
	for (i = 0; i<sizeof(monsterarr) / sizeof(Monster);i++)
	{
		if (monsterarr[i].getid() == monster->getid()){
			monsterindex = i;
			break;
		}
	}
	setposition(MARGIN_LEFT + 10, 18);
	cout << "                                            ";
	if (monsterindex == -1){
		setposition(MARGIN_LEFT + 10, 18);
		cout << "ѡ��Ĺ��ﲻ���ڣ�����������أ�";
		return;
	}
	//����������
	int monsterhp = monster->gethp();
	int playerhp = player->gethp();

	int fightcount = 0;
	while (1)
	{
		monsterhp -= player->getweapon().getattack();
		if (monsterhp < 0){
			break;
		}
		playerhp -= monster->getatt();
		if (playerhp < 0)
		{
			break;
		}
		setposition(MARGIN_LEFT + 5, 18);		//ˢ��
		cout << "                                 ";
		setposition(MARGIN_LEFT + 5, 18);		//ˢ��
		fightcount++;
		cout << "ս����" << fightcount << "�֣�"
			<< player->getname() << ":" << playerhp << "  " << monster->getname() << ":" << monsterhp;
		Sleep(200);
	}
	setposition(MARGIN_LEFT + 5, 18);		//ˢ��
	cout << "                                 ";
	setposition(MARGIN_LEFT + 5, 18);
	if (playerhp < 0)
	{
		cout << "���ѱ���ɱ��ʤ���˱��ҳ���";
		player->sethp(1);				//�������Ѫ��
		return;
	}
	player->sethp(playerhp);
	cout << "�����ɵĻ�ɱ��" << monster->getname() << "����ý��" << monster->getmaxmoney() << "����þ���" << monster->getexp();
	player->setgold(player->getgold() + monster->getmaxmoney());
	player->setexp(player->getexp() + monster->getexp());
	return;
}

void moveback(Player* player){
	player->setcoord(player->getmartial().getx(), player->getmartial().gety());
	showMap(player->getcoordX(), player->getcoordY());
}

void showTread(Player* player){
	Clear(MARGIN_LEFT + 1, 12, 7);
	setposition(MARGIN_LEFT + 10, 12);
	cout << "����Ҫ������߻��������أ���1.��������2.���ߣ�(0.�˳�)";
	setposition(MARGIN_LEFT + 15, 18);
	cout << "�ҵ�ѡ���ǣ�";
	int ch;
	cin >> ch;
	if (ch == 1){
		Clear(MARGIN_LEFT + 1, 12, 7);
		setposition(MARGIN_LEFT + 15, 12);
		cout << "��ǰ�Ļ����У�";
		setposition(MARGIN_LEFT + 10, 13);
		for (int i = 0; i < sizeof(warray) / sizeof(Weapon); i++){
			if (i % 3 == 0)					//��ӡ������һ��
			{
				setposition(MARGIN_LEFT + 10, 13 + i / 3);
			}
			cout << warray[i].getid() << "." << warray[i].getname() << " " << warray[i].getstock()<<" ";
		}
		setposition(MARGIN_LEFT + 10, 18);
		cout << "��������Ҫ�������Ʒ��ţ�(��0�˳�)";
		int chooseid;
		cin >> chooseid;
		//�жϹ�������
		if (chooseid == 0){
			showTread(player);
		}
		else if (chooseid < 0 || chooseid > 9){
			setposition(MARGIN_LEFT + 10, 18);
			cout << "                                           ";
			setposition(MARGIN_LEFT + 10, 18);
			cout << "��������,�����������";
			_getch();
			showTread(player);
		}
		else{
			chooseid--;
			if (warray[chooseid].getstock() < 1){
				setposition(MARGIN_LEFT + 10, 18);
				cout << "                                        ";
				setposition(MARGIN_LEFT + 10, 18);
				cout << "��Ʒ��û�����������������";
				_getch();
				showTread(player);
			}
			else if(player->getgold() < warray[chooseid].getstock()){
				setposition(MARGIN_LEFT + 10, 18);
				cout << "                                           ";
				setposition(MARGIN_LEFT + 10, 18);
				cout << "���겻���ˣ������������";
				_getch();
				showTread(player);
			}
			else if (player->getbag().getpropCount() == 6){
				setposition(MARGIN_LEFT + 10, 18);
				cout << "                                          ";
				setposition(MARGIN_LEFT + 10, 18);
				cout << "���������ı����ˣ������������";
				_getch();
				showTread(player);
			}
			else{
				warray[chooseid].setstock(warray[chooseid].getstock()-1);
				player->setgold(player->getgold() - (int)warray[chooseid].getprice());
				player->setbag(warray[chooseid]);
				setposition(MARGIN_LEFT + 10, 18);
				cout << "                                            ";
				setposition(MARGIN_LEFT + 10, 18);
				cout << "����ɹ�";
			}
		}
	}
	else if (ch == 2){
		Clear(MARGIN_LEFT + 1, 12, 7);
		setposition(MARGIN_LEFT + 15, 12);
		cout << "��ǰ�Ļ����У�";
		setposition(MARGIN_LEFT + 10, 13);
		for (int i = 0; i < sizeof(aarray) / sizeof(Armor); i++){
			if (i % 3 == 0)					//��ӡ������һ��
			{
				setposition(MARGIN_LEFT + 10, 13 + i / 3);
			}
			cout << aarray[i].getid() << "." << aarray[i].getname() << " " << aarray[i].getstock() << " ";
		}
	}
	else if (ch == 0){
		setposition(MARGIN_LEFT + 15, 18);
		return;
	}
	else{
		showTread(player);
	}
}