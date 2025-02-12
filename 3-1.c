#include<stdio.h>

int main(){

	int n,sum=0;
	scanf("%d",&n);
	while(1)
	{
	    if(n<1)break;
	    sum+=n;
	    
	    n--;
	}
    printf("%d",sum);
	return 0;
}
