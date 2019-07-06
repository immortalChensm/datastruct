//
// Created by 1655664358@qq.com on 2019/7/5.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef char ElemType;
typedef struct pNode{
    ElemType data;
    int parent;
}pNode;

typedef struct PTree{
    pNode node[MAX_SIZE];
    int n;
}PTree;

PTree initPTree(PTree tree);
void FindTreeParent(PTree tree);
/**
 * 双亲表示
 * R -1
A 0
B 0
C 0
D 1
E 1
F 3
G 6
H 6
K 6
 * @return
 */
int main(){
    PTree tree;
    for(int i=0;i<MAX_SIZE;i++){
        tree.node[i].data = ' ';
        tree.node[i].parent = 0;
    }

    tree = initPTree(tree);
    printf("parent is \n");
    printf("%c\n",tree.node[0].data);

    printf("*****************************");
    FindTreeParent(tree);
    return 0;
}

/**
 * 树初始化
 * @param tree
 * @return
 */
PTree initPTree(PTree tree)
{
    int i,j;
    char ch;
    printf("please type tree number\n");
    scanf("%d",&tree.n);
    printf("please type tree data and tree parent num\n");
    for(i=0;i<tree.n;i++){

        getchar();
        scanf("%c %d",&ch,&j);
        tree.node[i].data = ch;
        tree.node[i].parent = j;
    }
    return tree;
}

/**
 * 查找双亲结点
 * @param tree
 */
void FindTreeParent(PTree tree)
{
    char a;
    int isfind=0;
    printf("please type your wann find parent\n");
    getchar();
    scanf("%c",&a);
    for(int i=0;i<tree.n;i++){
        if (tree.node[i].data == a){

            isfind = 1;
            int parent = tree.node[i].parent;

            printf("find data is %c,parent is %d\n",tree.node[parent].data,parent);

            //查到父结点，就应该能查找到子结点
            for(int j=0;j<tree.n;j++){
                if (tree.node[j].parent==parent){
                    printf("my son is %c\n",tree.node[j].data);
                }
            }
            break;
        }
    }
    if (isfind==0){
        printf("no parent!\n");
    }
}