#include <stdio.h>

// check if we can paint within given maxTime using <= k painters
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];
        }
    }

    return painters <= k;
}

int minTime(int boards[], int n, int k) {
    int low = 0, high = 0;

    // find max board and total sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller time
        } else {
            low = mid + 1;   // need more time
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));

    return 0;
}