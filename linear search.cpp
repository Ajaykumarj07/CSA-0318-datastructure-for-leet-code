#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        printf("Number %d found at index %d.\n", key, result);
    } else {
        printf("Number %d not found in the array.\n", key);
    }

    return 0;
}
