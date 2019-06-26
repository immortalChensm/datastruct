//
// Created by 1655664358@qq.com on 2019/6/26.
//

#include <stdlib.h>
#include <stdio.h>
//链栈结构结点
typedef struct linkStack{
    int data;
    struct linkStack *next;
}linkStack;

linkStack *push(linkStack *link,int data);
linkStack *pop(linkStack *link);
void display(linkStack *link);
int main()
{

    linkStack *link = NULL;
    link = push(link,1);//压栈
    link = push(link,2);
    link = push(link,3);

    display(link);

    printf("pop stack test\n");
    link = pop(link);//弹栈
    display(link);
    return 0;
}

void display(linkStack *link)
{
    while(link){
        printf("%d\n",link->data);
        link = link->next;
    }
}

linkStack *push(linkStack *link,int data)
{
    linkStack *temp = (linkStack*)malloc(sizeof(linkStack));
    temp->data = data;
    temp->next = link;
    link = temp;
    return link;
}

linkStack *pop(linkStack *link)
{
    if (link){
        linkStack *p = link;
        link = link->next;
       if (link){
           printf("next elem is %d\n",link->data);
       }else{
           printf("null stack");
       }
       printf("pop elem is %d\n",p->data);
       free(p);
    }else{
        printf("null stack\n");
        return link;
    }
    return link;
}