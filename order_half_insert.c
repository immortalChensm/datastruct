//
// Created by 1655664358@qq.com on 2019/8/16.
//
/**
 * 插入折半排序
 */
#include <stdio.h>
#include <stdlib.h>
void print(int a[],int n,int i)
{
    printf("%d:",i);
    for (int j = 0; j <n ; j++) {
        printf("%d",a[j]);
    }
    printf("\n");
}

void insertOrder(int a[],int n)
{
    int j,low=0,high=0,mid=0;
    int temp=0;
    for (int i = 1; i <n ; i++) {
        low = 0;//起始位置
        high = i-1;//当前位置
        temp = a[i];//当前数值
        while (low<=high){
            mid = (low+high)/2;//起始位置-当前位置的中间
            if (a[mid]>temp){//当前位置的数据是否小于中间那个数据
                high = mid-1;//此时结束位置移动
            }else{
                low = mid+1;
            }
        }
        //经过while不断的循环，最终找到当前位置的数据应该插入哪个位置
        for (j = i; j >low ; j--) {
            a[j] = a[j-1];
        }
        a[low] = temp;
        print(a,n,i);
    }
}
int main()
{
    int a[8] = {3,1,7,5,2,4,9,6};
    insertOrder(a,8);
    return 0;
}