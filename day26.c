#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    int n, i, value;

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create nodes
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        // allocate memory
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        // first node
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // Traversal in forward direction
    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}