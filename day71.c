#include <stdio.h>
#include <string.h>

#define SIZE 1009   // prime size for better distribution

int table[SIZE];

// Initialize table
void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;   // -1 means empty
}

// Hash function
int hash(int key, int i) {
    return ( (key % SIZE) + i*i ) % SIZE;
}

// Insert using quadratic probing
void insert(int key) {
    for (int i = 0; i < SIZE; i++) {
        int idx = hash(key, i);

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key) {
    for (int i = 0; i < SIZE; i++) {
        int idx = hash(key, i);

        if (table[idx] == -1)
            return 0;   // not found

        if (table[idx] == key)
            return 1;   // found
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d", &m);   // table size (can ignore or use)
    scanf("%d", &n);   // number of operations

    init();

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}