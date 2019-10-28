//
// Created by 1655664358@qq.com on 2019/10/28.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int front,near=0;

void createBiTree(BiTree *tree)
{
    *tree = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->data=1;
    (*tree)->lchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->lchild->data=2;

    (*tree)->rchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->rchild->data=3;

    (*tree)->lchild->lchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->lchild->lchild->data=4;
    (*tree)->lchild->rchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->lchild->rchild->data=5;

    (*tree)->lchild->lchild->lchild=NULL;
    (*tree)->lchild->lchild->rchild = NULL;

    (*tree)->lchild->rchild->lchild = NULL;
    (*tree)->lchild->rchild->rchild = NULL;

    (*tree)->rchild->lchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->rchild->lchild->data=6;
    (*tree)->rchild->rchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->rchild->rchild->data=7;

    (*tree)->rchild->lchild->lchild= NULL;
    (*tree)->rchild->lchild->rchild = NULL;
    (*tree)->rchild->rchild->lchild = NULL;
    (*tree)->rchild->rchild->rchild = NULL;
}

void displayItem(BiTNode *elem)
{
    printf("%d\n",elem->data);
}

void enQueue(BiTree *a,BiTNode *node)
{
    a[near++]=node;
}
BiTNode *deQueue(BiTree *a)
{
    return a[front++];
}
void PreOrderTraserve(BiTree T)
{
    if (T){
        displayItem(T);
        PreOrderTraserve(T->lchild);
        PreOrderTraserve(T->rchild);
    }
}
int main(void)
{

    BiTree tree;
   createBiTree(&tree);

   printf("%d\n",tree->rchild->data);

   printf("************************\n");
   PreOrderTraserve(tree);

   printf("层序遍历................\n");
   BiTree a[20];
   BiTree p;
   enQueue(a,tree);
    while (front<near){
        p = deQueue(a);
        displayItem(p);
        if (p->lchild!=NULL){
            enQueue(a,p->lchild);
        }
        if (p->rchild!=NULL){
            enQueue(a,p->rchild);
        }
    }
    return 0;
}