#define _CRT_SECURE_NO_ARNINGS 1;

#include "game.h"

void test(void);//���Գ���
void game(void);
void menu(void);//��ӡ�˵�

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
		printf("���������ѡ��");
		scanf("%d", &choice);
		switch (choice) 
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("�������������֣�����\n");
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

	//��ʼ������
	InitBoard(mine, ROW, COL, '0');
	InitBoard(show, ROW, COL, '*');

	//������
	SetMine(mine, MINENUM);

	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//ɨ��
	SweepMine(mine, show, ROW, COL);

}