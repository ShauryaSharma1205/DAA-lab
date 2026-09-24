/* Program to find Minimum Spanning Tree using Kruskal's Algorithm */

#include <stdio.h>
#include <stdlib.h>

// Structure for edges
struct Edge {
    int u, v, weight;
};

// Function to compare edges (for sorting)
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Find function for Union-Find
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Union function
void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    int count = 0, i = 0;
    while (count < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(parent, next.u);
        int y = find(parent, next.v);

        if (x != y) {
            printf("%d - %d : %d\n", next.u, next.v, next.weight);
            unionSet(parent, x, y);
            count++;
        }
    }

    return 0;
}