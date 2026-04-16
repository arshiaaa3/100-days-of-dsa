#include <stdio.h>
#include <stdlib.h>

// Simple hash map using array (since constraints are small)
int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Hash map (sum -> first index)
    // Using large range for simplicity
    int *hash = (int *)malloc(sizeof(int) * 200001);

    // Initialize with -2 (means not visited)
    for (int i = 0; i < 200001; i++)
        hash[i] = -2;

    // Offset to handle negative sums
    int offset = 100000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // If sum seen before
        if (hash[sum + offset] != -2) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            // Store first occurrence
            hash[sum + offset] = i;
        }
    }

    free(hash);
    return maxLen;
}

// Driver code
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));
    return 0;
}