//
// Created by 1655664358@qq.com on 2019/7/6.
//
/**
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 20
typedef int TElemType;

typedef struct CTNode{
    TElemType child;
    struct CTNode *next;
}ChildPtr;

typedef struct CTBox
{
    char data;
    ChildPtr *firstChild;
}CTBox;

typedef struct CTree
{
    CTBox node[MAX_SIZE];
    int n,r;
}CTree;

CTree initTree(CTree tree);
void FindKids(CTree tree,char a);
void displayNode(CTree tree);

/**
 * 树结构孩子表示法
0 R -1 3个孩子 构成孩子链表
1 A 0  2个孩子
2 B 0  0
3 C 0  1个孩子
4 D 1  0
5 E 1  0
6 F 3  3个孩子 构成孩子链表
7 G 6  0
8 H 6  0
9 K 6  0
 * @return
 */
int main()
{
    CTree tree;
    for(int i=0;i<MAX_SIZE;i++){
        tree.node[i].data=' ';
        tree.node[i].firstChild = NULL;
    }

   // tree = initTree(tree);
    //printf("%c\n",tree.node[0].data);
    //printf("**************************");
    //displayNode(tree);
    //FindKids(tree,'F');
    char *path = getenv("PATH");
    printf("path=%s\n",path);
    return 0;
}

/**
 * 普通树初始化
 * @param tree
 * @return
 */
CTree initTree(CTree tree)
{
    printf("please type parent number \n");
    scanf("%d",&tree.n);
    for(int i=0;i<tree.n;i++){
        printf("please type parent data\n");
        getchar();
        scanf("%c",&tree.node[i].data);

        tree.node[i].firstChild = (ChildPtr*)malloc(sizeof(ChildPtr));
        tree.node[i].firstChild->next=NULL;

        printf("please type child number\n");
        getchar();
        int ChildNum=0;
        scanf("%d",&ChildNum);


        if (ChildNum!=0){

            ChildPtr *p = tree.node[i].firstChild;

            for(int j=0;j<ChildNum;j++){
                printf("please type child data\n");
                ChildPtr *child = (ChildPtr*)malloc(sizeof(ChildPtr));
                getchar();
                scanf("%d",&child->child);
                child->next=NULL;

                p->next = child;
                p = child;

            }
        }


    }
    return tree;
}

/**
 * 查找树
 * @param tree
 * @param a
 */
void FindKids(CTree tree,char a)
{
    int hasKids=0;
    for(int i=0;i<tree.n;i++){
        if(tree.node[i].data==a){
            ChildPtr *p = tree.node[i].firstChild->next;
            while (p){
                hasKids = 1;
                printf("%c",tree.node[p->child].data);
                p = p->next;
            }
        }
    }
    if (hasKids==0){
        printf("this node is end \n");
    }
}

/**
 * 显示树
 * @param tree
 */
void displayNode(CTree tree)
{
    for(int i=0;i<tree.n;i++){
        printf("%c\n",tree.node[i].data);
        ChildPtr *child = tree.node[i].firstChild->next;
        while (child){
            printf("%10c\n",tree.node[child->child].data);
            child = child->next;
        }
    }
}