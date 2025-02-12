#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap2(int start, int end, int* num)
{
    int s = (end - start + 1) / 2;

    int index = 0;
    for (int i = 0; i < s; i++)
    {
        swap(&num[start + index], &num[end - index]);
        index++;
    }


}
int main() {

    int n;
    scanf("%d", &n);
    int* num = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    int m;
    scanf("%d", &m);
    int s, e;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);
        swap2(s, e, num);

    }
   
    for (int i = 0; i < n; i++)
    {
        printf(" %d", num[i]);
    }

    free(num);
    
    return 0;
}
