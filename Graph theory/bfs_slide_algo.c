#include<stdio.h>
#include<limits.h>
#include<string.h>

#define N 1000

int graph[N][N];
int prev[N],d[N],color[N];


void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;   

    }
    
}

void bfs(int start, int nodes) {
    int queue[N];
    int front = 0, rear = 0;

    for (int i = 1; i <= nodes; i++) {
        color[i] = 0; // 0 represents white color
        prev[i] = 0;
        d[i] = INT_MAX;
    }

    d[start] = 0;
    color[start] = 1; // 1 represents gray color

    queue[rear++] = start;

    while (front != rear) {
        int u = queue[front++];
        for (int i = 1; i <= nodes; i++) {
            if (graph[u][i] == 1 && color[i] == 0) {
                color[i] = 1; // Mark the adjacent node as gray
                d[i] = d[u] + 1;
                prev[i] = u;
                queue[rear++] = i;
            }
        }
        color[u] = 2; // Mark the current node as black
    }
    printf("\nShortest distances from node %d:\n", start);
    for(int i = 1; i <= nodes; i++) {
        printf("Node %d: %d\n", i, d[i]);
    }
}

int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges); 

    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    bfs(start, nodes);

    return 0;
}