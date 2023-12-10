#define _CRT_SECURE_NO_WARNINGS 1;
#include "game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char flag)
{
	int i = 0;
	for (i = 0; i < ROWS; i++) 
	{
		int j = 0;
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] = flag;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col) 
{
	int i = 0;
	printf("------扫雷游戏-----\n");
	for (i = 0; i <= COL; i++) 
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++) 
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char arr[ROWS][COLS], int num) 
{
	srand((unsigned int)time(NULL));
	int x = 0;
	int y = 0;
	while (num) 
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;

		if (arr[x][y] == '0') 
		{
			arr[x][y] = '1';
			num--;
		}
	}

}

void SweepMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rpw, int col) 
{
	int x, y;
	int ch;
	

	int num = (COL * ROW - MINENUM);

	while (num)
	{
		printf("请输入坐标(用空格隔开):");
		scanf("%d %d", &x, &y);

		if ('*' == show[x][y])
		{
			if ('1' == mine[x][y])
			{
				printf("你被炸死了，游戏结束\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				ch = SurroundMine(mine, x, y);
				show[x][y] = ch + '0';
				DisplayBoard(show, ROW, COL);
				num--;
			}
		}

		else
		{
			printf("请输入合法的坐标！！！！\n");
		}
	}
	if (0 == num)
	{
		printf("游戏胜利了\n");
	}
}

char SurroundMine(char arr[ROWS][COLS], int x, int y)
{
		return arr[x - 1][y] +
			arr[x - 1][y - 1] +
			arr[x][y - 1] +
			arr[x + 1][y - 1] +
			arr[x + 1][y] +
			arr[x + 1][y + 1] +
			arr[x][y + 1] +
			arr[x - 1][y + 1] - (8 * '0');
}