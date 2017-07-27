#include "GameMap.h"

GameMap maparray[8][8] = {																//第一行
	{
		{ 1, "天山", 1, { 0, 0 }, "据《穆天子传》记载，3000年前的周朝穆王曾乘坐\"八骏马车\"西行天山，西王母在天池接见了他。穆王赠送大批锦绸美绢等中原特产，西王母则回赠了天山的奇珍瑰宝，并邀请穆王游览天山名胜。穆王亲书\"西王母之山\"，留作纪念。临别时，西王母劝饮再三，即席歌曰:\"祝君长寿，愿君再来。\"" },
		{ 2, "楼兰", 1, { 1, 0 }, "东通敦煌，西北到焉耆、尉犁，西南到若羌、且末。古代“丝绸之路”的南、北两道从楼兰分道。" },
		{ 3, "白驼山", 1, { 2, 0 }, "这可是当年大魔头欧阳锋的发家之地。今天的白驼山却很安静。。。" },
		{ 4, "野猪林", 1, { 3, 0 }, "野猪林里到处都是野猪。。。嗖！嗖！嗖！搜！。。。四只小野猪围了过来。喝过8个巨无霸后，领头的野猪朗声道：俗套！" },
		{ 5, "水晶洞", 1, { 4, 0 }, "走进一个洞中，洞中的景色马上呈现在眼前，这里真是太美了。一低头，发现脚边有一块石碑，上面写着：水晶洞。" },
		{ 6, "天蚕洞", 1, { 5, 0 }, "天蚕洞满地蚕茧，满地飞蛾。噗噜噜！噗噜噜！拨开飞蛾，踢开蚕蛹。。。但见一绝色女尼正坐在你的面前@！@！闭眼闭眼！" },
		{ 7, "黑风寨", 1, { 6, 0 }, "黑风寨只有狂风在不停地吹。突然，一条东瀛狼狗疯狂地扑了上来，一阵乱咬。" },
		{ 8, "冰火岛", 1, { 7, 0 }, "冰火岛上只有火球、冰块。快跑，轰隆隆----火山爆发了！咦，怎么只有烟，没有火？" }
	},
	{
		{ 9, "迷宫", 1, { 0, 1 }, "这里是高昌迷宫，也是一个十分神秘的地方，连江湖阅历及其丰富的老侠客都不知道这会发生什么事情。" },
		{ 10, "凌霄城", 1, { 1, 1 }, "凌霄城只有哆嗦，没人。" },
		{ 11, "轩辕岭", 1, { 2, 1 }, "一条山岭，绿油油的，不过从远处看去，岭上透出一层杀气，问过路人才知道，这里就是早有耳闻的轩辕岭！" },
		{ 12, "华山", 1, { 3, 1 }, "自古华山一条路，只许上，不许撤。如同风景介绍一般，五岳派总舵岂是邪魔歪道们随便来去之地？不过如果是君子，那就大可放心了。" },
		{ 13, "嵩山", 1, { 4, 1 }, "在雄伟的嵩山上，有一个江湖上名声响亮的寺庙：少林寺。如果说桂林山水甲天下，那么少林武功甲天下并不为过。" },
		{ 14, "紫禁城", 1, { 5, 1 }, "大内高手云集的地方。谁要赶来这里闹事，得罪的不光是大内锦衣卫，还有当今的皇上。" },
		{ 15, "快活林", 1, { 6, 1 }, "快活林快活林，有钱才能快乐！" },
		{ 16, "神龙岛", 1, { 7, 1 }, "这一上岛来，就能听到不知是韦小宝还是周星驰发出的笑声：啊哈哈哈哈哈哈哈！！这就是神龙教的总舵：神龙岛了。" }
	},
	{
		{ 17, "西域", 1, { 0, 2 }, "西域大漠的风沙吹得人和牲畜都睁不开眼睛。这里没有水，没有树，没有草，死一般的像个地狱。" },
		{ 18, "葫芦谷", 1, { 1, 2 }, "葫芦峪里似乎只有葫芦。远看还真像只大葫芦。" },
		{ 19, "唐门", 1, { 2, 2 }, "这里是唐家堡，从外面看这只是一个大宅院，与其他的富家宅院没有什么两样，但却是藏龙卧虎之地。" },
		{ 20, "终南山", 1, { 3, 2 }, "这里是终南山，全真教总舵。两旁丛丛耸耸的长满了各种树木，大道的尽头出现一座道观，几个小道士边聊天边请扫道观。" },
		{ 21, "石窟", 1, { 4, 2 }, "这里是龙门石窟，一个个的石窟自有一种神秘感。" },
		{ 22, "客栈", 1, { 5, 2 }, "地处交通要道的龙门客栈可是名扬四海，老帮娘金香玉的名头也是世人皆知，今天她在店里吗？" },
		{ 23, "玉皇顶", 1, { 6, 2 }, "一个永远不会安定的地方：泰山玉皇顶。这里是一个充满着厮杀的地方，无时无刻不充斥着暴力、仇杀的地方。" },
		{ 24, "灵蛇岛", 1, { 7, 2 }, "到处都是蛇的岛，这就是灵蛇岛。在这里，恐怖的故事层出不穷，令人毛骨悚然。不过要是喜欢吃蛇的人来到这里，可是该高兴死了。" }
	},
	{
		{ 25, "光明顶", 1, { 0, 3 }, "所谓三十六峰者，骈列舒张，横绝天表，众岫叠岭，效奇献秀，尽在一览。" },
		{ 26, "摩天崖", 1, { 1, 3 }, "这里是摩天崖，陡峭的石壁，就连猿猴上下都不可能，真是太险了。真难以想象当年谢烟客是如何在上面生存而又可以叱咤风云的。" },
		{ 27, "聚贤庄", 1, { 2, 3 }, "聚贤庄大家今日都很忙。虽然现在没人，不过无所谓！" },
		{ 28, "后山", 1, { 3, 3 }, "终终南后山的景色就是不一般，到处盛开着叫不上名字的各色小花，几只蜜蜂在花间飞舞，沿着一条花间小路来到一个古墓前，上面写着：活死人墓。" },
		{ 29, "武当山", 1, { 4, 3 }, "武当山只有火工道人在打盹。红卫兵刚刚来过！道士全都拉走批斗了！" },
		{ 30, "开封府", 1, { 5, 3 }, "宋朝时的都城，因有包青天而世人皆知。同时也是武林人士活动的要地。" },
		{ 31, "二十四桥", 1, { 6, 3 }, "今天没人乐意走二十四桥，不如坐下来喝点茶，寂寞高手嘛！" },
		{ 32, "蓬莱仙境", 1, { 7, 3 }, "云雾缭绕的蓬莱仙境自古以来都似乎隐藏着天大的秘密，谁能真正揭开这里的迷呢？也许你可以，也许他额可以。" }
	},
	{
		{ 33, "擂鼓山", 1, { 0, 4 }, "这里是擂鼓山，一点也想不到这座山为什么要起这个名字，看到的是这么美丽的景致，听到的却是个并不美丽的名字。" },
		{ 34, "峨眉山", 1, { 1, 4 }, "峨眉金顶只有几个扫山尼姑。尼姑当然寂寞！寂寞的人当然想说话！说了乱七八糟后，并没有提供什么有用的信息。" },
		{ 35, "迷踪林", 1, { 2, 4 }, "这里是迷踪林，人们总说这片树林不要轻易走进，因为它十分危险，据说有不少人走进去就再也没有出来过。" },
		{ 36, "五虎岭", 1, { 3, 3 }, "五虎岭素以五条猛虎闻名，每年都有许多不自量力的捕虎人成群进入，但从来都是一去无回，五虎真的如此厉害？" },
		{ 37, "天宁寺", 1, { 4, 4 }, "佛家地天宁寺，每天前来进香之人络绎不绝。可从进香之人求愿灵验的程度上让人不得不产生怀疑。" },
		{ 38, "积善堂", 1, { 5, 4 }, "积善堂今天没卖出一张彩票。此时已是深夜，不如早些睡了吧！" },
		{ 39, "镇江府", 1, { 6, 4 }, "从两百里以外就可以闻到一股酸味，这就是镇江府，盛产镇江醋。" },
		{ 40, "桃花岛", 1, { 7, 4 }, "桃花岛今天没人来偷桃，愉快的花工正躺在花下。" }
	},
	{
		{ 41, "恶人谷", 1, { 0, 5 }, "恶人善人都不在谷里。只有小鱼儿在睡觉！这家伙，抗倭一点都不积极。" },
		{ 42, "大理", 1, { 1, 5 }, "大理城里只有大理平民，平民最好打交道!" },
		{ 43, "百花谷", 1, { 2, 5 }, "哇，这里太美了，这里的很多花都叫不上名字！" },
		{ 44, "孔雀山庄", 1, { 3, 5 }, "这里金湖碧波荡漾，典型的傣式建筑掩映在茂密的森林之中，孔雀争相开屏、鸵鸟欢唱迎宾，梅花鹿湖畔戏水，人与自然和谐相融。" },
		{ 45, "五霸岗", 1, { 4, 5 }, "如果有人问：哪里能交上武林朋友？那答案肯定是五霸岗。此地虽怪石嶙峋、寸草不生，但却是天下英雄汇聚的地方。" },
		{ 46, "万仞堂", 1, { 5, 5 }, "万仞堂，顾名思义，十八般兵刃样样俱全。最近该堂还搞了点副业，外卖防具、药丸，有意者敬请光顾。" },
		{ 47, "栖霞古刹", 1, { 6, 5 }, "栖霞古刹今天没人来拜佛，倭寇究竟在哪里呢？不仅仰天长叹。" },
		{ 48, "六合塔", 1, { 7, 5 }, "六合塔里阴森森的。空调可够足的！" }
	},
	{
		{ 49, "玩偶山庄", 1, { 0, 6 }, "来到了玩偶山庄，这里好像什么东西都与其他地方有些不同，这是一个十分特别的地方，不知进庄之后还能有什么与众不同的东西。" },
		{ 50, "黑木崖", 1, { 1, 6 }, "黑木崖今天没人来会任我行。突然间，飞来一只黑鸽，徐徐盘旋而下。" },
		{ 51, "蝴蝶谷", 1, { 2, 6 }, "为何蝴蝶谷中会有如此众多的蝴蝶？是不是因为发生了什么不可告人的事情？看来只有有缘人才能知道了。" },
		{ 52, "铁花堡", 1, { 3, 6 }, "神秘的铁花堡，曾经是飞龙帮在三百年前的总舵。自从飞龙帮最后一任帮主争夺武林盟主失败自杀后，如今已是一片凋零。如今的铁花堡，多的是制造铁工艺品的工匠。" },
		{ 53, "霹雳堂", 1, { 4, 6 }, "江湖雷家曾把这里建立成唯一可以与唐门暗器抗衡的雷家火器大本营。" },
		{ 54, "关帝庙", 1, { 5, 6 }, "一到关帝庙，就会看到无数乞丐。他们虽乞讨，但真实的任务却是习武练功，除暴安良。" },
		{ 55, "麒麟庄", 1, { 6, 6 }, "麒麟庄的人都被麒麟给吓跑了。" },
		{ 56, "销魂宫", 1, { 7, 6 }, "销魂宫现在没人消化灵魂。不如跟小姐们聊聊！群中的眼睛是雪亮的！头牌秦可卿柔声道：大兄弟做个大保健吧！" }
	},
	{
		{ 57, "石府", 1, { 0, 7 }, "天机石府里只有石头。石头当然不会是乱放的。可惜，石头太多怎么办？" },
		{ 58, "金三角", 1, { 1, 7 }, "金三角里看来没有别人。只有只老狗悻悻的靠在罂粟田头吸着什么。。。" },
		{ 59, "忏悔崖", 1, { 2, 7 }, "忏悔崖上没人在忏悔，却有人在宣传倭寇！" },
		{ 60, "通吃岛", 1, { 3, 7 }, "通吃岛上只有“此岛危险！当心被吃”几个字。" },
		{ 61, "通天观", 1, { 4, 7 }, "一个普普通通、其貌不扬的小小通天观，有意者都可以进来玩玩。观内有一颗很高的大树，从来没有人能够爬到树顶。据说它是通天的。" },
		{ 62, "紫霞亭", 1, { 5, 7 }, "紫霞亭现在空着，亭中有一盘棋。棋子不合棋法，但对你却有用！" },
		{ 63, "天弃庵", 1, { 6, 7 }, "天弃庵是空空荡荡的小尼姑庵。我想进去，但人家不让。" },
		{ 64, "侠客岛", 1, { 7, 7 }, "侠客岛没人钻研侠客神功。卖门票的女子百无聊赖。" }
	}
};