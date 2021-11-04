#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SIZE 4
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* ps;
	size_t size;
	size_t capacity;
}SL;
void SLInit(SL* ps)
{
	ps->ps = NULL;
	ps->size = ps->capacity = 0;
}
void CheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = (ps->capacity == 0 ? MAX_SIZE : ps->capacity * 2);
		SLDataType* tmp = (SLDataType*)realloc(ps->ps, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("Creat memory failed.");
			exit(-1);
		}
		ps->ps = tmp;
		ps->capacity = newcapacity;
	}
}
void SLShow(SL* ps)
{
	if (ps->size == 0)
	{
		printf("顺序表为空");
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->ps[i]);
	}
	printf("数组的大小是%d\n", ps->size);
}
void SLDataDelete(SL* ps, int pos)
{
	assert(pos < ps->size);
	while (pos < ps->size - 1)
	{
		ps->ps[pos] = ps->ps[pos + 1];
		pos++;
	}
	ps->size--;
}
void SLDataPush(SL* ps, int pos, int x)
{
	assert(pos < ps->size);
	CheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->ps[i] = ps->ps[i - 1];
	}
	ps->ps[pos] = x;
	ps->size++;
}
void SLDataPushFront(SL* ps, int x)
{
	CheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->ps[i] = ps->ps[i - 1];
	}
	ps->ps[0] = x;
	ps->size++;
}
void SLDataPushBack(SL* ps, int x)
{
	CheckCapacity(ps);
	ps->ps[ps->size] = x;
	ps->size++;
}
void SLDataDeleteFront(SL* ps)
{
	for (int i = 1; i < ps->size; i++)
	{
		ps->ps[i - 1] = ps->ps[i];
	}
	ps->size--;
}
void SLDataDeleteBack(SL* ps)
{
	ps->size--;
}
void SLDataChange(SL* ps, int pos, int x)
{
	ps->ps[pos] = x;
}
void SLDataSearch(SL* ps, int x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->ps[i] == x)
		{
			printf("找到了，下标是：%d\n", i);
			break;
		}
		else
		{
			printf("没找到");
		}
	}
}
void SLDestroy(SL* ps)
{
	free(ps->ps);
	ps->ps = NULL;
	ps->size = ps->capacity = 0;
}
int main()
{
	SL ps;
	SLInit(&ps);
	SLDataPushFront(&ps, 4);
	SLDataPushFront(&ps, 1);
	SLDataPushFront(&ps, 2);
	SLDataPushFront(&ps, 3);
	SLDataPushFront(&ps, 7);
	SLDataPush(&ps, 3, 8);
	SLDataPushBack(&ps, 12);
	SLDataDeleteFront(&ps);
	SLDataDeleteBack(&ps);
	SLDataDelete(&ps, 2);
	SLDataSearch(&ps, 3);
	SLDataChange(&ps, 1, 5);
	SLShow(&ps);
	SLDestroy(&ps);
	return 0;
}