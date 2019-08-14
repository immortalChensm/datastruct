//
// Created by 1655664358@qq.com on 2019/8/14.
//
#include <stdlib.h>
#include <stdio.h>
/**
 * 插入排序算法
 * @param a
 * @param n
 * @param i
 */
void print(int a[],int n,int i)
{
    printf("%d:",i);
    for (int j = 0; j <n ; j++) {
        printf("%d",a[j]);
    }
    printf("\n");
}
void insertSort(int a[],int n)
{
    for (int i = 1; i <n ; i++) {

        if (a[i]<a[i-1]){
            int j = i-1;
            int x = a[i];
            while (j>-1&&x<a[j]){//向前循环，一直找到自己的位置为止
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;
        }
        print(a,n,i);
    }
}
int main()
{
    int a[8] = {3,1,7,5,2,4,9,6};
    insertSort(a,8);
    return 0;
}
