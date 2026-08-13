// This program finds the second largest distinct element in an array without sorting

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int second = arr[0];

    // find largest first
    for(i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    // find second largest
    for(i = 0; i < n; i++) {
        if(arr[i] != largest) {
            second = arr[i];
            break;
        }
    }

    for(i = 0; i < n; i++) {
        if(arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if(second == largest)
        printf("No second largest element");
    else
        printf("Second largest element = %d", second);

    return 0;
}