//
// Created by 1655664358@qq.com on 2019/7/10.
//

#include <stdio.h>
#include <stdlib.h>


/**
 * 孩子兄弟表示法
 * 每个结点：存储数据之外，还要存储它的孩子结点，兄弟结点
 * 经过转换之后会将一棵普通树构成二叉树
 */
typedef char ElemType;
typedef struct CSNode{
    ElemType data;
    struct CSNode *firstChild,*nextsibling;
}CSNode,*CSTree;

CSTree initTree();
void displayTree(CSTree node);
int main()
{
    CSTree node = initTree();
    printf("%c\n",node->data);
    printf("%c\n",node->firstChild->data);
    printf("***************************\n");
    displayTree(node);
    return 0;
}

/**
 * 初始化树
 * @return
 */
CSTree initTree()
{
    CSTree nodeR = (CSTree)malloc(sizeof(CSNode));
    nodeR->data='R';
    nodeR->nextsibling=NULL;

    CSTree nodeA = (CSTree)malloc(sizeof(CSNode));
    nodeA->data='A';
    nodeR->firstChild=nodeA;

    CSTree nodeD = (CSTree)malloc(sizeof(CSNode));
    nodeD->data='D';

    CSTree nodeB = (CSTree)malloc(sizeof(CSNode));
    nodeB->data='B';

    nodeA->firstChild=nodeD;
    nodeA->nextsibling=nodeB;

    CSTree nodeE = (CSTree)malloc(sizeof(CSNode));
    nodeE->data='E';
    nodeE->firstChild=NULL;
    nodeE->nextsibling=NULL;

    nodeD->firstChild=NULL;
    nodeD->nextsibling=nodeE;

    CSTree nodeC = (CSTree)malloc(sizeof(CSNode));
    nodeC->data='C';

    nodeB->firstChild=NULL;
    nodeB->nextsibling=nodeC;

    CSTree nodeF = (CSTree)malloc(sizeof(CSNode));
    nodeF->data='F';

    nodeC->firstChild=nodeF;
    nodeC->nextsibling=NULL;

    CSTree nodeG = (CSTree)malloc(sizeof(CSNode));
    nodeG->data='G';
    nodeF->nextsibling=NULL;
    nodeF->firstChild=nodeG;

    CSTree nodeH = (CSTree)malloc(sizeof(CSNode));
    nodeH->data='H';
    nodeG->firstChild=NULL;
    nodeG->nextsibling=nodeH;


    CSTree nodeK = (CSTree)malloc(sizeof(CSNode));
    nodeK->data='K';
    nodeK->firstChild=NULL;
    nodeK->nextsibling=NULL;
    nodeH->firstChild=NULL;
    nodeH->nextsibling=nodeK;

    return nodeR;
}

void displayTree(CSTree node)
{
    if (node){
        printf("%c\n",node->data);
        displayTree(node->nextsibling);
        displayTree(node->firstChild);

    }
}