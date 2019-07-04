//
// Created by 1655664358@qq.com on 2019/7/4.
//
#include <stdlib.h>
#include <stdio.h>
#define TElemType int
typedef enum pointerTag{
    Link,
    Thread
}pointerTag;

typedef struct Bitree{
    TElemType data;
    struct Bitree *ltree,*rtree;
    pointerTag LTag,RTag;
}BiNoe,*Bitree;


int main()
{

}