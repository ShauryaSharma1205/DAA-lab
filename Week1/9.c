// This program manages library books with add, search, issue, return and unavailable display

#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main() {
    struct Book b[100];
    int n = 0, choice, i, id;

    while(1) {
        printf("\n1.Add 2.Search 3.Issue 4.Return 5.Unavailable 6.Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter id, title, author, copies: ");
            scanf("%d %s %s %d", &b[n].id, b[n].title, b[n].author, &b[n].total);
            b[n].available = b[n].total;
            n++;
        }

        else if(choice == 2) {
            printf("Enter id to search: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++) {
                if(b[i].id == id) {
                    printf("%s by %s, Available: %d\n", b[i].title, b[i].author, b[i].available);
                }
            }
        }

        else if(choice == 3) {
            printf("Enter id to issue: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++) {
                if(b[i].id == id && b[i].available > 0) {
                    b[i].available--;
                    printf("Book issued\n");
                }
            }
        }

        else if(choice == 4) {
            printf("Enter id to return: ");
            scanf("%d", &id);

            for(i = 0; i < n; i++) {
                if(b[i].id == id && b[i].available < b[i].total) {
                    b[i].available++;
                    printf("Book returned\n");
                }
            }
        }

        else if(choice == 5) {
            printf("Unavailable books:\n");
            for(i = 0; i < n; i++) {
                if(b[i].available == 0) {
                    printf("%s\n", b[i].title);
                }
            }
        }

        else if(choice == 6) {
            break;
        }
    }

    return 0;
}