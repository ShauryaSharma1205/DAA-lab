// Program to print matrix elements in spiral order

#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    printf("Enter matrix:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while(top <= bottom && left <= right) {

        for(i = left; i <= right; i++) {
            printf("%d ", arr[top][i]);
        }
        top++;

        for(i = top; i <= bottom; i++) {
            printf("%d ", arr[i][right]);
        }
        right--;

        if(top <= bottom) {
            for(i = right; i >= left; i--) {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
        }

        if(left <= right) {
            for(i = bottom; i >= top; i--) {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
    }

    return 0;
}