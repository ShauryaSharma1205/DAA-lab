// Program to find indices of two elements whose sum equals target

#include <stdio.h>

int main() {
    int arr[] = {2, 7, 11, 15};
    int n = 4;
    int target = 9;

    int i, j;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                printf("[%d, %d]", i, j);
                return 0;
            }
        }
    }

    return 0;
}