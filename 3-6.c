#include<stdio.h>

int Gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    else if(b==0){
        return a;
    }
    
    else if(a>=b)
    {
        Gcd(a%b,b);
    }
    else if(b>a)
    {
        Gcd(a,b%a);
    }
}



int main(){

	int a,b;
	scanf("%d %d",&a,&b);
	
	int ans;
	ans=Gcd(a,b);
    printf("%d\n",ans);
	return 0;
}
