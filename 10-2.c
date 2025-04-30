#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct {
  char data[MAX_STACK_SIZE];
  int num;
} StackType;


void Initialize(StackType *s){s->num = -1;}
int IsEmpty(StackType *s){return (s->num == -1);}
int IsFull(StackType *s){return (s->num >= (MAX_STACK_SIZE - 1));}
void Push(StackType *s, char ipt);
char Pop(StackType *s);
int Cal(char arr[]);
char Peek(StackType *s);


int main(void){
   char cal[MAX_STACK_SIZE];
   int num;
   scanf("%d",&num);
   getchar();

   for(int i=0;i<num;i++){
      scanf("%s", &cal);
      int answer = Cal(cal);
      printf("%d\n",answer);
   }
   return 0;
}


void Push(StackType *s, char ipt){
   if (IsFull(s)) {
      printf("Full\n");
      return;
   }
   else s->data[++(s->num)] = ipt;
}


char Pop(StackType *s){
   if (IsEmpty(s)) {
      printf("EMPTY\n");
      exit(1);
   }
   else return s->data[(s->num)--];
}

char Peek(StackType *s){
   if (IsEmpty(s)) {
      printf("EMPTY\n");
      exit(1);
   }
   else return s->data[s->num];
}



int Cal(char arr[]){
   int op1, op2, value;
   char ch;
   StackType s;

   Initialize(&s);

   for (int i = 0; i < strlen(arr); i++) {
      
      ch = arr[i];//현재 인덱스의 값을 저장
      
      
      if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
         value = ch - '0';   
         Push(&s, value); // 숫자일 경우
      }
      
      else {   
         
         op2 = Pop(&s);
         op1 = Pop(&s);

         switch (ch) { 
         case '+': Push(&s, op1 + op2); break;
         case '-': Push(&s, op1 - op2); break;
         case '*': Push(&s, op1 * op2); break;
         case '/': Push(&s, op1 / op2); break;
         }
      }
   }
   return Pop(&s);
}
