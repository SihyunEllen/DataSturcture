#include <stdio.h>

void Matrix(int arr[100][100],int num_N,int num_M) {
	
	int num1,num2, turn =1; 
	int put = 1;
	int col = 0, row = -1; 
	num1 = num_N;num2 = num_M;
	while (num1!=0 && num2!=0) {
		for (int i = 0; i < num2; i++) { 
			row += turn;
			arr[col][row] += put;
			put++;
		}
		num1--; 
		for (int i = 0; i < num1; i++) {
			col += turn;
			
			arr[col][row] += put;
			put++;
		}
        num2 --; 
		turn *= -1;
	}
	for (int i = 0; i < num_N; i++) {
		for (int j = 0; j < num_M; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	int n,m; 
	int arr[100][100] = { 0 };

	scanf("%d %d", &n,&m);
	Matrix(arr, n,m);
	return 0;
}
