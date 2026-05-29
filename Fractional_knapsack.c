#include <stdio.h>


struct Item {
    double value, weight, ratio;
};


int main() {
    int n;
    double W;
    printf("Enter no. of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%lf", &W);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value & weight: ");
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].ratio = items[i].value / items[i].weight;
    }


    // Bubble sort by ratio descending
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }


    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += items[i].ratio * W;
            W = 0;
        }
    }


    printf("Max Value: %.2f\n", totalValue);
    return 0;
}
