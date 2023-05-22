#include<stdio.h>
#include<limits.h>

#define N 1000

int graph[N][N];
int prev[N],d[N],f[N],color[N];
int time=0,cc=0;


void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;   //directed graph

    }
    
}
void dfs_visit(int u,int nodes){
    color[u]=1; //1 represents grey
    time=time+1;
    d[u]=time;
    for (int i = 1; i <= nodes; i++) {
        if (graph[u][i] == 1 && color[i] == 0) {
            color[i] = 1; // Mark the adjacent node as gray
            prev[i] = u;
            dfs_visit(i,nodes);
        }
    }
    color[u]=2; //make the current node as black
    time=time+1;
    f[u]=time;
}
void dfs(int start, int nodes) {

    for (int i = 1; i <= nodes; i++) {
        color[i] = 0; // 0 represents white color
        prev[i] = -1;
        d[i] = INT_MAX;
        f[i]=INT_MAX;
    }

    for(int i=1;i<=nodes;i++){
        if(color[i]==0) {
            dfs_visit(i,nodes);
            cc++; //counting connected components
        }
        
    }

    printf("Discovered Time:\n");
    for (int i = 1; i <= nodes; i++) {
        printf("Node %d: %d\n", i, d[i]);
    }

    printf("Finished Time:\n");
    for (int i = 1; i <= nodes; i++) {
        printf("Node %d: %d\n", i, f[i]);
    }
    
}

int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges); 

    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("DFS traversal: ");
    dfs(start, nodes);

    printf("Connected components:%d\n",cc);

    return 0;
}