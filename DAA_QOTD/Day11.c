// Program to square elements of a sorted array and return them in sorted order

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n], result[n];

    printf("Enter sorted array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = n - 1;
    int pos = n - 1;

    while(left <= right) {
        int left_sq = arr[left] * arr[left];
        int right_sq = arr[right] * arr[right];

        if(left_sq > right_sq) {
            result[pos] = left_sq;
            left++;
        } else {
            result[pos] = right_sq;
            right--;
        }
        pos--;
    }

    printf("Sorted squares: ");
    for(i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}