#include "face.h"
#include <stdlib.h>
#include <time.h>

void showWelecom(){
	setposition(MARGIN_LEFT, 0);
	cout << SEP << endl;
	setposition(MARGIN_LEFT, 1);
	cout << "|";
	setposition(MARGIN_LEFT + 25, 1);
	cout << "欢迎来到这个游戏" << endl;
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
			if (i == y && j == x){						//表示玩家的位置改个颜色
				setcolor(14, 8);
			}
			cout << std::left << setw(9) << maparray[i][j].getname();
			setcolor(9, 0);								//变回原来的
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
	//信息窗口有七行
	setposition(MARGIN_LEFT, 12);				//信息窗口开始
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
	setposition(MARGIN_LEFT, 20);				//菜单
	cout << "游戏菜单：";
	setposition(MARGIN_LEFT, 21);
	cout << "1.自我欣赏：";
	setposition(MARGIN_LEFT, 22);
	cout << "2.探索（打怪）";
	setposition(MARGIN_LEFT, 23);
	cout << "3.回城";
	setposition(MARGIN_LEFT, 24);
	cout << "4.购买装备";
	setposition(MARGIN_LEFT, 25);
	cout << "5.举目四望（未完成）";
	setposition(MARGIN_LEFT, 26);
	cout << "6.到此一游（未完成）";
	setposition(MARGIN_LEFT, 27);
	cout << "7.退出游戏"<<endl;

}

void showMapInfo(int x,int y){
	//清除信息窗的信息
	Clear(MARGIN_LEFT + 1,12,7);
	//显示玩家所在地图信息
	setposition(MARGIN_LEFT + 25, 12);
	cout << "当前地点：" << maparray[y][x].getname();
	setposition(MARGIN_LEFT + 5, 13);
	//需要控制文字显示行
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
	case '1':											//查看自己的属性
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
	cout << "大侠所属门派："<<player->getmartial().getname()<<"   大侠资料如下：";
	setposition(MARGIN_LEFT + 10, 13);
	cout << "姓名：" << player->getname() << "          " << "血量/生命值：" << player->gethp() << "/" << player->getlife();
	setposition(MARGIN_LEFT + 10, 14);
	cout << "等级：" << player->getlevel() << "             " << "内力/最大内力" << player->getmp() << "/" << player->getmpmax();
	setposition(MARGIN_LEFT + 10, 15);
	cout << "当前金币" << player->getgold() << "     " << "当前经验值：" << player->getexp();
	setposition(MARGIN_LEFT + 10, 16);
	cout << "装备武器：" << player->getweapon().getname() << "          " << "装备防具:" << player->getarmor().getname();
	
	player->getbag().show();
}


void showmonster(Player* player){
	Clear(MARGIN_LEFT + 1, 12, 7);
	//得到怪物总数
	int monstercount = sizeof(monsterarr) / sizeof(Monster);
	int monsterindex[9];				//用于存放应该在这个地图的怪物下标
	int currentmonstercount = 0;		//当前地图的怪物总数
	int i = 0;
	for (i = 0; i < monstercount;i++)
	{
		//查看怪物是不是在这个地图
		if (monsterarr[i].getcoordx() == player->getcoordX() &&
			monsterarr[i].getcoordy() == player->getcoordY() &&
			monsterarr[i].getstate() != 0){
			monsterindex[currentmonstercount] = i;			//这个数组存放的是怪物在怪物数组的下标
			currentmonstercount++;
			if (currentmonstercount == 9)
			{
				break;
			}
		}
	}
	//打印怪物信息
	setposition(MARGIN_LEFT + 15, 12);
	if (currentmonstercount == 0){
		cout << "当前地图没哟怪物";
		return;
	}
	cout << "当前怪物有：";
	for (int i = 0; i < currentmonstercount;i++)
	{
		if (i % 3 == 0)					//打印三个换一行
		{
			setposition(MARGIN_LEFT + 10, 13 + i / 3);
		}
		cout << monsterarr[monsterindex[i]].getid() << "." << monsterarr[monsterindex[i]].getname()
			<< "(" << monsterarr[monsterindex[i]].getlevel() << ")" << "\t";
	}
	setposition(MARGIN_LEFT + 10, 18);
	cout << "请输入要攻击的对象编号（按0返回）";
	//选择怪物编号，与玩家pk
	int pkMonsterid = 0;					
	cin >> pkMonsterid;								
	Fight(player, &monsterarr[pkMonsterid - 1]);
}

