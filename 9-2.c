#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;
// 스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s) {
    return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
    return (s->top==(MAX_STACK_SIZE-1));
}
// 삽입함수
void push(StackType* s, element item) {
    if (is_full(s)) {
        printf("스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s) {
    if (is_empty(s)) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// 피크함수
element peek(StackType* s) {
    if (is_empty(s)) {
        printf("스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

//괄호 검사 
int check_matching(char* in) // 수식 확인
{ 
    StackType s;  //스택
    char ch, open_ch; 
    int i, n = strlen(in); 
    init_stack(&s); // 스택 초기화 

    for (i = 0; i < n; i++) { 
        int cnt;
        ch = in[i]; 
        switch (ch) { 
        case '(': 
        case '[': 
        case '{': 
            push(&s, ch); 
            //printf("삽입 : %c\n", ch); 
            break; 
        case ')': 
        case ']': 
        case '}': 
            if (is_empty(&s)) //스택이 비어 있으면 오류 아니면 pop()실행 
                return 0; 
            else 
            { 
                open_ch = pop(&s); 
                //printf("삭제 : %c\n", ch); 
                if ((open_ch == '(') && ch != ')' || (open_ch == '[') && ch != ']' || (open_ch == '{') && ch != '}') 
                    return 0; 
                 } 
                 break; 
            } 
    } 
    if (!is_empty(&s)) //스택에 남아있으면 오류 
        return 0; 

    return 1; 
} 

int Counts(char*ch)
{
  int cnt=0;
  for(int i=0;i<strlen(ch); i++)
    {
      if ( ch[i] == '(' || ch[i] == ')' ||
       ch[i] == '[' || ch[i] == ']' || ch[i] == '{' || ch[i] == '}') 
        cnt++;
    }
  return  cnt;
}
int main() 
{ 
    char st[MAX_STACK_SIZE];
    gets(st);
    int cnt=Counts(st);

    if (check_matching(st) == 1) 
        printf("OK_%d\n",cnt); 
    else 
        printf("Wrong_%d\n",cnt); 


    return 0;
}
