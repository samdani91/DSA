#include<stdio.h>
#include<limits.h>
#include<string.h>

void creat_graph(int nodes,int edges);
void transpose_graph(int nodes);
void print_graph(int nodes);
int maximum();
void dfs_visit(int u,int nodes);
void dfs(int nodes);

#define N 1000

int graph[N][N],transpose[N][N];
int prev[N],d[N],f[N],color[N];
int time=0,cc=0;


int main(int argc,char *argv[])
{
    int nodes,edges,start;
    scanf("%d %d",&nodes,&edges);
    creat_graph(nodes,edges);
    transpose_graph(nodes);
    //print_graph(nodes); 
    dfs(nodes);
    printf("\nFinishing time\n");
    for(int i = 1; i <= nodes; i++) {
        printf("Node %d: %d\n", i, f[i]);
    }

    

    printf("Connected components:%d\n",cc);

    return 0;
}

void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v]=1;  

    }
    
}
void transpose_graph(int nodes){
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            if(graph[i][j]==1){
                transpose[j][i]=graph[i][j];
            }
        }
    }
}
void print_graph(int nodes){
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }
}
int maximum(int nodes){
    int index,max=0;
    for(int i=1;i<=nodes;i++){
        if(f[i]>max){
            max=f[i];
            index=i;
        }
    }
    f[index]=0;
    return index;
    
}
void dfs(int nodes) {

    for (int i = 1; i <= nodes; i++) {
        color[i] = 0; // 0 represents white color
        prev[i] = 0;
        d[i] = f[i]= INT_MAX;
    }
    time=0;

    for(int i=1;i<=nodes;i++){
        int index=maximum(nodes);
        if(color[index]==0) {
            dfs_visit(index,nodes);
            cc++;
        }
    }
}

void dfs_visit(int u,int nodes){
    color[u]=1;// 1 represents gray color
    time+=1;
    d[u]=time;

    for(int i=u;i<=nodes;i++){
        if(transpose[u][i]==1 && color[i]==0){
            color[i]=1;
            prev[i]=u;
            dfs_visit(i,nodes);
        }
    }
    color[u] = 2;// Mark the current node as black
    time = time+1;
    f[u] = time;
    
}
