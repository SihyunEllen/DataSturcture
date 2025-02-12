#include<stdio.h>

int main(){

	int n;
	scanf("%d",&n);
	while(1){
	    
	    printf("%d\n",n%10);
	    n/=10;
	    
	     if(n==0) break;
	}

	return 0;
}
