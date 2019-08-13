//
// Created by 1655664358@qq.com on 2019/8/12.
//

#include <stdlib.h>
#include <stdio.h>

#define LH +1
#define EH 0
#define RH -1

typedef int ElemType;
typedef enum {false,true}bool;

typedef struct BSTNode
{
    ElemType data;
    int bf;
    BSTNode *lchild,*rchild;
}*BSTree,BSTNode;

void R_Rotate(BSTree *p)
{
    BSTree lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = (*p);
    *p = lc;
}
void L_Rotate(BSTree *p)
{
    BSTree rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = *p;
    *p = rc;
}
void LeftBalance(BSTree *T)
{
    BSTree lc,rd;
    lc = (*T)->lchild;
    switch (lc->bf){
        case LE:
            (*T)->bf = lc->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            break;
    }
}
int InsertAVL(BSTree *T,ElemType e,bool *taller)
{
    if ((*T)==NULL){
        (*T) = (BSTree)malloc(sizeof(BSTNode));
        (*T)->bf = EH;
        (*T)->data = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*taller) = true;
    }
    else if (e ==(*T)->data){
        *taller = false;
        return 0;
    }
    else if (e<(*T)->data){

        if (!InsertAVL(&(*T)->lchild,e,taller)){
            return 0;
        }
        if (*taller){
            switch (*taller){
                case LH:
                    break;
                case EH:
                    (*T)->bf = LH;
                    *taller = true;
                    break;
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
            }
        }
    }else{
        if (!InsertAVL(&(*T)->rchild,e,taller)){
            return 0;
        }
        if (*taller){
            switch (*taller){
                case LH:
                    break;
                case EH:
                    break;
                case RH:
                    break;
            }
        }
    }
    return 1;
}
int main()
{
    int i,nArr[] = {1,23,45,34,98,9,4,35,23};
    BSTree root = NULL,pos;
    bool taller;
    for (int i = 0; i < sizeof(nArr)/ sizeof(int) ; ++i) {
        InsertAVL(&root,nArr[i],&taller);
    }

}