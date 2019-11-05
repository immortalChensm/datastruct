//
// Created by 1655664358@qq.com on 2019/11/5.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef int ElemType;

typedef struct CTNode
{
    ElemType child;
    struct CTNode *next;
}ChildPtr;

typedef struct
{
    ElemType data;
    ChildPtr *firstchild;
}CBox;

typedef struct {
    CBox node[MAX];
    int n,r;
}CTree;

CTree initTree(CTree tree)
{
    printf("input node number:\n");
    scanf("%d",&(tree.n));
    for (int i = 0; i <tree.n ; ++i) {

        printf("please input %d node of value:\n",i+1);
        getchar();
        scanf("%c",&(tree.node[i].data));
        tree.node[i].firstchild = (ChildPtr*)malloc(sizeof(ChildPtr));
        tree.node[i].firstchild->next = NULL;

        printf("please input %c node of children number:\n",tree.node[i].data);
        int num;
        scanf("%d",&num);
        if (num!=0){
            ChildPtr *p = tree.node[i].firstchild;
            for (int j = 0; j < num; ++j) {
                ChildPtr *newElem = (ChildPtr*)malloc(sizeof(ChildPtr));
                newElem->next = NULL;
                printf("please input %d node of position:\n",j+1);
                scanf("%d",&(newElem->child));
                p->next = newElem;
                p = p->next;
            }
        }
    }
    return tree;
}

void findKids(CTree tree,char a)
{
    printf("your find value is :%c\n",a);
    int hasKid = 0;
    for (int i = 0; i <tree.n ; ++i) {
        if (tree.node[i].data == a){

            ChildPtr *p = tree.node[i].firstchild;
            while (p){
                hasKid = 1;
                printf("%c",tree.node[p->next->child].data);
                p = p->next;
            }
        }
    }
    if (hasKid==0){
        printf("this node is end node\n");
    }
}
int main()
{

    CTree tree;
    for (int i = 0; i <MAX ; ++i) {
        tree.node[i].data = ' ';
        tree.node[i].firstchild = NULL;
    }

    tree = initTree(tree);
    findKids(tree,'F');
    return 0;
}



