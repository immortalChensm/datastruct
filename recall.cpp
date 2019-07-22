//
// Created by 1655664358@qq.com on 2019/7/22.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int set[5];
/**
 *
 * {1,2,3}
 * {1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}
 * @param i
 * @param n
 */
void powerSet(int i,int n){
    if(i>n){
        for(int j=1;j<=n;j++){
            if (set[j]==1){
                printf("%d",j);//1 2 3 / 1 2 / 1 3
            }

        }
        printf("\n");
    }else{
        set[i]=1;powerSet(i+1,n);//第一层时set[1]=1 第二层时set[2]=1 第三层时set[3]=1
        set[i]=0;powerSet(i+1,n);//第一层i=1 第二层i=2 第三层i=3  /回到第三层 set[1]=1 set[2]=1 set[3]=1 /回到第二层i=2 set[1]=1 set[2]=0 set[3]=1
    }
}
int main()
{
    int n=3;
    for(int i=0;i<5;i++){
        set[i]=0;
    }
    powerSet(1,n);

    srand(time(0));

    int entry = rand();
    printf("%d,%d\n",entry,entry%4);
    return 0;
}