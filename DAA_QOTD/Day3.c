// Program to find the length of the longest consecutive increasing streak

#include <stdio.h>

int main() {
    int arr[] = {10, 12, 15, 14, 16, 18, 20};
    int n = 7;

    int current = 1;
    int max = 1;
    int i;

    for(i = 1; i < n; i++) {
        if(arr[i] > arr[i - 1]) {
            current++;
        } else {
            current = 1;
        }

        if(current > max) {
            max = current;
        }
    }

    printf("%d\n", max);

    return 0;
}