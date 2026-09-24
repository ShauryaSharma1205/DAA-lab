// Program to find smallest difference between elements of two arrays

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int m, n, i = 0, j = 0;

    printf("Enter size of first array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter elements of first array: ");
    for(int k = 0; k < m; k++) {
        scanf("%d", &arr1[k]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter elements of second array: ");
    for(int k = 0; k < n; k++) {
        scanf("%d", &arr2[k]);
    }

    // sorting both arrays
    qsort(arr1, m, sizeof(int), compare);
    qsort(arr2, n, sizeof(int), compare);

    int minDiff = abs(arr1[0] - arr2[0]);

    while(i < m && j < n) {
        int diff = abs(arr1[i] - arr2[j]);

        if(diff < minDiff) {
            minDiff = diff;
        }

        if(arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    printf("Smallest difference = %d", minDiff);

    return 0;
}