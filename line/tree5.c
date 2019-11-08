//
// Created by 1655664358@qq.com on 2019/11/6.
//

#include <stdlib.h>
#include <stdio.h>
#define MAX 30
typedef char ElemType;
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstChild,*nextChild;
}CSNode,*CSTree;
int front,near;
CSTree initTree(CSTree tree)
{
    int num;
    char ch;
    printf("please input tree node number:\n");
    scanf("%d",&num);
    if (num!=0){
        for (int i = 0; i <num ; ++i) {


        }
    }
    return tree;
}

void createTree(CSTree *tree)
{

    if (*tree!=NULL&&(int)(*tree)->data!=0) {
        char ch;
        printf("please input %c of firstChild value\n",  (*tree)->data);

        scanf("%c", &ch);
        if ((int)ch != 0) {
            CSNode *nodeChild = (CSNode *) malloc(sizeof(CSNode));
            nodeChild->data = ch;
            nodeChild->firstChild = NULL;
            nodeChild->nextChild = NULL;
            printf("get first value is %c\n",nodeChild->data);
            (*tree)->firstChild = nodeChild;

        }
        printf("please input %c of nextChild value\n",  (*tree)->data);
        getchar();
        scanf("%c", &ch);
        if ((int)ch != 0) {
            CSNode *nodeChild = (CSNode *) malloc(sizeof(CSNode));
            nodeChild->data = ch;
            nodeChild->firstChild = NULL;
            nodeChild->nextChild = NULL;
            printf("get next value is %c\n",nodeChild->data);
            (*tree)->nextChild = nodeChild;
        }
        getchar();
        createTree((&(*tree)->firstChild));

        createTree((&(*tree)->nextChild));
    }
}

void enQueue(CSTree *a,CSNode *node)
{
    a[near++] = node;
}
CSNode *deQueue(CSTree *a)
{
    return a[front++];
}
int main()
{
    CSTree tree = (CSTree)malloc(sizeof(CSTree));
    tree->data = 'R';
    tree->firstChild = NULL;
    tree->nextChild = NULL;

    createTree(&tree);

    CSTree a[MAX];
    enQueue(a,tree);
    while (front<near){
        CSNode *node = deQueue(a);
        printf("%c\n",node->data);
        if (node->firstChild!=NULL){
            enQueue(a,node->firstChild);
        }
        if (node->nextChild!=NULL){
            enQueue(a,node->nextChild);
        }
    }
    return 0;
}