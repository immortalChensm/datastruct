//
// Created by 1655664358@qq.com on 2019/10/28.
//

#include <stdlib.h>
#include <stdio.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void createBiTree(BiTree *tree)//要传递二级指针
{
    *tree = (BiTree)malloc(sizeof(BiTNode));//tree=*(&tree)
    (*tree)->data = 1;
    (*tree)->lchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->lchild->data=2;
    (*tree)->rchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->rchild->data=3;

    (*tree)->lchild->lchild = (BiTree)malloc(sizeof(BiTNode));
    (*tree)->lchild->lchild->data=4;
    (*tree)->lchild->rchild = NULL;

    (*tree)->rchild->lchild = NULL;
    (*tree)->rchild->rchild = NULL;

    (*tree)->lchild->lchild->lchild = NULL;
    (*tree)->lchild->lchild->rchild = NULL;
}
int main(void)
{

    BiTree tree;//变量名tree 变量内容=null 变量地址xx
    createBiTree(&tree);

    printf("%d\n",tree->lchild->lchild->data);
    return 0;
}