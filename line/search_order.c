//
// Created by 1655664358@qq.com on 2019/11/8.
//

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

void create(SSTable **st,int length)
{
    (*st) = (SSTable*)malloc(sizeof(SSTable));
    (*st)->length = length;
    (*st)->elem = (ElemType*)malloc((length+1)* sizeof(ElemType));
    
    printf("please type data\n");
    for (int i = 1; i <=length ; ++i) {
        scanf("%d",&((*st)->elem[i].key));
    }
}

int search(SSTable *st,int key)
{
    st->elem[0].key = key;
    int i = st->length;
    while (st->elem[i].key!=key){
        i--;
    }
    return i;
}
int main()
{
    SSTable *st;
    create(&st,6);

    int key;
    printf("please input your key\n");
    scanf("%d",&key);
    int location = search(st,key);
    if (location==0){
        printf("not found\n");
    }else{
        printf("find %d\n",location);
    }
    return 0;
}