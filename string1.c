//
// Created by 1655664358@qq.com on 2019/6/29.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str1 = NULL;
    char *str2 = NULL;

    str1 = (char*)malloc(10* sizeof(char));
    str2 = (char*)malloc(10* sizeof(char));
    strcpy(str1,"hello");
    strcpy(str2,"nihao");

    int str1Length = strlen(str1);
    int str2Length = strlen(str2);
    printf("str1=%s\n",str1);
    if (str1Length<str1Length+str2Length){
        //这个相当重新分配了内存
        //str1 = (char*)malloc((str1Length+str2Length)* sizeof(char));
        //在原来的基础上增加内存
        str1 = realloc(str1,(str1Length+str2Length)* sizeof(char));
    }

    //i=5,i<10
    for(int i=str1Length;i<str1Length+str2Length;i++){
        str1[i] = str2[i-str1Length];//0 1 2 3 4 5
    }
    str1[str1Length+str2Length] = '\0';
    printf("str1=%s\n",str1);
    free(str1);
    free(str2);
    return 0;
}