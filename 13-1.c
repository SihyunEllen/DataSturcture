#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode {
    int data;
    int id;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* makeRootNode(int id, int data, treeNode* leftNode, treeNode* rightNode)
{
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    root->id = id;
    return root;
}

void inorder(treeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

void preorder(treeNode* root) {
    if (root == NULL)
        return;

    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(treeNode* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->data);
}

void find(treeNode* root, int type, int id) {
    if (root == NULL)
        return;

    if (root->id == id) {
        if (type == 1)
            preorder(root);
        else if (type == 2)
            inorder(root);
        else if (type == 3)
            postorder(root);
    }

    find(root->left, type, id);
    find(root->right, type, id);
}

int main()
{
    treeNode* F8 = makeRootNode(8, 80, NULL, NULL);
    treeNode* F7 = makeRootNode(7, 130, NULL, NULL);
    treeNode* F6 = makeRootNode(6, 120, F7, F8);
    treeNode* F5 = makeRootNode(5, 90, NULL, NULL);
    treeNode* F4 = makeRootNode(4, 70, NULL, NULL);
    treeNode* F3 = makeRootNode(3, 50, NULL, F6);
    treeNode* F2 = makeRootNode(2, 30, F4, F5);
    treeNode* F1 = makeRootNode(1, 20, F2, F3);

    int type, Id;
    scanf("%d %d", &type, &Id);

    if (Id <= 0 || Id > 8)
        printf("-1");
    else
        find(F1, type, Id);

    return 0;
}
