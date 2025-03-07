#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

#define U 1
#define D 2
#define L 3 
#define R 4       //蛇的状态，U：上 ；D：下；L:左 R：右

typedef struct SNAKE //蛇身的一个节点
{
	int x;
	int y;
	struct SNAKE *next;
}snake;

//全局变量//
int score = 0, add = 10;//总得分与每次吃食物得分。
int status, sleeptime = 200;//每次运行的时间间隔
snake *head, *food;//蛇头指针，食物指针
snake *q;//遍历蛇的时候用到的指针
int endGamestatus = 0; //游戏结束的情况，1：撞到墙；2：咬到自己；3：主动退出游戏。

					   //声明全部函数//
void Pos(int, int);
void creatMap();
void initSnake();
int biteSelf();
void createFood();
void cantCrossWall();
void snakeMove();
void pause();
void runGame();
void initGame();
void endGame();
void gameStart();

void Pos(int x, int y)//设置光标位置
{
	COORD pos;//定义控制台坐标
	HANDLE hOutput;//定义句柄
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄
	SetConsoleCursorPosition(hOutput, pos);//设置控制台坐标
}

void creatMap()//创建地图
{
	int i;
	for (i = 0; i<58; i += 2)//打印上下边框
	{
		Pos(i, 0);
		printf("■");//一个方块占两个位置
		Pos(i, 26);
		printf("■");
	}
	for (i = 1; i<26; i++)//打印左右边框
	{
		Pos(0, i);
		printf("■");
		Pos(56, i);
		printf("■");
	}
}

void initSnake()//初始化蛇身
{
	snake *tail;
	int i;
	tail = (snake*)malloc(sizeof(snake));//从蛇尾开始，头插法，以x,y设定开始的位置//
	tail->x = 24;
	tail->y = 5;
	tail->next = NULL;
	for (i = 1; i <= 4; i++)//初始长度为4
	{
		head = (snake*)malloc(sizeof(snake));
		head->next = tail;
		head->x = 24 + 2 * i;
		head->y = 5;
		tail = head;
	}
	while (tail != NULL)//从头到为，输出蛇身
	{
		Pos(tail->x, tail->y);
		printf("■");
		tail = tail->next;
	}
}
//??
int biteSelf()//判断是否咬到了自己
{
	snake *self;
	self = head->next;
	while (self != NULL)
	{
		if (self->x == head->x && self->y == head->y)
		{
			return 1;
		}
		self = self->next;
	}
	return 0;
}

void createFood()//随机出现食物
{
	snake *food_1;
	srand((unsigned)time(NULL));//为了防止每次产生的随机数相同，种子设置为time
	food_1 = (snake*)malloc(sizeof(snake));
	while ((food_1->x % 2) != 0)    //保证其为偶数，使得食物能与蛇头对其
	{
		food_1->x = rand() % 52 + 2;
	}
	food_1->y = rand() % 24 + 1;
	q = head;
	while (q->next == NULL)
	{
		if (q->x == food_1->x && q->y == food_1->y) //判断蛇身是否与食物重合
		{
			free(food_1);
			createFood();
		}
		q = q->next;
	}
	Pos(food_1->x, food_1->y);
	food = food_1;
	printf("■");
}

void cantCrossWall()//不能穿墙
{
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
	{
		endGamestatus = 1;
		endGame();
	}
}

void snakeMove()//蛇前进,上U,下D,左L,右R
{
	snake * nexthead;
	cantCrossWall();

	nexthead = (snake*)malloc(sizeof(snake));
	if (status == U)
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1;
		if (nexthead->x == food->x && nexthead->y == food->y)//如果下一个有食物//
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			score = score + add;
			createFood();
		}
		else                                               //如果没有食物//
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			Pos(q->x, q->y);
			printf("  ");
			free(q);
			q = NULL;
		}
	}
	if (status == D)
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
		if (nexthead->x == food->x && nexthead->y == food->y)  //有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			score = score + add;
			createFood();
		}
		else                               //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			Pos(q->x, q->y);
			printf("  ");
			free(q);
			q = NULL;
		}
	}
	if (status == L)
	{
		nexthead->x = head->x - 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)//有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			score = score + add;
			createFood();
		}
		else                                //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			Pos(q->x, q->y);
			printf("  ");
			free(q);
			q = NULL;
		}
	}
	if (status == R)
	{
		nexthead->x = head->x + 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)//有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			score = score + add;
			createFood();
		}
		else                                         //没有食物
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next != NULL)
			{
				Pos(q->x, q->y);
				printf("■");
				q = q->next;
			}
			Pos(q->x, q->y);
			printf("  ");
			free(q);
			q = NULL;
		}
	}
	if (biteSelf() == 1)       //判断是否会咬到自己
	{
		endGamestatus = 2;
		endGame();
	}
}

void pause()//暂停
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}

	}
}

void runGame()//控制游戏        
{

	Pos(64, 15);
	printf("不能穿墙，不能咬到自己\n");
	Pos(64, 16);
	printf("用↑.↓.←.→分别控制蛇的移动.");
	Pos(64, 17);
	printf("F1 为加速，F2 为减速\n");
	Pos(64, 18);
	printf("ESC ：退出游戏.space：暂停游戏.");
	status = R;
	while (1)
	{
		Pos(64, 10);
		printf("得分：%d  ", score);
		Pos(64, 11);
		printf("每个食物得分：%d分", add);
		if (GetAsyncKeyState(VK_UP) && status != D)
		{
			status = U;
		}
		else if (GetAsyncKeyState(VK_DOWN) && status != U)
		{
			status = D;
		}
		else if (GetAsyncKeyState(VK_LEFT) && status != R)
		{
			status = L;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && status != L)
		{
			status = R;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			endGamestatus = 3;
			break;
		}
		else if (GetAsyncKeyState(VK_F1))
		{
			if (sleeptime >= 50)
			{
				sleeptime = sleeptime - 30;
				add = add + 2;
				if (sleeptime == 320)
				{
					add = 2;//防止减到1之后再加回来有错
				}
			}
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			if (sleeptime<350)
			{
				sleeptime = sleeptime + 30;
				add = add - 2;
				if (sleeptime == 350)
				{
					add = 1;  //保证最低分为1
				}
			}
		}
		Sleep(sleeptime);
		snakeMove();
	}
}

void initGame()//开始界面
{
	Pos(40, 12);

	system("title 美气的哼");
	printf("欢迎来到贪食蛇游戏！");
	system("pause");
	system("cls");
	Pos(25, 12);
	printf("用↑.↓.←.→分别控制蛇的移动， F1 为加速，2 为减速\n");
	Pos(25, 13);
	printf("加速将能得到更高的分数。\n");
	system("pause");
	system("cls");
}

void endGame()//结束游戏
{

	system("cls");
	Pos(24, 12);
	if (endGamestatus == 1)
	{
		printf("对不起，您撞到墙了。游戏结束.");
	}
	else if (endGamestatus == 2)
	{
		printf("对不起，您咬到自己了。游戏结束.");
	}
	else if (endGamestatus == 3)
	{
		printf("您的已经结束了游戏。");
	}
	Pos(24, 13);
	printf("您的得分是%d\n", score);
	while (getchar() != 'y')
	{
		printf("close?[y]");
	}
	exit(0);
}

void gameStart()//游戏初始化
{
	system("mode con cols=100 lines=30");
	initGame();
	creatMap();
	initSnake();
	createFood();
}

int main()
{
	gameStart();
	runGame();
	endGame();
	return 0;
}
