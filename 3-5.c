#include<stdio.h>

void Hanoi(int n, char start, char end, char sub)
  
{
    if(n==1){
        printf("%c %c\n",start,end);
        return;
    }
    else{
        
        Hanoi(n-1,start,sub,end);
        printf("%c %c\n",start,end);
        Hanoi(n-1,sub,end,start);
        
    }
}
int main(){

    int n;
    scanf("%d",&n);
    Hanoi(n,'A','C','B');
	return 0;
}
