#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *arr;

    printf("Enter the no of elements in the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory not Allotted");
    }

    for(int i = 0; i < n; i++){
        printf("Enter the element %d: ", i + 1);
        scanf("%d",&arr[i]);
    }

    int target = 0;

    printf("Enter the number to search for: ");
    scanf("%d", &target);

    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            printf("Target %d found at index %d", target, i);
        }
    }

    free(arr);

    return 0;
}