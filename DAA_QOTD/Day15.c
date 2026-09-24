// Program to detect cycle in a linked list using Floyd’s Algorithm

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int hasCycle(struct Node* head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Creating a cycle manually for testing (last node points to second node)
    if(head != NULL && head->next != NULL) {
        temp->next = head->next;
    }

    if(hasCycle(head)) {
        printf("Cycle detected");
    } else {
        printf("No cycle");
    }

    return 0;
}