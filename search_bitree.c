//
// Created by 1655664358@qq.com on 2019/8/1.
//

/**
 * 二叉排序树【二叉查找树】
 * 主要是树的构建和查找过程
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define ElemType int
#define KeyKey int
typedef struct BiTNode
{
    ElemType data;
    struct BiTnode *lchild,*rchild;
}BiTNode,*BiTree;

int searchBST(BiTree T,KeyKey key,BiTree f,BiTree *p) //(null,3,null,p) (node3,4,null,p) (node3,2,null,p)
{
    if (!T){//null
        *p = f;//p=f=null  p=f=node3 p=f=node3
        return FALSE;
    }
    else if(key==T->data){
        *p = T;
        return TRUE;
    }
    else if(key<T->data){
        return searchBST(T->lchild,key,T,p);//(node3->lchild=null,2,node3,p)
    }else{
        return searchBST(T->rchild,key,T,p);//(node3->rchild=null,4,node3,p) (5>3=node4,5,node3,p) (5>4=node2,5,node4,p) (5>2=null,5,node2,p)
    }
}
int insertBST(BiTree *T,ElemType e)
{
    BiTree p = NULL;
    if (!(searchBST((*T),e,NULL,&p))){

        BiTree s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->rchild = NULL;

        if (!p){
            (*T) = s;//T=node3
        }
        else if (e<p->data){
            p->lchild = s;//node3->lchild=node2
        }else{
            p->rchild = s;//node3->rchild=node4 5>node2 node2->rchild=node5
        }

        return TRUE;
    }
    return FALSE;

}

int deleteTNode(BiTree *p)
{
    BiTree q,s;
    if (!(*p)->lchild&&!(*p)->rchild){//结点为叶子结点
        *p = NULL;
        return TRUE;
    }
    else if (!(*p)->lchild){//结点没有左子树，则当前结点直接等于右子树
        q = *p;
        (*p) = (*p)->rchild;
        free(q);
    }else if (!(*p)->rchild){//当前结点没有右子树，当前结点直接等于左子树
        q = *p;
        (*p) = (*p)->lchild;
        free(q);
    }else{
        q = *p;
        s = (*p)->lchild;//当前结点的左结点
        while(s->rchild){
            q = s;
            s = s->rchild;//当前结点的右结点
        }

        (*p)->data = s->data;
        if (q!=(*p)){
            q->rchild=s->lchild;
        }else{
            q->lchild=s->lchild;
        }
        free(s);

    }
    return TRUE;

}
int deleteBST(BiTree *T,ElemType key)
{
    if (!(*T)){
        return FALSE;
    }
    else if (key == (*T)->data){
        deleteTNode(T);
        return TRUE;
    }else if (key<(*T)->data){
        return deleteBST(&(*T)->lchild,key);
    }else{
        return deleteBST(&(*T)->rchild,key);
    }
}
void displayTree(BiTree T){
    if (T){
        displayTree(T->lchild);
        printf("%d\n",T->data);
        displayTree(T->rchild);
    }
}
int main()
{

    int i;
    int a[5] = {3,4,2,5,9};
    BiTree T = NULL;

    for(i=0;i<5;i++){
        insertBST(&T,a[i]);//(null,3) (node3,4) (node3,2) (node3,5)
    }

    displayTree(T);

    printf("\n");
    printf("**********************************\n");
    deleteBST(&T,3);
    displayTree(T);
    return EXIT_SUCCESS;
}