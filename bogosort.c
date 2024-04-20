#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if the array is sorted
bool is_sorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array
void shuffle(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to perform bogosort
void bogosort(int arr[], int size) {
    while (!is_sorted(arr, size)) {
        shuffle(arr, size);
    }
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d numbers separated by spaces: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bogosort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
