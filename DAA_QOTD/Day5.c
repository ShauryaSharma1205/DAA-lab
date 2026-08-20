// Program to count number of 1s, 0s, and consecutive 1s in binary representation

#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int ones = 0, zeros = 0;
    int maxConsecutive = 0, current = 0;

    while(n > 0) {
        if(n % 2 == 1) {
            ones++;
            current++;
            if(current > maxConsecutive) {
                maxConsecutive = current;
            }
        } else {
            zeros++;
            current = 0;
        }
        n = n / 2;
    }

    printf("Number of 1s = %d\n", ones);
    printf("Number of 0s = %d\n", zeros);
    printf("Max consecutive 1s = %d\n", maxConsecutive);

    return 0;
}