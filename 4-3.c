#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int num[100][100];
void MakeMatrix(int n)
{
	int put = 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++)
				num[i][j] = put++;
		}

		else {
			for (int j = n - 1; j >= 0; j--)
				num[i][j] = put++;
		}
	}


}
int main()
{
	int n;
	scanf("%d", &n);

	MakeMatrix(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf(" %d", num[i][j]);
		}
		printf("\n");
	}

	return 0;
}
