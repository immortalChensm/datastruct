//
// Created by 1655664358@qq.com on 2019/7/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name = 'c';
    printf("name value %c\n",name);
    printf("name address %#X\n",&name);

    printf("name value %c\n",*&name);

    printf("*******************\n");
    char *names = &name;

    printf("names value %#X\n",names);
    printf("names address %#X\n",&names);
    printf("names value1 %c\n",*names);
    printf("names value2 %c\n",**&names);//names输出的是name的地址 &names输出的是本身的地址  *&names得到是的本身地址的内容就是name的地址

    printf("*************************\n");
    char **namess = &names;
    /**
     * namess 的内容是
     */
     printf("namess value %#X\n",namess);//namess输出的内容是names的地址
     printf("namess address %#X\n",&namess);//namess输出的是本身的地址

     printf("namess value %c\n",**namess);//namess输出的内容是names本身的地址，*namess输出的是names的内容 names的内容是name本身的地址
     printf("namess value %c\n",***&namess);//&namess = 它本身的地址 *&namess取得它地址存储的内容 它的存储内容是names本身的地址   *names取得它地址上存储的内容.它的内容是name本身的地址

     printf("******************\n");
     char *address = (char*)malloc(10* sizeof(char));//address的内容是一块连续为10个char类型大小的存储空间
     printf("address value %#X\n",address);
     printf("address[0] value %#X\n",address+1);

     *(address+0)='c';
     printf("address value %c\n",*address);

     printf("*************************\n");
     char **city = (char**)malloc(10* sizeof(char));
     /**
      * city输出的内容是：10个连续的内存存储单元的地址
      * *city输出的内容是：10个连续内存存储单元的地址
      *
      */

     //city[0] = "china";
     strcpy(city[0],"china");
     printf("city[0] %s\n",city[0]);
     printf("city value %s\n",*&city[0]);

     printf("city value %c\n",city[0][0]);
     printf("city value %c\n",city[0][1]);

     printf("************************");

    return 0;
}