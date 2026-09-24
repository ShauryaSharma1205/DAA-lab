// Program to find median of two sorted arrays

#include <stdio.h>

int main() {
    int m, n, i, j, k;

    printf("Enter size of first array: ");
    scanf("%d", &m);

    int a[m];
    printf("Enter elements of first array: ");
    for(i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int b[n];
    printf("Enter elements of second array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int merged[m + n];

    i = 0, j = 0, k = 0;

    while(i < m && j < n) {
        if(a[i] < b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    while(i < m) {
        merged[k++] = a[i++];
    }

    while(j < n) {
        merged[k++] = b[j++];
    }

    int total = m + n;

    if(total % 2 == 1) {
        printf("Median = %d", merged[total / 2]);
    } else {
        float median = (merged[total / 2] + merged[total / 2 - 1]) / 2.0;
        printf("Median = %.2f", median);
    }

    return 0;
}