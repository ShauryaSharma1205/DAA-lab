// Program to rotate an array to the right by k positions

#include <stdio.h>

int main() {
    int n, k, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    for(i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}