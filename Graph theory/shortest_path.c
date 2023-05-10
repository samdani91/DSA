#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define N 1000

int graph[N][N];
int distance[N];
bool visited[N];

void create_graph(int nodes, int edges) {
    int u, v;
    for(int i = 1; i <= edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;   
    }
}

void bfs(int start, int nodes) {
    int queue[N];
    int front = 0, rear = 0;

    // Initialize distance of all nodes to be infinity
    for(int i = 1; i <= nodes; i++) {
        distance[i] = INT_MAX;
    }

    // Mark start node as visited and enqueue it with distance 0
    visited[start] = true;
    distance[start] = 0;
    queue[rear++] = start;

    // Traverse the graph
    while(front != rear) {
        int current = queue[front++];

        // Enqueue all unvisited neighbors of current node
        for(int i = 1; i <= nodes; i++) {
            if(graph[current][i] == 1 && visited[i] == false) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\nShortest distances from node %d:\n", start);
    for(int i = 1; i <= nodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }
}

int main(int argc, char *argv[]) {
    int nodes, edges, start;
    scanf("%d %d", &nodes, &edges);

    create_graph(nodes, edges);

    // Perform BFS to find shortest path
    printf("Enter the starting node: ");
    scanf("%d", &start);
    bfs(start, nodes);

    return 0;
}
