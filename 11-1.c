#define _CRT_SECURE_NO_WARNINGS 

#include<stdlib.h>
#include<string.h>
#include <stdio.h>

typedef int element;

typedef struct QueueType {
	element* data;
	int front, rear;
}Queue;
 
void init_queue(Queue* q,int quesize);
int is_empty(Queue* q);
int is_full(Queue* q, int n);
void enqueue(Queue* q, int data, int n);
element dequeue(Queue* q, int n);
void print_queue(Queue* q, int n);

int main(void)
{
	int quesize ,n , Data;
	scanf("%d", &quesize);
	scanf("%d", &n);
	Queue* q = malloc(sizeof(Queue));
	q->data = (int*)malloc(sizeof(int) * quesize);
	init_queue(q, quesize);
	char str[2];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "I") == 0)
		{
			scanf("%d", &Data);
			if (is_full(q, quesize)) {
				printf("overflow\n");
				print_queue(q,quesize);
				break;
			}enqueue( q, Data, quesize);
		}
		else if (strcmp(str, "D") == 0)
		{
			if (is_empty(q))
			{
				printf("underflow\n"); break;
			}dequeue( q,quesize);
		}
		else if (strcmp(str, "P") == 0)
		{
			print_queue(q,quesize);
		}
	}
	return 0;
}


//큐 초기화 
void init_queue(Queue* q,int quesize) {
	q->front = q->rear = 0;
	for (int i = 0; i < quesize; i++)
	{
		q->data[i] = 0;
	}
}

//큐가 비어 있는지 확인
int is_empty(Queue* q) {
	return (q->front == q->rear);
}

//큐가 가득 찼는지 확인
int is_full(Queue* q, int n) {
	return (q->front == ((q->rear + 1) % n));
}

//큐가 가득 차 있는지 확인 후 삽입 연산
void enqueue(Queue* q, int data, int n) {
	if (is_full(q, n)) {
		return;
	}
	else {
		q->rear = (q->rear + 1) % n;
		q->data[q->rear] = data;
	}
}

//큐가 비어 있는지 확인 후 삭제 연산
element dequeue(Queue* q, int n) {
	if (is_empty(q)) {
		return;
	}
	else {
		q->front = (q->front + 1) % n;
		int data = q->data[q->front];
		q->data[q->front] = 0;
		return data;
	}
}

//큐의 모든 요소 출력
void print_queue(Queue* q, int quesize) {
	
	for (int i = 0; i < quesize; i++)
	{
		printf(" %d", q->data[i]);
	}
	printf("\n");
}
