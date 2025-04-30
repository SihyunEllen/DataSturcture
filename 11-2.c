#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
    int count; // 큐 안의 노드 개수  
}Queue;

void initQueue(Queue* queue);
int isEmpty(Queue* queue);
void add_front(Queue* queue, int Data);
void add_rear(Queue* queue, int Data);
void delete_front(Queue* queue);
void delete_rear(Queue* queue);
void PRT(Queue* queue);



int main()
{   
    int n;
    int Data;
    char str[3];

    Queue* q = malloc(sizeof(Queue));
    initQueue(q);
    
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s",str);
        
        if (strcmp(str,"AF")==0)
        {
           scanf("%d",&Data);
           add_front(q,Data);
        }
        else if (strcmp(str,"AR")==0)
        {
            scanf("%d", &Data);
            add_rear(q, Data);
        }
        else if (strcmp(str, "DF") == 0)
        {
            if (isEmpty(q)) 
            {
                printf("underflow\n");
                break;
            }
            delete_front(q);
           
        }
        else if (strcmp(str, "DR") == 0)
        {
            if (isEmpty(q)) 
            {
                printf("underflow\n");
                break;
            }
            delete_rear(q);
           
        }
        else if (strcmp(str, "P") == 0)
        {
            PRT(q);
            printf("\n");
        }
    }
    

    return 0;
}








void initQueue(Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;    // 큐 안의 노드 개수를 0으로 설정
}

int isEmpty(Queue* queue)
{
    return queue->count == 0;    // 큐안의 노드 개수가 0이면 빈 상태
}

void add_front(Queue* queue, int Data)
{
    Node* newNode = (Node*)malloc(sizeof(Node)); // newNode 생성
    newNode->data = Data;
    newNode->prev = NULL;

    if (isEmpty(queue))    // 큐가 비어있을 때
    {
        queue->rear = newNode;
        newNode-> next = NULL;
    }
    else    // 비어있지 않을 때
    {
        queue->front->prev = newNode;    //맨 뒤의 다음을 newNode로 설정
        newNode->next = queue->front;
    }
    queue->front = newNode;    //맨 앞을 newNode로 설정   
    queue->count++;    //큐안의 노드 개수를 1 증가
}

void add_rear(Queue* queue, int Data)
{
    Node* newNode = (Node*)malloc(sizeof(Node)); // newNode 생성
    newNode->data = Data;
    newNode->next = NULL;

    if (isEmpty(queue))    // 큐가 비어있을 때
    {
        queue->front = newNode;
        newNode->prev = NULL;
    }
    else    // 비어있지 않을 때
    {
        queue->rear->next = newNode;    //맨 뒤의 다음을 newNode로 설정
        newNode->prev = queue->rear;
    }
    queue->rear = newNode;    //맨 뒤를 newNode로 설정   
    queue->count++;    //큐안의 노드 개수를 1 증가
}


void delete_front(Queue* queue)
{
    int data;
    Node* ptr;
    if (isEmpty(queue))    //큐가 비었을 때
    {
       return;
    }
    ptr = queue->front;    //맨 앞의 노드 ptr 설정 
    data = ptr->data;  
    queue->front = ptr->next;    
    free(ptr);    // ptr 해제 
    queue->count--;    //큐의 노드 개수를 1 감소

    
}
void delete_rear(Queue* queue)
{
    int data;
    Node* ptr;
    if (isEmpty(queue))    
    {
        return;
    }
    ptr = queue->rear;    //맨 뒤의 노드 ptr 설정 
    data = ptr->data;   
    queue->rear = ptr->prev; 
    queue->rear->next = NULL;
    free(ptr);    // ptr 해제 
    queue->count--;    

    
}

void PRT(Queue* queue)
{
    Node* tmp = queue->front;
    while (tmp != NULL)
    {
        printf(" %d", tmp->data);
        tmp = tmp->next;
    }
}
