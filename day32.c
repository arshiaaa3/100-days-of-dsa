#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1)
        return;
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1)
        return;
    top--;
}

int main() {
    int n, m, i, value;

    scanf("%d", &n);

    // Push n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack from top to bottom
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
