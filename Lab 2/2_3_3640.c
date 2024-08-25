#include <stdio.h>
#include <stdlib.h>

// Function to traverse the array
void traverse(int* arr, int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element
void insert(int* arr, int* n) {
    int pos, val;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    printf("Enter the value to insert: ");
    scanf("%d", &val);
    if (pos < 0 || pos > *n) {
        printf("Invalid position\n");
        return;
    }
    *n = *n + 1;
    int* temp = (int*)realloc(arr, *n * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
    for (int i = *n - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
}

// Function to delete an element
void delete(int* arr, int* n) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= *n) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    *n = *n - 1;
    int* temp = (int*)realloc(arr, *n * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    arr = temp;
}

// Function to merge two arrays
void merge(int* arr1, int n1, int* arr2, int n2) {
    int* arr3 = (int*)malloc((n1 + n2) * sizeof(int));
    for (int i = 0; i < n1; i++) {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        arr3[n1 + i] = arr2[i];
    }
    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    free(arr3);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Input elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice=0;
    while (1) {
        printf("Menu:\n");
        printf("1. Traverse elements\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Merge elements of two arrays\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, n);
                break;
            case 2:
                insert(arr, &n);
                break;
            case 3:
                delete(arr, &n);
                break;
            case 4: {
                int n2;
                printf("Enter the number of elements for the second array: ");
                scanf("%d", &n2);
                int* arr2 = (int*)malloc(n2 * sizeof(int));
                printf("Enter %d elements for the second array: ", n2);
                for (int i = 0; i < n2; i++) {
                    scanf("%d", &arr2[i]);
                }
                merge(arr, n, arr2, n2);
                free(arr2);
                break;
            }
            case 5:
                free(arr);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}