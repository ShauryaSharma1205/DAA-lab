// Program to find the celebrity in a party using matrix

#include <stdio.h>

#define MAX 100

// Function to check if a is celebrity
int isCelebrity(int mat[MAX][MAX], int n, int c) {
    int i;

    for (i = 0; i < n; i++) {
        // Celebrity should not know anyone
        if (mat[c][i] == 1)
            return 0;

        // Everyone should know celebrity (except self)
        if (i != c && mat[i][c] == 0)
            return 0;
    }
    return 1;
}

// Function to find celebrity
int findCelebrity(int mat[MAX][MAX], int n) {
    int i, a = 0, b = n - 1;

    // Step 1: Find candidate
    while (a < b) {
        if (mat[a][b] == 1)
            a++;   // a knows b → a can't be celebrity
        else
            b--;   // a doesn't know b → b can't be celebrity
    }

    // Step 2: Verify candidate
    if (isCelebrity(mat, n, a))
        return a;

    return -1; // No celebrity
}

int main() {
    int n, i, j;
    int mat[MAX][MAX];

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int result = findCelebrity(mat, n);

    if (result == -1)
        printf("No Celebrity\n");
    else
        printf("Celebrity is person %d\n", result);

    return 0;
}