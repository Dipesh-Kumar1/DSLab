#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial
typedef struct {
    int degree;
    int* coefficients;
} polynomial;

// Function to create a polynomial from user input
polynomial create_polynomial() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    polynomial p;
    p.degree = degree;
    p.coefficients = (int*)malloc((degree + 1) * sizeof(int));

    printf("Enter the coefficients of the polynomial (from highest to lowest degree):\n");
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &p.coefficients[i]);
    }

    return p;
}

// Function to add two polynomials
polynomial add_polynomials(polynomial p1, polynomial p2) {
    int max_degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;
    polynomial result;
    result.degree = max_degree;
    result.coefficients = (int*)malloc((max_degree + 1) * sizeof(int));

    for (int i = 0; i <= max_degree; i++) {
        result.coefficients[i] = 0;
        if (i <= p1.degree) {
            result.coefficients[i] += p1.coefficients[i];
        }
        if (i <= p2.degree) {
            result.coefficients[i] += p2.coefficients[i];
        }
    }

    return result;
}

// Function to print a polynomial
void print_polynomial(polynomial p) {
    printf("Polynomial: ");
    for (int i = 0; i <= p.degree; i++) {
        if (p.coefficients[i] != 0) {
            if (i == 0) {
                printf("%d", p.coefficients[i]);
            } else if (i == 1) {
                printf("%dx", p.coefficients[i]);
            } else {
                printf("%dx^%d", p.coefficients[i], i);
            }
            if (i < p.degree) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    polynomial p1 = create_polynomial();
    polynomial p2 = create_polynomial();

    printf("Polynomial 1: ");
    print_polynomial(p1);
    printf("Polynomial 2: ");
    print_polynomial(p2);

    polynomial result = add_polynomials(p1, p2);
    printf("Result: ");
    print_polynomial(result);

    free(p1.coefficients);
    free(p2.coefficients);
    free(result.coefficients);
    return 0;
}
