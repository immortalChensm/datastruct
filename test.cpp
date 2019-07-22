//
// Created by 1655664358@qq.com on 2019/7/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
void handler(int sig)
{
    printf("test");
}
int main(int argc,char *argv[])
{
    int a = 10;
    printf("a=%d\n",a);
}