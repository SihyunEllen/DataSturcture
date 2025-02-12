#include<stdio.h>

int main(){

	int n,m; 
	scanf("%d %d",&n,&m);
	
	int cnt=1;
	int array[100][100];
	
	int row=0, col=0;

	for (int i = 0; i < m; i++) {
        while (row < n && col >= 0) {
            array[row][col] = cnt++;
            row++;
            col--;
        }
        row = 0;
        col = i + 1;
    }
    

	 //printf("%d %d\n",row, col);
     row=row+1;
     col-=1;
     
     int start_row=row;
     //printf("%d %d\n",row, col);
    
    
    for(int i=0; i<n-1; i++)
    {
        while (row < n && col >= 0) {
            array[row][col] = cnt++;
            row++;
            col--;
        }
        
        row =start_row+(i+1);
        col=m-1;
    }
    // print array
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf(" %d",array[i][j]);
        }
        
        printf("\n");
    }
	return 0;
}
