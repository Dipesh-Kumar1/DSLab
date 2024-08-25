#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    char publication[100];
    float price;
};

int main(){
    int numBooks;

    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    struct Book book[numBooks];
    struct Book* ptr;
    ptr = (struct Book*)malloc(numBooks * sizeof(struct Book));

    for(int i = 0; i < numBooks; i++){

        printf("Enter the details of BOOK %d \n", i+1);
        printf("Enter the title of Book %d: ",i+1);
        scanf("%s", book[i].title);
        printf("Enter the author of Book %d: ",i+1);
        scanf("%s", book[i].author);
        printf("Enter the publication of Book %d: ",i+1);
        scanf("%s", book[i].publication);
        printf("Enter the price of Book %d: ",i+1);
        scanf("%f", &book[i].price);
        
        printf("\n");
    }

    char Author[100];
    printf("Enter the name of author of the book you want : ");
    scanf("%s", Author);

    for(int i = 0 ; i < numBooks; i++){
        if(strcmp(book[i].author,Author) == 0){
            printf("Title: %s \n", book[i].title);
            printf("Author: %s \n", book[i].author);
            printf("Publication: %s \n", book[i].publication);
            printf("Price: %.2f \n", book[i].price);
        }
    }

    return 0;
}