#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	printf("���Խ�����1���Ӻ�ػ�,������ʮλ����ȷ������ȡ���ػ���");
	system("shutdown -s -t 60");
	char arr[11] = { 0 };
	char input[20] = { 0 };
	scanf("%s", arr);
	if (strcmp(arr, "0.51321wqy") == 0)
	{
		system("shutdown -a");
		printf("ȡ���ɹ�");
	}
	else
	{
		printf("���룺������ ��ȡ���ػ�\n�����룺");
		scanf("%s", input);
		if (strcmp(input, "������") == 0)
		{
			system("shutdown -a");
			printf("ȡ���ɹ�");
		}
	}
		return 0;
}