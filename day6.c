#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Taking input
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Printing unique elements
    if(n > 0) {
        printf("%d ", arr[0]);   // first element always unique
    }

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
