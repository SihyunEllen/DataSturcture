#include<stdio.h>
int MAX(int*,int);
int main() {
    int n;
    scanf("%d",&n);
    int*num=malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }
    
    printf("%d",MAX(&num[0],n));
    
    free(num);
    return 0;
}

int MAX(int*p, int n)
{
    if(n<=1) return p[0];
    
    int sub= MAX(p+1,n-1);
    
    if(sub<*p)
    {
        return *p;
    }
    else return sub;
    
}