void Fight(Player* player, Monster* monster){
	//先验证玩家pk的怪物编号是否存在
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
		cout << "选择的怪物不存在，按任意键返回！";
		return;
	}
	//如果怪物存在
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
		setposition(MARGIN_LEFT + 5, 18);		//刷新
		cout << "                                 ";
		setposition(MARGIN_LEFT + 5, 18);		//刷新
		fightcount++;
		cout << "战斗第" << fightcount << "轮："
			<< player->getname() << ":" << playerhp << "  " << monster->getname() << ":" << monsterhp;
		Sleep(200);
	}
	setposition(MARGIN_LEFT + 5, 18);		//刷新
	cout << "                                 ";
	setposition(MARGIN_LEFT + 5, 18);
	if (playerhp < 0)
	{
		cout << "您已被击杀，胜败乃兵家常事";
		player->sethp(1);				//重生后的血量
		return;
	}
	player->sethp(playerhp);
	cout << "您轻松的击杀了" << monster->getname() << "，获得金币" << monster->getmaxmoney() << "，获得经验" << monster->getexp();
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
	cout << "您需要购买防具还是武器呢？（1.武器）（2.防具）(0.退出)";
	setposition(MARGIN_LEFT + 15, 18);
	cout << "我的选择是：";
	int ch;
	cin >> ch;
	if (ch == 1){
		Clear(MARGIN_LEFT + 1, 12, 7);
		setposition(MARGIN_LEFT + 15, 12);
		cout << "当前的货物有：";
		setposition(MARGIN_LEFT + 10, 13);
		for (int i = 0; i < sizeof(warray) / sizeof(Weapon); i++){
			if (i % 3 == 0)					//打印三个换一行
			{
				setposition(MARGIN_LEFT + 10, 13 + i / 3);
			}
			cout << warray[i].getid() << "." << warray[i].getname() << " " << warray[i].getstock()<<" ";
		}
		setposition(MARGIN_LEFT + 10, 18);
		cout << "请输入想要购买的商品编号：(按0退出)";
		int chooseid;
		cin >> chooseid;
		//判断购买条件
		if (chooseid == 0){
			showTread(player);
		}
		else if (chooseid < 0 || chooseid > 9){
			setposition(MARGIN_LEFT + 10, 18);
			cout << "                                           ";
			setposition(MARGIN_LEFT + 10, 18);
			cout << "输入有误,按任意键返回";
			_getch();
			showTread(player);
		}
		else{
			chooseid--;
			if (warray[chooseid].getstock() < 1){
				setposition(MARGIN_LEFT + 10, 18);
				cout << "                                        ";
				setposition(MARGIN_LEFT + 10, 18);
				cout << "商品还没进货！按任意键返回";
				_getch();
				showTread(player);
			}
			else if(player->getgold() < warray[chooseid].getstock()){
				setposition(MARGIN_LEFT + 10, 18);
				cout << "                                           ";
				setposition(MARGIN_LEFT + 10, 18);
				cout << "本店不赊账！按任意键返回";
				_getch();
				showTread(player);
			}
			else if (player->getbag().getpropCount() == 6){
				setposition(MARGIN_LEFT + 10, 18);
				cout << "                                          ";
				setposition(MARGIN_LEFT + 10, 18);
				cout << "你该清理你的背包了！按任意键返回";
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
				cout << "购买成功";
			}
		}
	}
	else if (ch == 2){
		Clear(MARGIN_LEFT + 1, 12, 7);
		setposition(MARGIN_LEFT + 15, 12);
		cout << "当前的货物有：";
		setposition(MARGIN_LEFT + 10, 13);
		for (int i = 0; i < sizeof(aarray) / sizeof(Armor); i++){
			if (i % 3 == 0)					//打印三个换一行
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