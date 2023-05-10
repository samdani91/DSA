#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;

void creat_graph(int nodes,int edges){
    int u,v;
    for(int i=1;i<=edges;i++){
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;   

    }
    
}

int main()
{
    int nodes,edges;
    creat_graph(nodes,edges);

    

    return 0;
}