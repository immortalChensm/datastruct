//
// Created by 1655664358@qq.com on 2019/8/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t now;
    time(&now);
    printf("now time %d\n",now);

    struct tm *now_tm;
    now_tm = localtime(&now);
    printf("%d-%d-%d %d:%d:%d\n",1900+now_tm->tm_year,now_tm->tm_mon+1,now_tm->tm_mday,now_tm->tm_hour,now_tm->tm_min,now_tm->tm_sec);


    return 0;
}