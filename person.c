//
// Created by 1655664358@qq.com on 2019/6/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct person{
    int number;
    struct person *next;
}person;

person *initPerson(int n);
void display(person *p);
void findK(person *head);
int main()
{

    person *head = initPerson(6);
   // display(head);
    findK(head);

    return 0;
}

person *initPerson(int n)
{
    person *head = (person*)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;

    person *cyclie = head;

    for(int i=2;i<=n;i++){

        person *temp = (person*)malloc(sizeof(person));
        temp->number = i;
        temp->next = NULL;

        cyclie->next = temp;
        cyclie = cyclie->next;
    }
    cyclie->next = head;
    return head;
}

void display(person *p)
{
    person *temp = p;
    while(temp){
        printf("%d<>",temp->number);
        temp = temp->next;
    }
}

void findK(person *head)
{
    person *tail = head;
    while(tail->next!=head){
        tail = tail->next;//找到最后一个结点
    }
    //printf("%d\n",tail->number);

    int k=3;
    person *p = head;
    while(p->number!=k){
        tail = p;//找到指定结点的上一个结点
        p = p->next;//找到指定结点
    }

    //从指定结点开始【不包括本结点】
    while(p->next!=p){
        //printf("%d\n",p->number);
//        int m=2;
//        for(int i=1;i<m;i++){
//            tail = p;//3
//            p  = p->next;//4
//        }
        //printf("%d\n",p->number);

        tail->next = p->next;//5
        printf("find k is %d\n",p->number);
        //free(p);
        p = tail->next;
    }
    //printf("%d\n",tail->number);
    //printf("%d\n",p->number);
    //printf("find k %d\n",p->number);
    //free(p);
}