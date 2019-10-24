//
// Created by 1655664358@qq.com on 2019/10/24.
//

#include <stdio.h>
#include <stdlib.h>

int push(int *a,int top,int elem)
{
    a[++top]=elem;
    return top;
}
int pop(int *a,int top)
{
    if (top==-1){
        printf("null stack\n");
        return -1;
    }
    printf("%d\n",a[top]);
    top--;
    return top;
}
int main(void)
{

    int a[100];
    int top = -1;

    top = push(a,top,1);
    top = push(a,top,2);
    top = push(a,top,3);

    top = pop(a,top);
    top = pop(a,top);
    top = pop(a,top);
    top = pop(a,top);

    return 0;
}