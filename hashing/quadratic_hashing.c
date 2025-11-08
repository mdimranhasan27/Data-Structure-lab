#include <stdio.h>

#define SIZE 11

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i*i) % SIZE] != -1) {
        i++;
    }
    hashTable[(index + i*i) % SIZE] = key;
}

int search(int hashTable[], int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i*i) % SIZE] != -1) {
        if (hashTable[(index + i*i) % SIZE] == key)
            return (index + i*i) % SIZE;
        i++;
        if (i == SIZE) return -1;
    }
    return -1;
}
int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;

    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++)
        insert(hashTable, data[i]);

    printf("Hash Table (Linear Probing):\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d] -> %d\n", i, hashTable[i]);

    int key = 44;
    int pos = search(hashTable, key);
    if (pos != -1) printf("\n%d found at index %d\n", key, pos);
    else printf("\n%d not found\n", key);

    return 0;
}
