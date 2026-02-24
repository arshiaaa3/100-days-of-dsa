#include <stdio.h>
#include <stdlib.h>

// structure
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, key, i;

    struct node *head = NULL, *temp = NULL, *newnode, *prev;

    // input number of nodes
    scanf("%d", &n);

    // create linked list
    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // input key
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    // delete first occurrence
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            if(prev == NULL) // first node delete
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    // print list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}