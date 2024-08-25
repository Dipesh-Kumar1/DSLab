#include <stdio.h>
#include <stdlib.h>
  //sparse matrix represent karne ka structure
typedef struct {
    int row;
    int col;
    int val;
} sparse_matrix;
 //function to add two matrices
void add_sparse_matrices(sparse_matrix* matrix1, int num_elements1, sparse_matrix* matrix2, int num_elements2) {
    sparse_matrix* result_matrix = (sparse_matrix*)malloc((num_elements1 + num_elements2) * sizeof(sparse_matrix));
    int result_index = 0;

   // merging two matrices 
    int i = 0, j = 0;
    while (i < num_elements1 && j < num_elements2) {
        if (matrix1[i].row < matrix2[j].row) {
            result_matrix[result_index++] = matrix1[i++];
        } else if (matrix1[i].row > matrix2[j].row) {
            result_matrix[result_index++] = matrix2[j++];
        } else {
            if (matrix1[i].col < matrix2[j].col) {
                result_matrix[result_index++] = matrix1[i++];
            } else if (matrix1[i].col > matrix2[j].col) {
                result_matrix[result_index++] = matrix2[j++];
            } else {
                result_matrix[result_index].row = matrix1[i].row;
                result_matrix[result_index].col = matrix1[i].col;
                result_matrix[result_index].val = matrix1[i].val + matrix2[j].val;
                result_index++;
                i++;
                j++;
            }
        }
    }
// adding remaining elements from matrix 1
    while (i < num_elements1) {
        result_matrix[result_index++] = matrix1[i++];
    }
// adding remaining elements from matrix 2
    while (j < num_elements2) {
        result_matrix[result_index++] = matrix2[j++];
    }
// printing the result matrix
    printf("Result matrix:\n");
    for (int k = 0; k < result_index; k++) {
        printf("(%d, %d, %d)\n", result_matrix[k].row, result_matrix[k].col, result_matrix[k].val);
    }

    free(result_matrix);
}

int main() {
    int num_elements1, num_elements2;
    printf("Enter the number of elements in the first sparse matrix: ");
    scanf("%d", &num_elements1);

    sparse_matrix* matrix1 = (sparse_matrix*)malloc(num_elements1 * sizeof(sparse_matrix));

    printf("Enter the elements of the first sparse matrix (row, col, val):\n");
    for (int i = 0; i < num_elements1; i++) {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].val);
    }

    printf("Enter the number of elements in the second sparse matrix: ");
    scanf("%d", &num_elements2);

    sparse_matrix* matrix2 = (sparse_matrix*)malloc(num_elements2 * sizeof(sparse_matrix));

    printf("Enter the elements of the second sparse matrix (row, col, val):\n");
    for (int i = 0; i < num_elements2; i++) {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].val);
    }

    add_sparse_matrices(matrix1, num_elements1, matrix2, num_elements2);

    free(matrix1);
    free(matrix2);
    return 0;
}
