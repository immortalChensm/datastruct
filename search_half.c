//
// Created by 1655664358@qq.com on 2019/7/30.
//

/**
 * 折半查找算法【二分查找】
 * 1 2 3 4 5 6 7 8 9 10
 * low=1 height=10
 * mid = 5  //11/2=5
 *
 * search=6
 *
 * height=10
 * low=6  //16/2=8
 * mid = 8
 *
 * 1 2 3 4 5 6 7 8 9 10
 *           low     height
 *               mid
 *
 *              mid
 * 1 2 3 4 5 6 7 8 9 10
 *           low   height
 *
 *           15/2=7
 *
 * 1 2 3 4 5 6 7 8 9 10
 *           low height
 *           mid=14/2=7
 * 1 2 3 4 5 6 7 8 9 10
 *           low=6 height=7
 *           mid = 13/2=6
 */
#include <stdio.h>
#include <stdlib.h>

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
    (*st)->elem = (ElemType*)malloc((length+1)* sizeof(ElemType));
    (*st)->length = length;

    for(int i=1;i<(*st)->length;i++){
        scanf("%d",&((*st)->elem[i].key));
    }
}

int SearchHalf(SSTable *st,int key)
{
    int low = 1;
    int height = st->length;
    int mid;
    while (low<=height){
        mid = (low+height)/2;
        if (st->elem[mid].key==key){
            return mid;
        }
        else if (st->elem[mid].key>key){
            height = mid-1;
        }else{
            low = mid+1;
        }
    }
    return 0;
}
int main()
{
    SSTable *st;
    int length;
    printf("input table length:\n");
    scanf("%d",&length);

    CreateTable(&st,length);
    printf("input search elem:\n");
    int key;
    scanf("%d",&key);
    int location = SearchHalf(st,key);
    if (location==0){
        printf("no find\n");
    }else{
        printf("find elem where location is %d\n",location);
    }

    return 0;
}