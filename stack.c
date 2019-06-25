//
// Created by 1655664358@qq.com on 2019/6/25.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
#define ERROR 0
#define OK 1
typedef struct stack{
    char *data;
    int top;
    int length;
}stack;
int push(stack *s,char data);
int pop(stack *s,char *data);
void display(stack *s);
int main()
{

    stack *s = (stack*)malloc(sizeof(stack));
    s->top=-1;
    s->data = (char *)malloc(MAXSIZE* sizeof(char));
    s->length=MAXSIZE;

    push(s,'a');//栈底
    push(s,'b');//栈底
    push(s,'c');//栈顶
    push(s,'d');//栈顶
    push(s,'e');//栈顶
    push(s,'f');//栈顶
    push(s,'g');//栈顶
    push(s,'h');//栈顶
//    push(s,'i');//栈顶
//    char result;
//    pop(s,&result);
//    printf("%c\n",result);
//    pop(s,&result);
//    printf("%c\n",result);
//    pop(s,&result);
//    printf("%c\n",result);
//
//    pop(s,&result);
//    printf("%c\n",result);
    display(s);
//    printf("%d %d\n",s->top,s->length);
//    //printf("size=%d\n", sizeof(*s->data));
//
//    char result;
//    pop(s,&result);
//    printf("%c\n",result);
//    pop(s,&result);
//    printf("%c\n",result);
//    pop(s,&result);
//    printf("%c\n",result);
    return 0;
}

void display(stack *s)
{
//    for(int i=0;i<=s->top;i++){
//        printf("%d=%c\n",i,s->data[i]);
//    }
     while(s->top>-1){
         printf("%c\n",s->data[s->top--]);
         if (s->top==-1){
             s->top=s->length;
         }
     }
}
int push(stack *s,char data)
{
    if (s->top==s->length){
        //增加内存空间  内存重新分配了
        char *temp = s->data;
        s->data = (char *)malloc((s->length+1)* sizeof(char));
        if (!s->data){
            return ERROR;
        }
        s->length+=1;
        for(int i=0;i<=s->length-1;i++){
            s->data[i] = temp[i];
        }
        s->top++;
        s->data[s->top] = data;
        //return ERROR;
    }else{
        s->top++;
        s->data[s->top] = data;
    }

    return OK;
}

int pop(stack *s,char *data)
{
    if (s->top==-1){
        return ERROR;
    }
    *data = s->data[s->top];

    s->top--;
    return OK;
}