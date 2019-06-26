//
// Created by 1655664358@qq.com on 2019/6/26.
//
#include <stdlib.h>
#include <stdio.h>
int max=5;
int enQueue(int *a,int front,int near,int data);
int deQueue(int *a,int front,int near);
int main()
{
    int a[5];
    int front,near;
    front=near=0;
    near = enQueue(a,front,near,1);
    near = enQueue(a,front,near,2);
    near = enQueue(a,front,near,3);
    near = enQueue(a,front,near,4);
//    near = enQueue(a,front,near,5);

    printf("front=%d,near=%d\n",front,near);
    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);
    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);
    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);
    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);
    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);

    near = enQueue(a,front,near,8);//4+1%5=0
    near = enQueue(a,front,near,9);//5+1%5=1

    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);

    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);


    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);

    near = enQueue(a,front,near,8);//4+1%5=0
    near = enQueue(a,front,near,9);//5+1%5=1


    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);

    front = deQueue(a,front,near);
    printf("front=%d,near=%d\n",front,near);
    return 0;
}

int enQueue(int *a,int front,int near,int data)
{
    if((near+1)%max==front){  //1:当进队满时near=4 front=0 当出队完时near=4 front=4 2:4+1%5=0==4 此时队列下标又从0开始了
        printf("space is full\n");
        return near;
    }
    a[near%max] = data;//0 1 2 3 4 0
    near++;
    return near;
}

int deQueue(int *a,int front,int near)
{
    if (front==(near%max)){//1:进队满，出队完时near=4,front=4 2:当进队操作第二轮开始时，near=5,front=4 此时front=0又重新开始
        printf("null queue\n");
        return front;
    }
    printf("%d\n",a[front]);
    front = ((front+1)%max);//0 1 2 3 4 0 1 2 3 4
    return front;
}