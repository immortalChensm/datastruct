//
// Created by 1655664358@qq.com on 2019/6/25.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct gambler{
    int number;
}gambler;

int main()
{
    int n;
    int round=1;
    int location=1;
    int shotNum;
    gambler gamblers[100];
    //srand((int)time(0));
    printf("please type gambler number (<100>):\n");
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){
        gamblers[i].number = i;
    }

//    for(j=0;j<=n;j++){
//        printf("%d\n",gamblers[j].number);
//    }
    while(n!=1){
        printf("round %d,number %d start\n",round,gamblers[location].number);
        shotNum = rand()%6+1;//产生1~6的随机数字
        //printf("%d\n",shotNum);
        printf("will to fire a gun at %d\n",shotNum);
        for(i=location;i<location+shotNum;i++);
        i = i%n;
        if (i==1||i==0){
            i=n+1;
        }
        //printf("i=%d\n",i);
        printf("number is %d will die\n",gamblers[i-1].number);

        for(j=n-1;j+1<=n;j++){
            gamblers[j]=gamblers[j+1];
        }
        n--;

    }
    return 0;
}