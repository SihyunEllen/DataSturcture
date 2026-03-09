#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}node;
void Input(node* header , int num);
int subset(node* headA, node* headB);
void PRT(node* head);

int main(void) {
  int n1 , n2 , num;
  node * head1 =(node*)malloc(sizeof(node));
  node * head2 =(node*)malloc(sizeof(node));
  scanf("%d",&n1);
  for(int i=0; i<n1; i++)
  {
      scanf("%d",&num);
      Input(head1,num);
  }
  scanf("%d",&n2);
  for(int i=0; i<n2; i++)
  {   scanf("%d",&num);
      Input(head2,num);
  }

  printf("%d",subset(head1, head2));
  
  return 0;
}


void Input(node* header , int num) 
{                              
    node* new;

    new = (node*)malloc(sizeof(node));                                     
    if (new == NULL) return;
    new-> data = num;
    new->next = NULL;

    while (1) {                                                             
        if (header->next == NULL)
            break;
        header = header->next;
    }

    header->next = new;                                                    
}


int subset(node* headA, node* headB) {
  node* nodeA = headA->next;
  node* nodeB = headB->next;
  while (nodeA != NULL) {
    while (nodeB != NULL && nodeB->data < nodeA->data) {
      nodeB = nodeB->next;
    }
    if (nodeB == NULL || nodeB->data != nodeA->data) {
      return nodeA->data;
    }
    nodeA = nodeA->next;
    nodeB = nodeB->next;
  }
  return 0;
}





void PRT(node* head)
{
  while(head->next!=NULL)
    {
      printf("%d->" , head -> next -> data);
      head = head -> next;
    }
  printf("\n");
}
