#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

   
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    int newSize = 0; 
    for (int i = 0; i < n; i++) {
        int j;
       
        for (j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        
        if (j == newSize) {
            arr[newSize++] = arr[i];
        }
    }

    
    printf("Array with distinct elements: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   
    free(arr);

    return 0;
}