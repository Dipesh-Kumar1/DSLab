#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int nonZeroCount = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    printf("Number of non-zero elements: %d\n", nonZeroCount);

    printf("Row-wise sum and average:\n");
    for(int i = 0; i < n; i++) {
        int rowSum = 0;
        for(int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        double rowAverage = (double)rowSum / n;
        printf("Row %d - Sum: %d, Average: %.2f\n", i, rowSum, rowAverage);
    }

    printf("Column-wise sum and average:\n");
    for(int j = 0; j < n; j++) {
        int colSum = 0;
        for(int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        double colAverage = (double)colSum / n;
        printf("Column %d - Sum: %d, Average: %.2f\n", j, colSum, colAverage);
    }

    return 0;
}
