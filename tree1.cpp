//
// Created by 1655664358@qq.com on 2019/7/3.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct tree{
    int data;
    struct tree *ltree;
    struct tree *rtree;
}tree;
int main()
{
    tree *bitree = (tree*)malloc(sizeof(tree));
    bitree->data=1;
    bitree->ltree=(tree*)malloc(sizeof(tree));
    bitree->ltree->data=2;

    bitree->rtree = (tree*)malloc(sizeof(tree));
    bitree->rtree->data=3;

    bitree->rtree->ltree=NULL;
    bitree->rtree->rtree=NULL;

    bitree->ltree->ltree=(tree*)malloc(sizeof(tree));
    bitree->ltree->ltree->data=4;
    bitree->ltree->ltree->ltree=NULL;
    bitree->ltree->ltree->rtree=NULL;

    printf("node1.data=%d\n",bitree->data);
    printf("node1.leftNode.data=%d\n",bitree->ltree->data);
    printf("node1.rightNode.data=%d\n",bitree->rtree->data);

    printf("node1.leftNode.leftNode.data=%d\n",bitree->ltree->ltree->data);

    return 0;
}