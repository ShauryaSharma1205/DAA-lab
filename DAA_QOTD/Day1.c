// Program to find the missing digit from 0 to 9 in a number where one digit is missing

#include <stdio.h>

int main() {
    long long num;
    int sum = 0;

    printf("Enter number: ");
    scanf("%lld", &num);

    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }

    int total = 45; // sum of digits from 0 to 9

    printf("Missing digit = %d", total - sum);

    return 0;
}