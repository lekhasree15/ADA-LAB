#include <stdio.h>
#define MAX 100
int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], count = 0;


    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter no. of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u, v)\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;


    while (front < rear) {
        int u = queue[front++];
        topo[count++] = u;
        for (int v = 1; v <= n; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }
    if (count != n)
        printf("Graph has a cycle. Topological sort not possible.\n");
    else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }
    return 0;
}
