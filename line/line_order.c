//
// Created by 1655664358@qq.com on 2019/10/22.
//

#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

typedef struct table{
    int *head;
    int lenght;
    int size;
} table;

table initTable()
{
    table t;
    t.head = (int*)malloc(SIZE* sizeof(int));
    if (!t.head){
        printf("init error!");
        exit(1);
    }
    t.lenght=0;
    t.size=SIZE;
    return t;
}

table addTable(table t,int elem,int add)
{
    if (add>t.lenght||add<1){
        printf("insert position is error\n");
        return t;
    }
    if (t.lenght>=t.size){
        t.head = (int*)realloc(t.head,(t.size+1)* sizeof(int));
        if (!t.head){
            printf("realloc error");
            return t;
        }
    }
    for(int i=t.lenght;i>=add;i--){
        t.head[i+1] = t.head[i];
    }
    t.head[add] = elem;
    t.lenght++;
    return t;
}

table delTable(table t,int add)
{
    if (add>t.lenght||add<1){
        printf("remove position is error\n");
        return t;
    }

    for(int i=add;i<t.lenght;i++){
        t.head[i-1] = t.head[i];
    }
    t.lenght--;
    return t;
}

int searchTable(table t,int elem)
{
    for (int i = 0; i <t.lenght ; ++i) {
        if (t.head[i] == elem){
            return i+1;
        }
    }
    return -1;
}

table updateTable(table t,int elem,int new)
{
    int add = searchTable(t,elem);
    t.head[add-1] = new;
    return t;
}
void display(table t)
{
    for (int i = 0; i < t.lenght; ++i) {
        printf("%d\n",t.head[i]);
    }
}
int main()
{

    table t = initTable();
    for (int i = 1; i <=SIZE; ++i) {
        t.head[i-1] = i;
        t.lenght++;
    }

    printf("now data is:\n");
    display(t);

    printf("add elem********************\n");
    t = addTable(t,6,2);
    display(t);

    printf("remove elem 6***************\n");
    t = delTable(t,3);
    display(t);

    printf("update elem 2 into 20********");
    t = updateTable(t,2,20);
    display(t);

    return 0;
}