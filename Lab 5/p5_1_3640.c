#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int degree;
    struct node *next;
};
typedef struct node NODE;

NODE * createNewNode(int val, int deg) {
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = val;
    newNode->degree = deg;
    newNode->next = NULL;

    return newNode;
}

NODE * addTerm(NODE** poly,int val, int deg){
    NODE* newTerm = createNewNode(val, deg);
    if(*poly == NULL){
        *poly = newTerm;
    }else{
        NODE * current = *poly;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newTerm;
    }
}

NODE * addTwoPoly(NODE* poly1, NODE * poly2) {
    NODE * result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->degree > poly2->degree) {
            addTerm(&result, poly1->coeff, poly1->degree);
            poly1 = poly1->next;
        } else if (poly1->degree < poly2->degree) {
            addTerm(&result, poly2->coeff, poly2->degree);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                addTerm(&result, sum, poly1->degree);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        addTerm(&result, poly1->coeff, poly1->degree);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        addTerm(&result, poly2->coeff, poly2->degree);
        poly2 = poly2->next;
    }
    return result;
}

void displayPolynomial(NODE* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d ", poly->coeff, poly->degree);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}
int main(){
    NODE * poly1 = NULL;
    NODE * poly2 = NULL;
    NODE * result = NULL;

    addTerm(&poly1, 5, 4);
    addTerm(&poly1, 3, 3);
    addTerm(&poly1, 2, 1);

    addTerm(&poly2, 2, 3);
    addTerm(&poly2, 4, 2);
    addTerm(&poly2, 1, 0);

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    result = addTwoPoly(poly1, poly2);
    printf("Sum of polynomial: ");
    displayPolynomial(result);
    return 0;
}
