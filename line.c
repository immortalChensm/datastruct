//
// Created by 1655664358@qq.com on 2019/6/23.
//
#include <stdlib.h>
#include <stdio.h>
/**
 * 双向链表
 */
typedef struct line{
    struct line *piror;
    int data;
    struct line *next;
}line;

line *initLine(line *head);
void display(line *head);
int main()
{
    line *head=NULL;
    head = initLine(head);
    display(head);

    // printf("%d,%d,%d",head->data,head->next->data,head->next->next->data);
    return 0;
}

line *initLine(line *head)
{
    head = (line*)malloc(sizeof(line));
    head->data=1;
    head->piror = NULL;
    head->next = NULL;

    line *link = head;
    for(int i=2;i<=5;i++){
        line *temp = (line*)malloc(sizeof(line));

        temp->next = NULL;
        temp->piror = NULL;
        temp->data=i;
        link->next = temp;
        temp->piror = link;
        //printf("temp.data=%d\n",temp->data);
        //1|2|  link = link->next
        //link = temp;
        link = link->next;
    }

    return head;

}

void display(line *head)
{
    line *temp = head;//1|2|3|4|5
    while(temp){
        if (temp->next==NULL){
            printf("%d\n",temp->data);
            break;
        }else{
            printf("%d<>",temp->data);
        }
        temp = temp->next;
        //printf("temp=%d\n",temp->data);
    }
}