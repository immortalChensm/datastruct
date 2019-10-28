//
// Created by 1655664358@qq.com on 2019/10/25.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

QNode *initQueue()
{
    QNode *queue = (QNode*)malloc(sizeof(QNode));
    queue->next = NULL;
    return queue;
}

QNode *enQueue(QNode *rear,int data)
{
    QNode *enElem = (QNode*)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    rear->next=enElem;
    rear = enElem;
    return rear;
}

QNode *deQueue(QNode *front,QNode *near)
{
    if (front->next==NULL){
        printf("queue is null\n");
        return near;
    }
    QNode *p = front->next;
    printf("elem is %d\n",p->data);
    front->next = p->next;
    if (p==near){
        near=front;
    }
    free(p);
    return near;
}
int main(void)
{
    QNode *queue,*front,*near;
    queue=front=near=initQueue();
   
    near = enQueue(near,1);
    printf("%d\n",front->next->data);
    near = enQueue(near,2);
    near = enQueue(near,3);
    near = enQueue(near,4);

    printf("%d\n",front->next->data);

    near = deQueue(front,near);

    return 0;
}