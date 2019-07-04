//
// Created by 1655664358@qq.com on 2019/7/3.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *ltree;
    struct tree *rtree;
}tree,*Bitree;

tree *initTree();
void display(Bitree tree);
void preOrderTraverse(Bitree tree);
void inOrderTraverse(Bitree tree);
void lastOrderTraverse(Bitree tree);

int front=0,near=0;

void enQueue(Bitree *a,Bitree node);
Bitree deQueue(Bitree *a);
//层序遍历  使用队列实现
void displayTree(Bitree tree);

typedef enum tag{
    ok=1,
    error
}tag;

tag test;
int main()
{
    Bitree tree = initTree();
//    printf("%d\n",tree->data);
//
//    printf("***************\n");
//    preOrderTraverse(tree);
//
//    printf("***************\n");
//    inOrderTraverse(tree);
//
//    printf("***************\n");
    lastOrderTraverse(tree);

    printf("***************\n");
    displayTree(tree);

    test = error;
    printf("test=%d\n",test);
    printf("test=%d\n", sizeof(test));
    printf("test=%d\n", sizeof(tag));
    printf("test=%d\n", sizeof(int));
    return 1;
}

/**
 * 层序遍历二叉链
 * @param tree
 */
void displayTree(Bitree tree)
{
    Bitree a[20];

    Bitree p=NULL;
    enQueue(a,tree);
    while (front<near){
        p = deQueue(a);
        display(p);
        if (p->ltree!=NULL){
            enQueue(a,p->ltree);
        }
        if (p->rtree!=NULL){
            enQueue(a,p->rtree);
        }
    }
}
tree *initTree()
{
    Bitree tree = (Bitree)malloc(sizeof(tree));

    Bitree node1 = (Bitree)malloc(sizeof(tree));
    node1->data = 1;

    Bitree node2 = (Bitree)malloc(sizeof(tree));
    node2->data = 2;

    Bitree node3 = (Bitree)malloc(sizeof(tree));
    node3->data=3;

    node1->ltree=node2;
    node1->rtree=node3;

    Bitree node4 = (Bitree)malloc(sizeof(tree));
    node4->data=4;node4->ltree=NULL;node4->rtree=NULL;
    Bitree node5 = (Bitree)malloc(sizeof(tree));
    node5->data=5;node5->ltree=NULL;node5->rtree=NULL;

    node2->ltree=node4;
    node2->rtree=node5;

    Bitree node6 = (Bitree)malloc(sizeof(tree));
    node6->data=6;node6->ltree=NULL;node6->rtree=NULL;

    Bitree node7 = (Bitree)malloc(sizeof(tree));
    node7->data=7;node7->ltree=NULL;node7->rtree=NULL;

    node3->ltree=node6;
    node3->rtree=node7;

    tree = node1;
    return tree;
}
void display(Bitree tree)
{
    if (tree){
        printf("%d\n",tree->data);
    }
}

/**
 * 前序遍历二叉链
 * @param tree
 */
void preOrderTraverse(Bitree tree)
{
    if (tree){
        display(tree);
        preOrderTraverse(tree->ltree);
        preOrderTraverse(tree->rtree);
    }
}

void inOrderTraverse(Bitree tree)
{
    if (tree){
        inOrderTraverse(tree->ltree);
        display(tree);
        inOrderTraverse(tree->rtree);
    }
}

void lastOrderTraverse(Bitree tree)
{
    if (tree){
        lastOrderTraverse(tree->ltree);
        lastOrderTraverse(tree->rtree);
        display(tree);
    }
}

void enQueue(Bitree *a,Bitree node)
{
    a[near++]=node;
}

Bitree deQueue(Bitree *a)
{
    return a[front++];
}