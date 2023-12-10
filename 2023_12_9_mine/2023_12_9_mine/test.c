#define _CRT_SECURE_NO_ARNINGS 1;

#include "game.h"

void test(void);//测试程序
void game(void);
void menu(void);//打印菜单

int main(void) 
{
	test();
	return 0;
}

void test(void) 
{
	int choice;
	do 
	{
		menu();
		printf("请输入你的选择：");
		scanf("%d", &choice);
		switch (choice) 
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("请输入合理的数字！！！\n");
				break;
		}
	} while (choice);
}

void menu(void) 
{
	printf("****************************\n");
	printf("*        1.play            *\n");
	printf("*        0.exit            *\n");
	printf("****************************\n");
}

void game(void) 
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化数组
	InitBoard(mine, ROW, COL, '0');
	InitBoard(show, ROW, COL, '*');

	//放置雷
	SetMine(mine, MINENUM);

	//打印数组
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//扫雷
	SweepMine(mine, show, ROW, COL);

}