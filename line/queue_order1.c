//
// Created by 1655664358@qq.com on 2019/10/25.
//
#include <stdlib.h>
#include <stdio.h>
#define MAX 5
int enQueue(int *a,int front,int near,int data)
{
    if ((near+1)%MAX==front){
        printf("queue is full\n");
        return near;
    }
    a[near%MAX]=data;
    near++;
    return near;
}

int deQueue(int *a,int front,int near)
{
    if (front==near%MAX){
        printf("queue is null");
        return front;
    }
    printf("%d\n",a[front]);
    front = (front+1)%MAX;
    return front;
}
int main(void)
{
    int a[MAX];
    int front,near;
    front=near=0;

    near = enQueue(a,front,near,1);
    near = enQueue(a,front,near,2);
    near = enQueue(a,front,near,3);
    near = enQueue(a,front,near,4);
    //near = enQueue(a,front,near,5);

    front = deQueue(a,front,near);
    front = deQueue(a,front,near);
    front = deQueue(a,front,near);
    front = deQueue(a,front,near);
    front = deQueue(a,front,near);

    near = enQueue(a,front,near,5);
    front = deQueue(a,front,near);
    return 0;
}
