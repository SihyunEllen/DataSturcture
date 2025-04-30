#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int size;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode)
{
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->size = size;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}
void PRT(treeNode * A)
{
  treeNode* tmp = A;
  if(tmp!=NULL)
  {
    printf("%d " ,tmp->size);
    if(tmp->left!=NULL) printf("%d " ,tmp->left->size);
    if(tmp->right!=NULL) printf("%d " ,tmp->right->size);
  }
}

int main()
{
    
    treeNode* F8 = makeRootNode(80, NULL, NULL);
    treeNode* F7 = makeRootNode(130, NULL, NULL);
    treeNode* F6 = makeRootNode(120, F7, F8);
    treeNode* F5 = makeRootNode(90, NULL, NULL);
    treeNode* F4 = makeRootNode(70, NULL, NULL);
    treeNode* F3 = makeRootNode(50, NULL, F6);
    treeNode* F2 = makeRootNode(30, F4, F5);
    treeNode* F1 = makeRootNode(20, F2, F3);

    int n; 
    scanf("%d",&n);
    treeNode* tmp;
  
  
  
    switch(n){
          case 1:
            PRT(F1);
            break;
          case 2:
            PRT(F2);
            break;
          case 3:
            PRT(F3);
            break;
          case 4:
            PRT(F4);
            break;
          case 5:
            PRT(F5);
            break;
          case 6:
            PRT(F6);
            break;
          case 7:
            PRT(F7);
            break;
          case 8:
            PRT(F8);
            break;
          default:
            printf("-1");
            break;
          
    }
     

    return 0;
}
