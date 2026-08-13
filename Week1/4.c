// This program checks whether a string is a palindrome ignoring spaces and case

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    char clean[100];
    int i = 0, j = 0;

    printf("Enter a string: ");
    gets(str);

    // remove spaces and convert to lowercase
    while(str[i] != '\0') {
        if(str[i] != ' ') {
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