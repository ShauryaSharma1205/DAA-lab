// Program to check whether a password is secure based on given conditions

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int i, len;

    int hasLower = 0;
    int hasUpper = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    printf("Enter password: ");
    scanf("%s", password);

    len = strlen(password);

    if(len < 10) {
        printf("Not Secure");
        return 0;
    }

    for(i = 0; i < len; i++) {

        if(password[i] >= 'a' && password[i] <= 'z')
            hasLower = 1;

        // isupper() checks if character is uppercase letter
        if(i != 0 && i != len-1 && isupper(password[i]))
            hasUpper = 1;

        // isdigit() checks if character is a digit
        if(i != 0 && i != len-1 && isdigit(password[i]))
            hasDigit = 1;

        if(i != 0 && i != len-1 &&
           (password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '&' || password[i] == '?'))
            hasSpecial = 1;
    }

    if(hasLower && hasUpper && hasDigit && hasSpecial)
        printf("Secure");
    else
        printf("Not Secure");

    return 0;
}