#include <stdio.h>
#include <stdlib.h>

int main(){
    char *word;
    int size = 100;

    word = (char *)malloc(size * sizeof(char));
    if(word == NULL){
        printf("Memory not allocated");
    }

    printf("Enter a string: ");
    scanf("%s",word);
    
    int length=0;

    while(*word != '\0'){
        length++;
        word++;
    }

    printf("the length of the string is: %d ", length);
}