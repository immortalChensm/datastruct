//
// Created by 1655664358@qq.com on 2019/6/26.
//

#include <stdio.h>
#include <stdlib.h>
int enQueue(int *a,int near,int data);
void deQueue(int *a,int front,int near);
int  main()
{
    int a[5];
    int front,near;
    front=near=0;

    near = enQueue(a,near,1);
    near = enQueue(a,near,2);
    near = enQueue(a,near,3);

    printf("front=%d,near=%d\n",front,near);
    printf("dequeue test \n");
    deQueue(a,front,near);

    printf("*******************************\n");
    near = enQueue(a,near,4);
    near = enQueue(a,near,5);
    near = enQueue(a,near,6);


    deQueue(a,front,near);

    int b=5;
    printf("b/5=%d\n",5%5);

    return 0;
}

int enQueue(int *a,int near,int data)
{
    a[near] = data;
    near++;
    return near;
}

void deQueue(int *a,int front,int near)
{
    while (front!=near){
        printf("dequeue elem is %d\n",a[front]);
        front++;
    }

    printf("front=%d,near=%d\n",front,near);
}