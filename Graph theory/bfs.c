#include<stdio.h>

#define N 1000

int graph[N][N];
int visited[N];

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

void bfs(int start, int nodes) {
    int queue[N];
    int front = 0, rear = 0;

    
    visited[start] = 1;
    queue[rear++] = start;

    
    while(front != rear) {
        int current = queue[front++];

        
        printf("%d ", current);

        
        for(int i = 1; i <= nodes; i++) {
            if(graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges); 

    print_graph(nodes);

    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    bfs(start, nodes);

    return 0;
}