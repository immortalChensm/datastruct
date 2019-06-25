//
// Created by 1655664358@qq.com on 2019/6/23.
//
#include <stdlib.h>
#include <stdio.h>
/**
 * 双向链表
 * 添加：前，后，后，前
 * 删除：前，后
 */
typedef struct line{
    struct line *piror;
    int data;
    struct line *next;
}line;

line *initLine(line *head);
line *insertLine(line *head,int add,int data);
line *delLine(line *head,int data);
int searchLine(line *head,int data);
line *updateLine(line *head,int add,int data);
void display(line *head);
int main()
{
    line *head=NULL;
    head = initLine(head);
    display(head);

    // printf("%d,%d,%d",head->data,head->next->data,head->next->next->data);

   // head = insertLine(head,2,100);
    //display(head);
//    head = delLine(head,100);
//    display(head);
//    printf("search some node\n");
//    int index = searchLine(head,3);
//    printf("%d\n",index);
//    printf("update some node\n");
//    head = updateLine(head,2,800);
//    display(head);

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

    //最后一个元素指向头结点【构成单向循环链表】
    link->next = head;
    head->piror = link;//头结点指向最后一个结点
    return head;

}

void display(line *head)
{
    line *temp = head;//1|2|3|4|5
    while(temp->next!=head){
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

line *insertLine(line *head,int add,int data)
{
    line *temp = (line *)malloc(sizeof(line));
    temp->data=data;
    temp->next=NULL;
    temp->piror = NULL;

    if (add==1){
        temp->next = head;  //插在头
        temp->piror = NULL;
    }else{
        line *body = head;
        for(int i=1;i<=add;i++){
            body = body->next;
        }
        if (body->next==NULL){
            body->next=temp;
            temp->piror=body;
        }else{

            body->next->piror=temp;//前
            temp->next=body->next;//后

            body->next=temp;//后
            temp->piror=body;//前
        }
    }
    return head;
}

line *delLine(line *head,int data)
{
    line *temp = head;
    while(temp){
        if(temp->data==data){
            //前
            temp->piror->next=temp->next;//1|2|3|4|5 当前节点的上一个节点=当前的下一个结点
            temp->next->piror=temp->piror;//当前节点的下一个节点的前驱结点=当前结点的前驱结点
            free(temp);
        }
        temp = temp->next;
    }
    return head;
}

int searchLine(line *head,int data)
{
    line *t = head;
    int i=1;
    while(t){
        if(t->data==data){
            return i;
        }
        i++;
        t = t->next;
    }
    return -1;
}

line *updateLine(line *head,int add,int data)
{
    line *temp = head;
    for(int i=1;i<=add;i++){
        temp = temp->next;
    }
    temp->data=data;
    return head;
}