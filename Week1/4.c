// Program to check if a string is palindrome ignoring spaces and case

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    char clean[100];
    int i = 0, j = 0;

    printf("Enter a string: ");
    gets(str);

    while(str[i] != '\0') {
        if(str[i] != ' ') {
            // tolower() converts uppercase letters to lowercase
            clean[j] = tolower(str[i]);
            j++;
        }
        i++;
    }
    clean[j] = '\0';

    int start = 0;
    int end = j - 1;
    int isPalindrome = 1;

    while(start < end) {
        if(clean[start] != clean[end]) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if(isPalindrome)
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}
