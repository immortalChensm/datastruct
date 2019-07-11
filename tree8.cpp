//
// Created by 1655664358@qq.com on 2019/7/11.
//

#include <stdlib.h>
#include <stdio.h>
/**
 * 哈夫曼树算法实现
 */
typedef struct {

    int weight;
    int parent,left,right;

}HTNode,*HuffmanTree;

HuffmanTree createHuffmanTree(HuffmanTree tree,int *w,int n);
void Select(HuffmanTree tree,int end,int *s1,int *s2);
void displayHuffmanTree(HuffmanTree tree);

int main()
{
    HuffmanTree tree=NULL;
    int w[5] = {2,8,7,6,5};
    int n=5;
    tree = createHuffmanTree(tree,w,n);
    printf("*****************\n");
//    printf("%d\n",tree[1].weight);
    displayHuffmanTree(tree);
    return 0;

}

void displayHuffmanTree(HuffmanTree tree)
{
    for(int i=1;i<10;i++){
        printf("tree[%d].weight=%d,tree[%d].parent=%d,tree[%d].left=%d,tree[%d].right=%d\n",i,tree[i].weight,i,tree[i].parent,i,tree[i].left,i,tree[i].right);
    }
}


/**
 * 构建一个哈夫曼树【赫夫曼树，最优二叉树】
 * @param tree
 * @param w
 * @param n
 */
HuffmanTree createHuffmanTree(HuffmanTree tree,int *w,int n)
{
    if (n<1)return tree;
    int m = 2*n-1;
    tree = (HuffmanTree)malloc((m+1)*sizeof(HTNode));

    HuffmanTree p = tree;
    int i=1;
    for(i;i<=n;i++){
        (p+i)->parent=0;
        (p+i)->left=0;
        (p+i)->right=0;

        (p+i)->weight=*(w+i-1);//是个数组
    }

    for(int i=n+1;i<=m;i++){
        (p+i)->weight=0;
        (p+i)->parent=0;
        (p+i)->left=0;
        (p+i)->right=0;
    }

    for(int i=n+1;i<=m;i++){
        int s1,s2;
        Select(tree,i-1,&s1,&s2);
        tree[s1].parent=tree[s2].parent=i;
        tree[i].right=s2;
        tree[i].left=s1;
        tree[i].weight=tree[s1].weight+tree[s2].weight;
    }

    return tree;
}

/**
 * 从数组中查找2个最小的权重值
 *
 * @param tree
 * @param end
 * @param s1
 * @param s2
 */
void Select(HuffmanTree tree,int end,int *s1,int *s2)
{
    int min1,min2;
    int i=1;

    //从数组中找到parent=0的结点
    while(tree[i].parent!=0&&i<=end){
        i++;
    }

    min1 = tree[i].weight;//得到parent=0的结点权重值
    *s1 = i;

    i++;//准备获取第二个数
    while(tree[i].parent!=0&&i<=end){
        i++;
    }

    //后面的权重值比第一个小的话
    if (tree[i].weight<min1){
        min2=min1;
        *s2=*s1;

        min1=tree[i].weight;
        *s1=i;
    }else{
        min2=tree[i].weight;
        *s2=i;
    }


    //以上得到了min1,min2的值
    for(int j=i+1;j<=end;j++){
        //继续向后查找parent=0的结点
        if (tree[j].parent!=0){
            continue;
        }
        //继续拿当前的权重值和第一个获取的权重比较
        if (tree[j].weight<min1){
            min2=min1;//如果当前结点的权重小于第一个数，则进行交换
            *s2=*s1;

            min1=tree[i].weight;
            *s1=j;
        }else if(tree[j].weight>=min1&&tree[j].weight<min2){
            min2 = tree[j].weight;
            *s2=j;
        }
    }
}