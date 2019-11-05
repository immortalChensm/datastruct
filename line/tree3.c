//
// Created by 1655664358@qq.com on 2019/11/5.
//

#include <stdlib.h>
#include <stdio.h>

#define MAX 30
typedef int ElemType;
typedef struct Snode
{
    ElemType data;
    int parent;

}PTNode;

typedef struct {
    PTNode node[MAX];
    int n;

}PTtree;

PTtree initPTNode(PTtree tree)
{
    int i,j;
    char ch;
    printf("node num:\n");
    scanf("%d",&(tree.n));
    for(i=0;i<=tree.n;i++){
        printf("type data and parent num:\n");
        getchar();
        scanf("%c %d",&ch,&j);
        tree.node[i].data = ch;
        tree.node[i].parent = j;
    }
    return tree;
}

void FindParent(PTtree tree)
{
    char a;
    int isfind = 0;
    printf("please type node data:\n");
    getchar();
    scanf("%c",&a);
    for(int i=0;i<tree.n;i++){
        if (tree.node[i].data == a){
            isfind = 1;
            int ad = tree.node[i].parent;
            printf("%c find result:parent=%d,value=%c position=%d\n",a,ad,tree.node[i].data,i);
            break;
        }
    }
    if (isfind==0){
        printf("can not find node\n");
    }
}

void showAllNode(PTtree tree)
{
    for (int i = 0; i <tree.n ; ++i) {

        printf("%d--%c---%d\n",i,tree.node[i].data,tree.node[i].parent);
    }
}
int main()
{
    PTtree tree;
    for (int i = 0; i <MAX ; ++i) {
        tree.node[i].data = ' ';
        tree.node[i].parent = i;
    }

    tree = initPTNode(tree);
    //FindParent(tree);
    showAllNode(tree);
    return 0;
}