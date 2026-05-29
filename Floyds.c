
#include <stdio.h>
#define INF 999
#define MAX 20


void floyd(int dist[MAX][MAX], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}


int main() {
    int n;
    int dist[MAX][MAX];


    printf("Enter no. of vertices: ");
    scanf("%d", &n);


    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);


    floyd(dist, n);


    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", dist[i][j]);
        printf("\n");
    }


    return 0;
}
