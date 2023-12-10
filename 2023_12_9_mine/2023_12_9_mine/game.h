#define _CRT_SECURE_NO_WARNINGS 1;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 9
#define ROW 9

#define COLS COL + 2
#define ROWS ROW + 2

#define MINENUM 10

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char flag);

void DisplayBoard(char arr[ROWS][COLS], int row, int col);

void SetMine(char arr[ROWS][COLS], int num);

void SweepMine(char mine[ROWS][COLS], char show[ROWS][COLS], int rpw, int col);

char SurroundMine(char arr[ROWS][COLS], int x, int y);