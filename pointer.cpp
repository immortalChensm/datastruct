//
// Created by 1655664358@qq.com on 2019/7/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char name = 'c';
    printf("name value %c\n",name);
    printf("name address %#X\n",&name);

    printf("name value %c\n",*&name);

    printf("*******************\n");
    char *names = &name;

    printf("names value %#X\n",names);
    printf("names address %#X\n",&names);
    printf("names value1 %c\n",*names);
    printf("names value2 %c\n",**&names);//names输出的是name的地址 &names输出的是本身的地址  *&names得到是的本身地址的内容就是name的地址

    printf("*************************\n");
    char **namess = &names;
    /**
     * namess 的内容是
     */
    printf("namess value %#X\n",namess);//namess输出的内容是names的地址
    printf("namess address %#X\n",&namess);//namess输出的是本身的地址

    printf("namess value %c\n",**namess);//namess输出的内容是names本身的地址，*namess输出的是names的内容 names的内容是name本身的地址
    printf("namess value %c\n",***&namess);//&namess = 它本身的地址 *&namess取得它地址存储的内容 它的存储内容是names本身的地址   *names取得它地址上存储的内容.它的内容是name本身的地址

    printf("******************\n");
    char *address = (char*)malloc(10* sizeof(char));//address的内容是一块连续为10个char类型大小的存储空间
    printf("address value %#X\n",address);
    printf("address[0] value %#X\n",address+1);

    *(address+0)='c';
    printf("address value %c\n",*address);

    printf("*************************\n");
    char **city = (char**)malloc(10* sizeof(char));
    /**
     * city输出的内容是：10个连续的内存存储单元的地址
     * *city输出的内容是：10个连续内存存储单元的地址
     *
     */

    //city[0] = "china";
    strcpy(city[0],"china");
    printf("city[0] %s\n",city[0]);
    printf("city value %s\n",*&city[0]);

    printf("city value %c\n",city[0][0]);
    printf("city value %c\n",city[0][1]);

    printf("************************\n");


    test();

    return 0;
}

void test()
{
    char **name = (char**)malloc(10* sizeof(char***************));
    /**
     * name的内容是个10个存储单元的地址，记作A地址 A=[10]
     * *name的内容是【取A地址】的内容，A地址上的内容还是地址，记作B地址 B[10]
     * **name的内容是[取B地址上的内容】
     */
//    name[0] = (char*)malloc(10* sizeof(char));
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