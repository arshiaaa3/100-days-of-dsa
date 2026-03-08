#include <stdio.h>

#define MAX 100

int main()
{
    int q[MAX];
    int front = 0, rear = -1;
    int n, m, i;

    // number of elements
    scanf("%d", &n);

    // enqueue elements
    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        q[rear] = x;
    }

    // number of dequeues
    scanf("%d", &m);

    // dequeue operations
    for(i = 0; i < m; i++)
    {
        front = (front + 1) % MAX;
    }

    // print elements from front to rear
    int count = n - m;
    for(i = 0; i < count; i++)
    {
        printf("%d ", q[(front + i) % MAX]);
    }

    return 0;
}