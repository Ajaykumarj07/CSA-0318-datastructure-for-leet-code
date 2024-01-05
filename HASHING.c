#include <stdio.h>
#define SIZE 10
int hash(int key) {
    return key % SIZE;
}
void insert(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}
int search(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != key) {
        if (hashTable[index] == -1) {
            return -1; 
        }
        index = (index + 1) % SIZE;
    }
    return index; 
void display(int hashTable[]) {
    printf("Hash Table: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}
int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    insert(hashTable, 5);
    insert(hashTable, 15);
    insert(hashTable, 25);
    display(hashTable);
    int keyToSearch = 15;
    int result = search(hashTable, keyToSearch);
    if (result != -1) {
        printf("Key %d found at index %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }
    return 0;
}