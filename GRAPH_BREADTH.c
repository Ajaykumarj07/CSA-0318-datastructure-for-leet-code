#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int visited[MAX_VERTICES] = {0}; 
void create_graph(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    int i, j;

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int start_vertex) {
    int queue[MAX_VERTICES], front = 0, rear = -1;

    visited[start_vertex] = 1;
    queue[++rear] = start_vertex;
    
    while (front <= rear) {
        int current_vertex = queue[front++];
        printf("%d ", current_vertex);

        for (int i = 0; i < num_vertices; i++) {
            if (graph[current_vertex][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1; 
            }
        }
    }
}

int main() {
    int num_vertices, start_vertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    create_graph(graph, num_vertices);

    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    printf("BFS traversal: ");
    bfs(graph, num_vertices, start_vertex);

    return 0;
}
