#include<stdio.h>
#include<limits.h>
#include<string.h>

#define N 100

int graph[N][N];
int prev[N],d[N],f[N],color[N];
int time=0;


void create_graph(int edges) {
    char u, v;
    int node_u, node_v;
    for(int i = 1; i <= edges; i++) {
        scanf(" %c %c", &u, &v); 
        node_u = u - 'a'+1 ; 
        node_v = v - 'a'+1 ;
        graph[node_u][node_v] = 1;
        //graph[node_v][node_u] = 1;   
    }
}

void dfs_visit(int u,int nodes){
    color[u]=1;// 1 represents gray color
    time+=1;
    d[u]=time;

    for(int i=1;i<=26;i++){
        if(graph[u][i]==1 && color[i]==0){
            prev[i]=u;
            dfs_visit(i,nodes);
        }
    }
    color[u] = 2;// Mark the current node as black
    time = time+1;
    f[u] = time;
}

void dfs(int start,int nodes) {

    for (int i = 1; i <=26; i++) {
        color[i] = 0; // 0 represents white color
        prev[i] = 0;
        d[i] = f[i]= INT_MAX;
    }
    time=0;

    for(int i=1;i<=nodes;i++){
        if(color[i]==0 ) dfs_visit(i,nodes);
    }
    printf("\nDiscovery time\n");
    for(int i = 1; i <= 26; i++) {
        if(d[i]!=INT_MAX)
        printf("Node %c: %d\n", i+'a'-1, d[i]);
    }
    printf("\nFinishing time\n");
    for(int i = 1; i <= 26; i++) {
        if(f[i]!=INT_MAX)
        printf("Node %c: %d\n", i+'a'-1, f[i]); 
    }
}


int main(int argc, char *argv[]) {
    int nodes, edges,beg;
    char start;
    scanf("%d %d", &nodes, &edges);

    create_graph( edges);

    printf("Enter the starting node: ");
    scanf(" %c", &start);
    beg= start - 'a' + 1; 
    dfs(beg,nodes);

    return 0;
}