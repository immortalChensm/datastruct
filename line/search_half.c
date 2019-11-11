//
// Created by 1655664358@qq.com on 2019/11/11.
//
#include <stdio.h>
#include <stdlib.h>

#define ElemKey int

typedef struct
{
    ElemKey key;
}ElemType;

typedef struct
{
    ElemType *elem;
    int length;
}SSTable;

void create(SSTable **t,int length)
{
    (*t) = (SSTable*)malloc(sizeof(SSTable));
    (*t)->elem = (ElemType*)malloc((length+1)*sizeof(ElemType));
    (*t)->length = length;

    printf("input table data\n");
    for (int i = 1; i <=length ; ++i) {
        scanf("%d",&((*t)->elem[i].key));
    }
}

int search(SSTable *t,ElemKey key)
{
    int low = 1;
    int height = t->length;
    int mid=0;
    while (low<height){
        mid = (low+height)/2;
        if (t->elem[mid].key==key){
            return mid;
        }else if (t->elem[mid].key>key){//当前值比中间值小
            height = mid-1;
        }else{
            //当前值比中间值大
            low = mid+1;
        }
    }
    return 0;
}
int main()
{
    SSTable *t;
    create(&t,6);

    for (int i = 1; i <=6 ; ++i) {
        printf("%d-",t->elem[i].key);
    }
    printf("\n");
    getchar();
    int key;
    printf("please input your data\n");
    scanf("%d",&key);
    int location = search(t,key);
    if (location==0){
        printf("can't find!\n");
    }else{
        printf("ok,find data location =%d\n",location);
    }
    return 0;
}