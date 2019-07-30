//
// Created by 1655664358@qq.com on 2019/7/30.
//
/**
 * 静态表  的顺序查找
 */
#include <stdlib.h>
#include <stdio.h>
#define KeyType int
typedef struct {
    KeyType key;
}ElemType;

typedef struct {
    ElemType *elem;
    int length;
}SSTable;

void CreateTable(SSTable **st,int length)
{
    (*st) = (SSTable*)malloc(sizeof(SSTable));
    (*st)->length=length;

    (*st)->elem = (ElemType*)malloc((length+1)* sizeof(ElemType));
    printf("input elem data:\n");
    for(int i=1;i<(*st)->length;i++){
        scanf("%d",&((*st)->elem[i].key));
    }
}
int SearchTable(SSTable *st,int key)
{
    st->elem[0].key = key;//放置监视哨
    int i = st->length;
    while (st->elem[i].key!=key){
        i--;
    }
    return i;
}
int main()
{
    SSTable *st;
    printf("input elem num:\n");
    int lenght;
    scanf("%d",&lenght);
    CreateTable(&st,lenght);

    getchar();
    printf("input search elem:\n");
    int key;
    scanf("%d",&key);
    int location = SearchTable(st,key);
    if (location==0){
        printf("no find!\n");
    }else{
        printf("find! where location is %d\n",location);
    }
    return 0;
}