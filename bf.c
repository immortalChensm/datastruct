//
// Created by 1655664358@qq.com on 2019/6/29.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int match(char *a,char *b);

int main()
{

    char *a = "abcdefabdg";
    char *b = "abd";
    int num = match(a,b);
    printf("num=%d\n",num);

    int *p = 12;
    printf("%d\n",p);
    return 0;
}

/**
 * BF模式匹配算法
 * @param a
 * @param b
 * @return
 */
int match(char *a,char *b)
{
    //a=abcdefabdg
    //  0123456789
    //b=abd
    //  012
    int i,j;
    i=j=0;
    while (i<strlen(a)&&j<strlen(b)){
        if (a[i]==b[j]){ //2=c==0=a    [3=d]==[0=a] [4=e]==[0=a]
            j++;//2
            i++;//2
        }else{
            j=0;
            //i=i-j+1;//2-1+1=2  2-0+1=3  3-0+1=4  4-0+1=5
            i=i+1;
        }
    }
    if (j==strlen(b)){
        return i-strlen(b)+1;
    }
    return -1;
}