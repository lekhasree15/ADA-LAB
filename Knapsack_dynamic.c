#include <stdio.h>


int max(int a, int b) { return (a > b) ? a : b; }
void traceback(int c[][100], int wt[], int n, int W) {
    printf("Items: ");
    for (int i = n; i > 0; i--) {
        if (c[i][W] != c[i - 1][W]) {
            printf("%d ", i);
            W -= wt[i - 1];
        }
    }
    printf("\n");
}


int main() {
    int n, W;
    printf("Enter no. of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int val[n], wt[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value & weight of item %d: ", i + 1);
        scanf("%d %d", &val[i], &wt[i]);
    }
    int c[n + 1][100];
    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                c[i][w] = 0;
            else if (wt[i - 1] <= w)
                c[i][w] = max(val[i - 1] + c[i - 1][w - wt[i - 1]], c[i - 1][w]);
            else
                c[i][w] = c[i - 1][w];
        }
    printf("Maximum value: %d\n", c[n][W]);
    traceback(c, wt, n, W);
    return 0;
}
