#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE 10
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int map[ROWS][COLS];
char show[ROWS][COLS];
void menu();
void init(int map[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void print(int map[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int sweep(int map[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void open(int map[ROWS][COLS], char show[ROWS][COLS], int x, int y);