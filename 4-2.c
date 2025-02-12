#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int* num = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	int m;
	scanf("%d", &m);
	int prev; 
	scanf("%d", &prev);
	int swch;
	int put = num[prev];
	int tmp;
	for (int i = 0; i < m-1; i++)
	{
		scanf("%d", &swch);
		tmp = num[swch];
		num[swch] = put;
		prev = swch;
		put = tmp;
	}

	for (int i = 0; i < n; i++)
	{
		printf(" %d", num[i]);
	}

	free(num);
	return 0;
}
