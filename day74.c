#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];
    int count[MAX] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        char temp[NAME_LEN];
        scanf("%s", temp);

        int found = 0;

        // Check if name already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        // If new name
        if (!found) {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[NAME_LEN];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}