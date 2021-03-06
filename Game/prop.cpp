#include "Prop.h"

Weapon warray[] = {
	{ 1, "一字长蛇剑", 1, 50, 1000, "犹如巨蟒出击，攻击凌厉！",5 },
	{ 2, "二龙汲水珠", 2, 10, 2000, "高度的灵活性，玄妙无比！",10 },
	{ 3, "三叉海神戟", 3, 10, 3000, "重达十万八千斤，威力无穷！",15 },
	{ 4, "四方苦禅杖", 4, 10, 4000, "极度彰显了少林作为中原武林第一大派和佛门贵地的崇高地位。",20 },
	{ 5, "五虎攒羊锤", 5, 10, 5000, "唯有能与元素沟通的人可以唤醒它的真正力量。",25 },
	{ 6, "六合迎风枪", 6, 10, 6000, "当年兵器谱排名第二，第一是小李他妈的飞刀！",30 },
	{ 7, "七星斩将矛", 7, 10, 7000, "矛尖有如白蛇吐信，是令敌将闻风丧胆的象征！",40 },
	{ 8, "八卦金锁鞭", 8, 10, 8000, "打在身上，仿佛是幻影涰连，遮日蔽天！",50 },
	{ 9, "九转乾坤圈", 9, 10, 10000, "金色镯子，可翻江倒海，震荡乾坤！",90 },
};

int weaponlen = sizeof(warray) / sizeof(Weapon);

Armor aarray[] = {
	{ 100, "辟邪犀", 1, 10, 1000, "一块能解天下百毒的透明佩玉。", 5 },
	{ 101, "乌蚕裙", 2, 10, 2000, "极其坚韧，刀枪不入，水火不侵！", 15 },
	{ 102, "英姿带", 3, 10, 3000, "穿后精气饱满，神采飞扬，姿态英勇威风！", 20 },
	{ 103, "天罡指", 4, 10, 4000, "飘忽不定，防东西至，防西东至！", 25 },
	{ 104, "紫鲛衫", 5, 10, 5000, "海蛟皮制成，装备后可在水下呼吸！", 30 },
	{ 105, "碧麟披", 6, 10, 6000, "上撰：上古南火朱雀之子,曾云字！", 40 },
	{ 106, "金钟罩", 7, 10, 7000, "装备后有如金铸之钟覆罩全身，刀剑难损！", 45 },
	{ 107, "防弹衣", 8, 10, 8000, "闯荡武林、居家必备！", 60 },
	{ 108, "软猬甲", 9, 10, 10000, "刀枪不入还可保暖，穿在身上，妙用无穷。桃花岛的镇岛之宝！", 70 }
};

int aarraylen = sizeof(aarray) / sizeof(Armor);