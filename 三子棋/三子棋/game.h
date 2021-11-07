#pragma once
#define R 3
#define C 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void menu();
void init(char arr[R][C],int r,int c);
void show(char arr[R][C], int r, int c);
void game();
void player(char arr[R][C], int r, int c);
void computer(char arr[R][C], int r, int c);
char judge(char arr[R][C], int r, int c);
