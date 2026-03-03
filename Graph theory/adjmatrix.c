#include<stdio.h>

#define N 1000

int graph[N][N];

void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;   
    }
}

void print_graph(int nodes){
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}



int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges); 

    print_graph(nodes);
    return 0;
}