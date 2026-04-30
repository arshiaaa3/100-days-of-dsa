#include <stdio.h>

// Check if allocation is possible
int canAllocate(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (currentPages + pages[i] > maxPages) {
            students++;
            currentPages = pages[i];

            if (students > m)
                return 0; // not possible
        } else {
            currentPages += pages[i];
        }
    }
    return 1;
}

// Main function
int allocateBooks(int pages[], int n, int m) {
    if (m > n) return -1; // not possible

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > left)
            left = pages[i]; // max element
        right += pages[i];   // total sum
    }

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(pages, n, m, mid)) {
            result = mid;
            right = mid - 1; // try smaller
        } else {
            left = mid + 1;  // increase
        }
    }

    return result;
}