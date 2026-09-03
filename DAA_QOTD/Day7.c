// Program to find the single element in a sorted array where every other element appears twice

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0, high = n - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(mid % 2 == 1) {
            mid--;
        }

        if(arr[mid] == arr[mid + 1]) {
            low = mid + 2;
        } else {
            high = mid;
        }
    }

    printf("%d", arr[low]);

    return 0;
}