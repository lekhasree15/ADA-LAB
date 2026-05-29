#include <stdio.h>

#define V 6
#define INF 999999

int minDist(int dist[], int visited[]) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V];
    char names[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDist(dist, visited);

        visited[u] = 1;

        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from %c:\n\n", names[src]);

    for (int i = 0; i < V; i++) {
        printf("%c -> %c = %d\n", names[src], names[i], dist[i]);
    }
}

int main() {

    int graph[V][V];
    int src;

    printf("Enter adjacency matrix (%d x %d):\n\n", V, V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nVertex mapping:\n");
    printf("a=0 b=1 c=2 d=3 e=4 f=5\n");

    printf("\nEnter source vertex index: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
