//
// Created by 1655664358@qq.com on 2019/6/28.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef int Status;
#define OK 1
#define ERROR 0
/**
 * 串
 * 空串
 * 空格串
 * 主串，子串
 * 室长顺序存储 静态数组
 * 动态顺序存储 动态数组
 * 链式存储
 * @return
 */
 Status insertStr(char *str,int location,char data);
 Status removeStr(char *str,int location,char *data);
 Status strPos(char *str,char data);
 Status strCount(char *str,char data);
 char *strReverse(char *str);

int main()
{
    char str[100] = "hello,nihao";
    str[0]= 'k';

    printf("%s\n",str);
    printf("%c\n",*str);
    insertStr(str,3,'m');
    printf("%s\n",str);
    char data;
    removeStr(str,3,&data);
    printf("%c\n",data);
    printf("%s\n",str);

    printf("***************\n");
    int pos = strPos(str,'o');
    printf("%d\n",pos);
    printf("******************\n");
    int count = strCount(str,'o');
    printf("%o=d\n",count);
    printf("revese test \n");
    char *temp = strReverse(str);
    printf("temp=%s\n",temp);
    return 0;
}

Status insertStr(char *str,int location,char data)
{
    if (location<1||location>strlen(str)){
        return ERROR;
    }
    //10>5
    for(int i=strlen(str)-1;i>location;i--){
        str[i+1] = str[i];//
    }
    str[location-1] = data;
    return OK;
}

Status removeStr(char *str,int location,char *data)
{
    if (strlen(str)==0){
        return ERROR;
    }
    *data = str[location-1];
    for(int i=location;i<strlen(str);i++){
        str[i-1] = str[i];
    }

    return OK;
}

Status strPos(char *str,char data)
{
    for(int i=0;i<strlen(str);i++){
        if (str[i] == data){
            return i;
        }
    }
    return -1;
}

Status strCount(char *str,char data)
{
    int count=0;
    for(int i=0;i<strlen(str);i++){
        if (str[i] == data){
            count++;
        }
    }
    return count;
}

char *strReverse(char *str)
{
    char *temp = (char*)malloc(strlen(str)*sizeof(char));
    int i,j;
    j=0;
    for(i=strlen(str)-1;i>0;i--,j++){
        temp[j] = str[i];
    }
    return temp;
}