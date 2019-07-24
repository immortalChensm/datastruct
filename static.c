//
// Created by 1655664358@qq.com on 2019/7/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {true,false}bool;
void test()
{
    static int n=0;
    static bool flag=false;
    n++;
    printf("called %d times\n",n);
    printf("flag %d \n",flag);
    if (n==3){
        flag=true;
    }
}
int main()
{
    int n=0;
    for(int i=0;i<5;i++){
        test();
    }
    printf("n=%d\n",n);
    //printf("flag=%d\b",flag);
    return 0;
}