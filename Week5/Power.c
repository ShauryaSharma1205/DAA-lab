// Program to calculate x^n using fast exponentiation (recursion)

#include <stdio.h>

// Function to compute power
long long power(int x, int n) {
    if (n == 0)
        return 1;

    long long y = power(x, n / 2);

    if (n % 2 == 0)
        return y * y;        // even case
    else
        return x * y * y;    // odd case
}

int main() {
    int x, n;

    printf("Enter base and exponent: ");
    scanf("%d %d", &x, &n);

    long long result = power(x, n);

    printf("Result = %lld\n", result);

    return 0;
}