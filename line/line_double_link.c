//
// Created by 1655664358@qq.com on 2019/10/23.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct line
{
    struct line *piror;
    int data;
    struct line *next;
}line;

line *initLine();
void display(line *head);

line *insertLine(line *head,int data,int add)
{
    line *temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->next = NULL;
    temp->piror = NULL;
    if (add==1){
        temp->next = head;
        head->piror = temp;
        head = temp;
    }else{
        line *body = head;
        for (int i = 1; i < add-1; ++i) {
            body = body->next;
        }
        if (body->next==NULL){
            body->next = temp;
            temp->piror = body;
        }else{
            body->next->piror=temp;
            temp->next=body->next;

            body->next=temp;
            temp->piror=body;
        }
    }

    return head;

}
line *delLine(line *head,int data)
{
    line *temp = head;
    while (temp){
        if (temp->data==data){
            temp->piror->next=temp->next;
            temp->next->piror=temp->piror;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int searchLine(line *head,int data)
{
    line *t;
    int i=1;
    while (t){
        if (t->data==data){
            return i;
        }
        t = t->next;
        i++;
    }
    return -1;
}
line *updateLine(line *head,int data,int add)
{
    line *temp = head;
    for (int i = 1; i < add; ++i) {
            temp = temp->next;
    }
    temp->data = data;
    return head;
}
int main(void)
{

    line *head = initLine();
    display(head);
    printf("%d\n",head->next->next->next->data);

    head = insertLine(head,100,2);
    display(head);
    head = delLine(head,2);
    display(head);
    head = updateLine(head,200,2);
    display(head);
    return 0;
}

line *initLine()
{
    line *head = (line*)malloc(sizeof(line));
    head->piror = NULL;
    head->next = NULL;
    head->data = 1;

    line *list = head;
    for(int i=2;i<=5;i++){
        line *body = (line*)malloc(sizeof(line));
        body->data = i;
        body->piror = NULL;
        body->next = NULL;

        list->next = body;
        body->piror = list;

        list = list->next;

    }
    return head;

}

void display(line *head)
{
    line *temp = head;
    while (temp){
        if (temp->next == NULL){
            printf("%d\n",temp->data);
        }else{
            printf("%d<>",temp->data);
        }

        temp = temp->next;
    }
}