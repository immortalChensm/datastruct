//
// Created by 1655664358@qq.com on 2019/6/27.
//

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef struct QNode
{
    ElemType data;
    struct QNode *next;

}QNode,*QNodePtr;
typedef int Status;
typedef struct {
    QNodePtr front;
    QNodePtr near;
}QueueLink;


Status enQueue(QueueLink *Q,ElemType data);
Status deQueue(QueueLink *Q,ElemType *data);
int main()
{
    QueueLink Q;
    QNodePtr Node = (QNodePtr)malloc(sizeof(QNode));
    Node->data = 'c';
    Node->next = NULL;

    Q.front = Node;//c
    Q.near = Node;//c
    enQueue(&Q,'A');
    enQueue(&Q,'B');
    enQueue(&Q,'C');
    char str;
    deQueue(&Q,&str);
    printf("%c\n",str);

    deQueue(&Q,&str);
    printf("%c\n",str);

    deQueue(&Q,&str);
    printf("%c\n",str);

    return 0;
}

Status enQueue(QueueLink *Q,ElemType data)
{
    QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
    p->data = data;
    p->next = NULL;

    Q->near->next = p;//1|2|3
    Q->near = p;

    return OK;
}

Status deQueue(QueueLink *Q,ElemType *data)
{
    if (Q->front==Q->near){
        return ERROR;
    }
    QNodePtr p = Q->front->next;
    *data = p->data;
    Q->front->next = p->next;
    if (Q->near==p){
        Q->near = Q->front;
    }
    free(p);
    return OK;
}