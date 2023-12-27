#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;  
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;  
}

int main() {
    int n, key;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Number %d found at index %d.\n", key, result);
    } else {
        printf("Number %d not found in the array.\n", key);
    }

    return 0;
}
