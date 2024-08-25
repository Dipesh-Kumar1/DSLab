#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} sparse_matrix;
void transpose_sparse_matrix(sparse_matrix* matrix, int num_elements) {
    sparse_matrix* transposed_matrix = (sparse_matrix*)malloc(num_elements * sizeof(sparse_matrix));

    for (int i = 0; i < num_elements; i++) {
        transposed_matrix[i].row = matrix[i].col;
        transposed_matrix[i].col = matrix[i].row;
        transposed_matrix[i].val = matrix[i].val;
    }

    printf("Transposed matrix:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("(%d, %d, %d)\n", transposed_matrix[i].row, transposed_matrix[i].col, transposed_matrix[i].val);
    }

    free(transposed_matrix);
}

int main() {
    int num_elements;
    printf("Enter the number of elements in the sparse matrix: ");
    scanf("%d", &num_elements);

    sparse_matrix* matrix = (sparse_matrix*)malloc(num_elements * sizeof(sparse_matrix));

    printf("Enter the elements of the sparse matrix (row, col, val):\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].val);
    }

    transpose_sparse_matrix(matrix, num_elements);

    free(matrix);
    return 0;
}
