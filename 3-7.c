#include <stdio.h>
#include <string.h>

int check(char* str, char s,int cnt) {
    if(*str==NULL) return cnt;
    else if(*str==s){
        check(str+1, s , cnt+1);
    }
    else
        check(str+1,s,cnt);
}

int main() {
    char str[101];
    scanf("%s", str);
    getchar(); 
    char c;
    scanf("%c", &c);
    int cnt= check(str,c,0);
    
    printf("%d",cnt);
    return 0;
}
