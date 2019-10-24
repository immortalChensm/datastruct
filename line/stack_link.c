//
// Created by 1655664358@qq.com on 2019/10/24.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct linkStack{
    int data;
    struct linkStack *next;
}linkStack;

linkStack *push(linkStack *stack,int elem)
{
    linkStack *line = (linkStack*)malloc(sizeof(linkStack));
    line->data = elem;
    line->next = stack;
    stack = line;
    return stack;
}

linkStack *pop(linkStack *stack)
{
    if (stack){

        linkStack *p = stack;
        stack = stack->next;
        printf("pop elem is %d\n",p->data);
        if (stack){
            printf("next stack data is %d\n",stack->data);
        }else{
            printf("next stack is null\n");
        }
    }else{
        printf("null stack\n");
        return stack;
    }
}
int main(void)
{
    linkStack *stack = NULL;
    stack = push(stack,1);
    stack = push(stack,2);
    stack = push(stack,3);
    stack = push(stack,4);

    stack = pop(stack);
    return 0;
}