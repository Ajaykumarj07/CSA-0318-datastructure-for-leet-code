#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES] = {0};  // Track visited vertices

// Create graph using adjacency matrix
void create_graph(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    printf("Enter adjacency matrix (1 for connected vertices, 0 otherwise):\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// DFS function using a stack for exploration
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int start_vertex) {
    int stack[MAX_VERTICES], top = -1;

    stack[++top] = start_vertex;  // Push starting vertex onto stack
    visited[start_vertex] = 1;   // Mark it as visited

    while (top != -1) {
        int current_vertex = stack[top--];  // Pop a vertex from the stack
        printf("%d ", current_vertex);

        // Explore its unvisited neighbors
        for (int i = 0; i < num_vertices; i++) {
            if (graph[current_vertex][i] == 1 && visited[i] == 0) {
                stack[++top] = i;  // Push unvisited neighbor onto stack
                visited[i] = 1;   // Mark it as visited
            }
        }
    }
}

int main() {
    int num_vertices, start_vertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    create_graph(graph, num_vertices);

    printf("Enter starting vertex: ");
    scanf("%d", &start_vertex);

    printf("DFS traversal: ");
    dfs(graph, num_vertices, start_vertex);

    return 0;
}

