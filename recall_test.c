//
// Created by 1655664358@qq.com on 2019/7/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef enum {true,false}bool;
#define ROWS 8
#define COLS 10

void makeGenerator(char maze[ROWS][COLS],int *,int *,int *,int *);

int main()
{

    char maze[ROWS][COLS];
    int xStart,yStart,x,y;
    srand(time(0));

    for(int loop=0;loop<ROWS;++loop){
        for(int loop2=0;loop2<COLS;++loop2){
            maze[loop][loop2] = '#';
        }
    }

    makeGenerator(maze,&xStart,&yStart,&x,&y);
    printf("maze entry location(%d,%d),exit location(%d,%d)\n",(xStart+1),(yStart+1),x+1,y+1);
    for(int i=0;i<ROWS;i++){
        for (int j = 0; j < COLS; ++j) {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void makeGenerator(char maze[ROWS][COLS],int *xPtr,int *yPtr,int *exitx,int *exity)
{
    int a,x,y,entry,exit;
    do{
        entry = rand()%4;
        exit = rand()%4;
    }while(entry==exit);

    if (entry==0){
        //左边
        *xPtr = 1+rand()%(ROWS-2);//0~7行随机
        *yPtr = 0;//第一列
        maze[*xPtr][*yPtr] = '0';
    }else if(entry==1){
        //上边
        *xPtr = 0;//第一行
        *yPtr = 1+rand()%(COLS-2);//0~9
        maze[*xPtr][*yPtr] = '0';
    }else if(entry==2){
        //右边
        *yPtr=COLS-1;//最后一列
        *xPtr=1+rand()%(ROWS-2);//随机行
        maze[*xPtr][*yPtr]='0';

    }else{
        //下边
        *xPtr=ROWS-1;//最后一行
        *yPtr = 1+rand()%(COLS-2);//随机列
        maze[*xPtr][*yPtr] = '0';
    }

    if (exit==0) {
        //左边的出口
        a = 1 + rand() % (ROWS - 2);
        *exitx = a;
        *exity = 0;
        maze[a][0] = '0';
    }else if(exit==1){
        //上边
        a = 1+rand()%(COLS-2);
        *exitx = 0;
        *exity = a;
        maze[0][a]='0';
    }else if(exit==2){
        //右边
        a = 1+rand()%(ROWS-2);
        *exitx=a;
        *exity=COLS-1;
        maze[a][COLS-1]='0';
    }else{
        //下边
        a = 1+rand()%(COLS-2);
        *exitx = ROWS-1;
        *exity = a;
        maze[ROWS-1][a] = '0';
    }

    for(int loop=0;loop<(ROWS-2)*(COLS-2);++loop){
        x = 1+rand()%(ROWS-2);
        y = 1+rand()%(COLS-2);
        maze[x][y] = '0';
    }
}