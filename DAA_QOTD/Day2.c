// Program to repeatedly ask for password until correct one is entered

#include <stdio.h>
#include <string.h>

// strcmp() is a library function used to compare two strings (returns 0 if equal)

int main() {
    char password[20];

    while(1) {
        printf("Enter password: ");
        scanf("%s", password);

        if(strcmp(password, "admin123") == 0) {
            printf("Login successful!");
            break;
        } else {
            printf("Incorrect password. Try again.\n");
        }
    }

    return 0;
}