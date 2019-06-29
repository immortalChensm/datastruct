//
// Created by 1655664358@qq.com on 2019/6/29.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//串链式存储
#define linkNum 3
typedef struct link
{
    char str[linkNum];
    struct link *next;
}link;

link *initLink(link *head,char *data);
void displayLink(link *head);
int main()
{
    char *data = "hello,china";
    link *head = NULL;
    head = initLink(head,data);
    displayLink(head);
    return 0;
}

link *initLink(link *head,char *data)
{
    int length = strlen(data);
    int num = length/linkNum;//3/4 小数
    if (length%linkNum){
        num++;//除不尽就加1
    }
    head = (link*)malloc(sizeof(link));
    head->next = NULL;

    link *temp = head;
    //控制节点数量
    for(int i=0;i<num;i++){

        //控制每个结点的存储字符长度
        int j=0;
        for(;j<linkNum;j++){
            if (i*linkNum+j<length){
                temp->str[j] = data[i*linkNum+j];//0+1 3+0
            }else{
                temp->str[j] = '\0';
            }
        }
        //0+3 3+3
        if (i*linkNum+j<length){
            link *newLink = (link*)malloc(sizeof(link));
            newLink->next = NULL;
            temp->next = newLink;
            temp = newLink;
        }
    }

    return head;
}

void displayLink(link *head)
{
    link *temp = head;
    while(temp){
        for(int i=0;i<linkNum;i++){
            printf("%c\n",temp->str[i]);
        }
        temp = temp->next;
    }

}