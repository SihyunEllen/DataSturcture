#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int top = -1;
int flag = 0;

void push(char* stack, char k) {
    top += 1;
    stack[top] = k;

}
char pop(char* stack) {
     top -= 1;
    return stack[top + 1];
}


int IsEmpty(int top){if( top!=-1) return 0;}
int IsFull(int top){if (top>=100) return 0;}


int rank(char* stack, int j) {

    if (stack[j] == '|')
        return 1;
    else if (top != -1 && (stack[j] == '+' || stack[j] == '-') && ((stack[j - 1] == '|') || (stack[j - 1] == '&') || (stack[j - 1] == '<') || (stack[j - 1] == '>') || (stack[j - 1] == '+') || (stack[j - 1] == '-') || (stack[j - 1] == '*') || (stack[j - 1] == '/') || (stack[j - 1] == '!')))
        return 6;
    else if (top != j && j == 0 && (stack[j] == '+' || stack[j] == '-')) {
        flag = 1;
        return 6;
    }
    else if (stack[j] == '&')
        return 2;
    else if (stack[j] == '<' || stack[j] == '>')
        return 3;
    else if (stack[j] == '+' || stack[j] == '-')
        return 4;
    else if (stack[j] == '*' || stack[j] == '/')
        return 5;
    else if (stack[j] == '!')
        return 6;
    else
        return 0;
}

int main()
{
    char formula[101];
    char stack[101] = { '\0' };
    int n, i, j, len;

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {

        flag = 0;

        scanf("%s", formula);
        len = strlen(formula);

        for (j = 0; j < len; j++) {
            if (rank(formula, j) == 0 && formula[j] != '(' && formula[j] != ')')
                printf("%c", formula[j]);

            else if (formula[j] == '(')
                push(stack, formula[j]);

            else if (formula[j] == ')') {
                while (stack[top] != '(')
                    printf("%c", pop(stack));
                pop(stack);
            }

            else if (rank(formula, j) == 6)
                push(stack, formula[j]);

            else {

                if (flag == 1) {
                    printf("%c", pop(stack));
                    flag = 0;
                }

                else {
                    while (IsEmpty(top)==0 && (rank(formula, j) <= rank(stack, top)))
                        printf("%c", pop(stack));
                }

                if (formula[j] == '&' || formula[j] == '|') {
                    push(stack, formula[j]);
                    j += 1;
                }
                push(stack, formula[j]);
            }
        }

        while (top != -1)
            printf("%c", pop(stack));
        printf("\n");
    }
}
