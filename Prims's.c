#include <stdio.h>
#define V 5
#define INF 999999


int minKey(int key[], int mstSet[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}


void printPath(int parent[], int v) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }
    printPath(parent, parent[v]);
    printf(" %d", v);
}


void primMST(int graph[V][V]) {
    int parent[V], key[V], mstSet[V];
    int totalDist[V];  // cumulative distance from source
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
        parent[i] = -1;
        totalDist[i] = 0;
    }


    key[0] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
                totalDist[v] = totalDist[u] + graph[u][v]; // accumulate
            }
        }
    }
    printf("Vertex\tDistance\tPath\n");
    printf("0\t0\t\t0\n");
    for (int i = 1; i < V; i++) {
        printf("%d\t%d\t\t", i, totalDist[i]);
        printPath(parent, i);
        printf("\n");
    }
}


int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };
    primMST(graph);
    return 0;
}
