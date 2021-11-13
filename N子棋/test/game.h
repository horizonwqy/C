#pragma once
#define ROWS 5
#define COLS 5
#define ROW ROWS*ROWS-2*ROWS
#define COL COLS*COLS-2*COLS
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu();
void game();
void player(char arr[ROW][COL], int row, int col, int* p);
void print(char arr[ROW][COL], int row, int col);
void init(char arr[ROW][COL], int row, int col);
char judge(char arr[ROW][COL], int row, int col,int rows, int cols,int count);
void computer(char arr[ROW][COL], int row, int col, int* p);