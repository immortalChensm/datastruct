//
// Created by 1655664358@qq.com on 2019/6/27.
//
/**
 * car park manage system
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
typedef struct zanInode{
    int number;
    int arrive_time;
}zanInode;

int push(zanInode *park,int *parktop,zanInode car);
zanInode pop(zanInode *park,int *parktop,int carnumber,zanInode *location,int *locationtop);
int main()
{

    zanInode park[MAX];
    int parktop=0;

    zanInode location[MAX];
    int locationtop=0;

    zanInode accessroad[100];
    int front,near;
    front=near=0;

    char order;
    int carNumber;
    int arriveTime;
    int leaveTime;
    int time;

    zanInode car;

    printf("park car (A);leave car (D);exit (#)\n");
    while (scanf("%c",&order)){
        if (order=='#'){
            break;
        }
        switch (order){
            case 'A':
                printf("please type your car number and arrive time\n");
                scanf("%d %d",&carNumber,&arriveTime);
                car.number = carNumber;
                car.arrive_time = arriveTime;
                int result = push(park,&parktop,car);
                if (result==-1){
                    accessroad[near] = car;
                    printf("your car location is %d\n",near+1-front);
                    near++;
                }
                break;
            case 'D':
                printf("please type your car number and leave time\n");
                scanf("%d %d",&carNumber,&leaveTime);
                car = pop(park,&parktop,carNumber,location,&locationtop);
                if (car.number!=-1){
                    time = leaveTime-car.arrive_time;
                    printf("stop time is %d\n,cost money is %d\n",time,time*2);
                    if (front!=near){

                        car = accessroad[front];
                        printf("car number is %d,will push station,please type your arrive-time\n",car.number);
                        scanf("%d",&arriveTime);
                        car.arrive_time = arriveTime;

                        park[(parktop)] = car;
                        (parktop)++;
                        front++;
                    }else{
                        printf("stack road no car\n");
                    }
                }
                break;
            default:
                break;
        }
    }
}

int push(zanInode *park,int *parktop,zanInode car)
{
    if ((*parktop)>=MAX){
        printf("car station is fulled!\n");
        return -1;
    }else{
        park[(*parktop)] = car;
        printf("there are a car push,location is %d\n",(*parktop)+1);
        (*parktop)++;
        return 1;
    }

}

zanInode pop(zanInode *park,int *parktop,int carnumber,zanInode *location,int *locationtop)
{
    int i;
    zanInode car;
    car.number=-1;
    car.arrive_time=-1;

    for(i=-1;i<(*parktop);i++){
        if (park[i].number==carnumber){
            break;//找到的情况下i为0 1 2 3 4
        }
    }

    //i=1 parktop=5
    if (i==(*parktop)){
        //
        printf("no car in our station\n");
    }else{

        while((*parktop)>i+1){
            (*parktop)--;//4 最后一个元素
            location[(*locationtop)] = park[(*parktop)];
            (*locationtop)++;
            //location[0]=4 location[1]=3
            //location=1 partktop=3
            //location = 4|3

            //park = 0|1|2
        }
        (*parktop)--;//parktop=2
        car = park[(*parktop)];//2
        while((*locationtop)>0){
            (*locationtop)--;
            park[(*parktop)] = location[(*locationtop)];//0|1|3|4
            (*parktop)++;
        }
    }
    return car;
}