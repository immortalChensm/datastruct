//
// Created by 1655664358@qq.com on 2019/7/31.
//

#include <stdlib.h>
#include <stdio.h>
/**
 * 分块查找【索引
 */
struct index
{
    int key;
    int start;
}newIndex[3];

int search(int key,int a[]);
int cmp(const void *a,const void *b)
{
    //return (*(int*)a)-(*(int*)b);
    //return (*(int*)a)>(*(int*)b)?1:-1;
    //return (*(struct index*)a).key-(*(struct index*)b).key;
    //return ((struct index*)a)->key-((struct index*)b)->key;
    return ((struct index*)a)->key>((struct index*)b)->key?1:-1;
}

int main()
{
    int i,j=-1,k;
    int key;
    int a[] = {33,42,44,38,24,48, 22,12,13,8,9,20,  60,58,74,49,86,53};

    for(i=0;i<3;i++){
        newIndex[i].start = j+1;
        j+=6;
        for(k=newIndex[i].start;k<=j;k++){
            if (newIndex[i].key<a[k]){
                newIndex[i].key = a[k];
            }
        }
    }

    for(int m=0;m<3;m++){
        printf("start=%d,key=%d\n",newIndex[m].start,newIndex[m].key);
    }

//    int b[] = {43,32,76,85,99};
//    qsort(b, 5, sizeof(int),cmp);
//    for(int k=0;k< sizeof(b)/ sizeof(int);k++){
//        printf("%d\n",b[k]);
//    }
    qsort(newIndex,3, sizeof(newIndex[0]),cmp);

    for(int m=0;m<3;m++){
        printf("start=%d,key=%d\n",newIndex[m].start,newIndex[m].key);
    }

    printf("input search key:\n");
    scanf("%d",&key);

    key = search(key,a);
    if (key>=0){
        printf("ok,find elem %d\n",key);
    }else{
        printf("no find!\n");
    }
    return EXIT_SUCCESS;
}

int search(int key,int a[])
{
    int i=0,starValue;
    while(i<3&&key>newIndex[i].key){
        i++;
    }

    if (i>=3){
        return -1;
    }

    starValue = newIndex[i].start;
    while (starValue<=starValue+5&&a[starValue]!=key){
        starValue++;
    }

    if (starValue>starValue+5){
        return -1;
    }
    return starValue;

}