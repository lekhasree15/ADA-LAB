#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000


void merge(int a[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = 0;
    int b[100000];
    while (i <= mid && j <= ub) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }


    while (i <= mid)
        b[k++] = a[i++];
    while (j <= ub)
        b[k++] = a[j++];
    for (i = lb, k = 0; i <= ub; i++, k++)
        a[i] = b[k];
}


void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}


int main() {
    int arr[MAX];
    srand(time(NULL));


    printf("Input Size\tTime Taken (sec)\n");
    for (int n = 10000; n <= MAX; n += 10000) {
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000;
        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t\t%f\n", n, time_taken);
    }
    return 0;
}
