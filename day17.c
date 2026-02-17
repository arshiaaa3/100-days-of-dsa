#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];
    int max, min;

    // input size
    scanf("%d", &n);

    // input elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // assume first element is max and min
    max = arr[0];
    min = arr[0];

    // find max and min
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    // output
    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
