#include<stdio.h>

#define N 1000

int graph[N][N];
int visited[N];
int outdeg[N],indeg[N];

void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;  

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

int indegree(int nodes){

    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            if(graph[j][i]==1){
                indeg[i] += graph[j][i];
            }
        }
    }
}

int outdegree(int nodes){

    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            if(graph[i][j]==1){
                outdeg[i] += graph[i][j];
            }
        }
    }

}

int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges); 

    //print_graph(nodes);
    indegree(nodes);
    outdegree(nodes);

    printf("Indegree of each node:\n");
    for(int i=1;i<=nodes;i++){
        printf("Node %d: %d\n",i,indeg[i]);
    }
    printf("Outdegree of each node:\n");
    for(int i=1;i<=nodes;i++){
        printf("Node %d: %d\n",i,outdeg[i]);
    }

    return 0;
}
//indegree -> 2 1 3 1 1 -> sum of column
//outdegree -> 3 1 1 1 2 -> sum of rows