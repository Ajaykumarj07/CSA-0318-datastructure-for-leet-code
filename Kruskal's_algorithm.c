#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Function to find the set of an element i
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// Function to do union of two sets of x and y
void union1(int parent[], int x, int y) {
    parent[x] = y;
}

// Function to implement Kruskal's MST algorithm
void kruskalMST(struct Edge edges[], int num_edges, int num_vertices) {
    int parent[num_vertices];
    int edge_count = 0, i = 0;

    // Initialize all sets as single element sets
    for (int v = 0; v < num_vertices; v++) {
        parent[v] = -1;
    }

    // Sort edges in increasing order of their weight
    qsort(edges, num_edges, sizeof(struct Edge), );

    // Pick edges one by one
    while (edge_count < num_vertices - 1 && i < num_edges) {
        struct Edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        // If including this edge doesn't cause a cycle, include it
        if (x != y) {
            printf("Edge %d-%d included in MST\n", next_edge.src, next_edge.dest);
            edge_count++;
            union1(parent, x, y);
        }
    }
}

// Comparison function for sorting edges based on weight
int compare(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}

int main() {
    int num_vertices, num_edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    struct Edge edges[num_edges];

    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    printf("Following are the edges in the constructed MST\n");
    kruskalMST(edges, num_edges, num_vertices);

    return 0;
}

