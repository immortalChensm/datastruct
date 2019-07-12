//
// Created by 1655664358@qq.com on 2019/7/11.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * 哈夫曼树算法实现
 */
typedef struct {

    int weight;
    int parent,left,right;

}HTNode,*HuffmanTree;

typedef struct {
    int data;
    int parent;
}Test,*T;

typedef char **HuffCode;

HuffmanTree createHuffmanTree(HuffmanTree tree,int *w,int n);
void Select(HuffmanTree tree,int end,int *s1,int *s2);
void displayHuffmanTree(HuffmanTree tree);

Test *findMinValue(Test *test,int *weight,int location);
void HuffmanCodeing(HuffmanTree tree,HuffCode *table,int n);
void displayHuffmanCode(HuffCode *table,int *weight,int n);

void test();
void testMin();
int main()
{
    HuffmanTree tree=NULL;
    int w[5] = {2,8,7,6,5};
    int n=5;
    HuffCode table;
    tree = createHuffmanTree(tree,w,n);

   // HuffmanCodeing(tree,&table,n);
   // displayHuffmanCode(&table,w,n);
//    printf("*****************\n");
////    printf("%d\n",tree[1].weight);
//    displayHuffmanTree(tree);
//    printf("*****************\n");
//    testMin();

//    displayHuffmanTree(tree);
//
//    printf("******************************\n");
//
//    char **test = (char**)malloc(10*sizeof(char));
//    strcpy(&(*test)[0],"chinese");
//    printf("%s\n",&(*test)[0]);

    test();
    return 0;

}

void test()
{
    char **name = (char**)malloc(10* sizeof(char***************));
    name[0] = (char*)malloc(10* sizeof(char));
    strcpy(name[0],"china");
    printf("%s\n",name[0]);
}
void testMin()
{
    T test = (T)malloc(10* sizeof(Test));
    int weight[]={8,4,7,3,2};
    for(int i=1;i<=5;i++){
        (test+i)->parent=0;
        (test+i)->data=*(weight+i-1);
    }
    for(int i=6;i<=10;i++){
        (test+i)->parent=0;
        (test+i)->data=0;
    }
    for(int i=1;i<=5;i++){
        test = findMinValue(test,weight,i);
    }
}
Test *findMinValue(Test *test,int *weight,int location)
{



    //从数组中查找2个最小的结点出来并显示
    int min1,min2;
    int s1,s2;
    int k=1;
    while(test[k].parent!=0&&k<=5){
        k++;
    }

    min1 = test[k].data;
    s1=k;
    k++;

    while (test[k].parent!=0&&k<=5){
        k++;
    }

    if (test[k].data<min1){
        min2=min1;
        s2=s1;
        min1=test[k].data;
        s1=k;
    }else{
        min2=test[k].data;
        s2=k;
    }


        for(int j=k+1;j<=5;j++){
            if (test[j].parent!=0){
                continue;
            }
            if (test[j].data<min1){
                min2=min1;
                s2=s1;
                min1=test[j].data;
                s1=j;
            }else if(test[j].data>=min1&&test[j].data<min2){
                min2=test[j].data;
                s2=k;
            }

        }
        printf("now min1 value is %d,min2 is %d\n",min1,min2);
        printf("s1=%d,s2=%d,location=%d\n",s1,s2,location);
        test[s1].parent=location;
        test[s2].parent=location;

    return test;
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

void HuffmanCodeing(HuffmanTree tree,HuffCode *table,int n)
{
    *table = (HuffCode)malloc((n+1)* sizeof(char*));

    char *cd = (char*)malloc(n* sizeof(char));
    cd[n-1]='\0';


    for(int i=1;i<=n;i++){

        int start=n-1;
        int c = i;
        int j = tree[i].parent;
        while (j!=0){
            if (tree[j].left==c){
                cd[--start]='0';
            }else{
                cd[--start]='1';
            }

            c = j;
            j = tree[j].parent;
        }
//        printf("%s\n",&cd[start]);
        //printf("%s\n",cd+start);
        (*table)[i]=(char*)malloc((n)*sizeof(char));

        strcpy((*table)[i],&cd[start]);
            //strcpy((*table)[i],cd+start);
        //printf("c");
    }

    free(cd);

}

void displayHuffmanCode(HuffCode *table,int *weight,int n)
{
    printf("print huffman code\n");
    for(int i=1;i<=n;i++){
        printf("w[%d]=%d,code=%s\n",i,weight[i-1],(*table)[i]);
    }
}