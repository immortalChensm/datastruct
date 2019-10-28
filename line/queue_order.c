//
// Created by 1655664358@qq.com on 2019/10/25.
//

#include <stdio.h>
#include <stdlib.h>

int enQueue(int *a,int near,int data)
{
    a[near]=data;
    near++;
    return near;
}
void deQueue(int *a,int front,int near)
{
    while(front!=near){
        printf("%d\n",a[front]);
        front++;
    }
}
int main(void)
{
    int a[100];
    int front,near;
    front=near=0;

    near = enQueue(a,near,1);
    near = enQueue(a,near,2);
    near = enQueue(a,near,3);
    near = enQueue(a,near,4);

    deQueue(a,front,near);
    return 0;
}