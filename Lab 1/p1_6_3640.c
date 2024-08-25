#include <stdio.h>

int cmp(int *a,int *b,int *greater,int *smaller){
    if(*a>*b){
        *greater = *a;
        *smaller = *b;
    }else{
        *smaller = *a;
        *greater = *b;
    }
}

int main(){
    int a, b;

    printf("Enter the value of 1st number a: ");
    scanf("%d", &a);

    printf("Enter the value of 2st number b: ");
    scanf("%d", &b);

    int greater=0;
    int smaller=0;

    cmp(&a, &b, &greater, &smaller);

    printf("%d is greater than %d.",greater, smaller);

    return 0;
}