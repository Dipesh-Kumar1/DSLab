#include <stdio.h>

struct Student {
    int rollNo;
    char name[40];
    char gender;
    float marks;
};

int main(){
    struct Student student;
    struct Student* ptr;
    ptr = &student;

    printf("enter the details of the student : \n");
    printf("\n Enter roll No: ");
    scanf("%d",&(ptr->rollNo));

    printf("\n Enter name: ");
    scanf("%s",(ptr->name));

    printf("\n Enter gender:");
    scanf(" %c", &(ptr->gender));

    printf("\n Enter marks: ");
    scanf(" %f", &(ptr->marks));

    printf("The details of the student are : \n");
    printf("Name of the student : %s \n", ptr->name);
    printf("Roll NO of the student: %d \n", ptr->rollNo);
    printf("The gender of the student: %c \n", ptr->gender);
    printf("The marks of the student : %.2f \n", ptr->marks);

    return 0;
}