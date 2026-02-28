#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    temp->next = head;

    // Traverse and print
    struct Node* ptr = head;
    if (head != NULL) {
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }

    return 0;
}