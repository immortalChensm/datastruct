//
// Created by 1655664358@qq.com on 2019/7/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERtEX_NUM 20 //顶点个数
#define VRType int  //顶点间关系数据类型
#define InfoType char //弧边额外信息
#define VertexType int //顶点数据类型

typedef enum {DG,DN,UDG,UDN}GraphKind;//图类型

//顶点关系结构体   无权图 1和0表示有无关系  有权图即网即权值
typedef struct {
    VRType adj;
    InfoType *info;

}ArcCell,AdjMatric[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

//图结构体
typedef struct {
    VertexType vers[MAX_VERtEX_NUM];//顶点值数组
    AdjMatric arcs;//顶点关系数组
    int vexnum,arcnum;//顶点数量和弧或边数量
    GraphKind kind;//图各类  图和网  有向图，无向图，有向网，无向网
}MGraph;

int LocateVer(MGraph *G,VertexType v)
{
    int i=0;
    for(;i<G->vexnum;i++){
        if (G->vers[i]==v){
            break;
        }
    }
    if (i>G->vexnum){
        printf("no vertex\n");
        return -1;
    }
    return i;
}
/**
 * 有向图
 * @param G
 */
void CreateDG(MGraph *G)
{
    printf("input vexnum and arcnum:\n");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    for(int i=0;i<G->vexnum;i++){
        printf("input vertex data:\n");
        scanf("%d",&(G->vers[i]));
    }

    for(int i=0;i<G->vexnum;i++){
        for(int j=0;j<G->vexnum;j++){
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }

    for(int i=0;i<G->arcnum;i++){
        int v1,v2;
        printf("input vertex x data ,vertex y data:\n");
        scanf("%d %d",&v1,&v2);
        int n = LocateVer(G,v1);
        int m = LocateVer(G,v2);
        if (n==-1||m==-1){
            printf("no this vertex\n");
            return ;
        }
        G->arcs[n][m].adj=1;
    }
}

void CreateGraph(MGraph *G){

    printf("input graph kind:\n");
    scanf("%d",&(G->kind));
    switch (G->kind){
        case DG:
            CreateDG(G);
            break;
        case DN:
            break;
        case UDG:
            break;
        case UDN:
            break;
    }
}

void PrintGraph(MGraph G)
{
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            printf("%d",G.arcs[i][j].adj);
        }
        printf("\n");
    }
}
int main()
{
    MGraph G;
    CreateGraph(&G);
    PrintGraph(G);
    return 0;
}