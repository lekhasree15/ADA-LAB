#include <stdio.h>
#include <stdlib.h>
#define V 5
#define E 7


struct Edge {
    int src, dest, weight;
};


int parent[V];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}


int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}


void kruskal(struct Edge edges[]) {
    qsort(edges, E, sizeof(struct Edge), compare);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    printf("Edge \tWeight\n");
    int count = 0;
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        if (find(u) != find(v)) {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            unionSet(u, v);
            count++;
        }
    }
}
int main() {
    struct Edge edges[E] = {
        {0, 1, 2},
        {1, 2, 3},
        {1, 4, 5},
        {0, 3, 6},
        {2, 4, 7},
        {1, 3, 8},
        {3, 4, 9}
    };


    kruskal(edges);
    return 0;
}
