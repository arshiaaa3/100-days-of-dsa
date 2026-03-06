#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main()
{
    char exp[100];
    char *token;

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    token = strtok(exp, " ");

    while(token != NULL)
    {
        if(isdigit(token[0]))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();
            int result;

            switch(token[0])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("Result = %d\n", pop());

    return 0;
}