//
// Created by 1655664358@qq.com on 2019/10/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int elem;
    struct Link *next;
}Link;

Link *initLink();
void display(Link *p);

Link *insertLink(Link *p,int elem,int add)
{
    Link *temp = p;
    for(int i=1;i<add;i++){
        temp = temp->next;
        if (temp == NULL){
            printf("insert position is error");
            return p;
        }
    }
    Link *c = (Link*)malloc(sizeof(Link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;

    return p;
}

Link *delLink(Link *p,int add)
{
    Link *temp = p;
    for(int i=1;i<add;i++){
        temp = temp->next;
        if (temp == NULL){
            printf("remove positoin is error");
            return p;
        }
    }

    Link *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

int searchLink(Link *p,int elem)
{
    Link *temp = p;
    int i=1;
    while (temp->next){
        temp = temp->next;
        if (temp->elem==elem){
            return i;
        }
        i++;
    }
    return -1;
}

Link *updateLink(Link *p,int elem,int add)
{
    Link *temp = p;
    temp = temp->next;
    for (int i = 1; i <add ; ++i) {
        temp = temp->next;
    }
    temp->elem = elem;
    return p;
}
int main()
{
    printf("initLink\n");
    Link *p = initLink();
    display(p);

    printf("add elem\n");
    p = insertLink(p,100,2);
    display(p);
    printf("remove elem\n");
    p = delLink(p,2);
    display(p);
    printf("update elem\n");
    p = updateLink(p,300,2);
    display(p);
    return 0;
}

Link *initLink()
{
    Link *p = NULL;
    Link *temp = (Link*)malloc(sizeof(Link));
    temp->elem=1;
    temp->next=NULL;
    p = temp;

    for (int i = 2; i <=5 ; ++i) {

        Link *a = (Link*)malloc(sizeof(Link));
        a->elem = i;
        a->next = NULL;

        temp->next  = a;
        temp = temp->next;
    }
    return p;
}

void display(Link *p)
{
    Link *temp = p;
    while (temp){
        printf("%d\n",temp->elem);
        temp = temp->next;
    }
}