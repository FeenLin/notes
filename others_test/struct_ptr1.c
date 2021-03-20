#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    typedef struct 
    {
        char* firstname;
        char* lastname;
        int number;
    }Student;

    int i;
    int student_num = 2;

    Student* students=malloc(student_num * sizeof(Student));

    for ( i = 0; i < student_num ; i++)
    {
        students[i].firstname = (char *)malloc(sizeof(char*));
        printf("frist name: ");
        scanf("%s",students[i].firstname);

        students[i].lastname = (char *)malloc(sizeof(char*));
        printf("last name: ");
        scanf("%s",students[i].lastname);

        printf("id: ");
        scanf("%d",&students[i].number);
    }

    for ( i = 0; i <  student_num; i++)
    {
        printf("fristname:%s   lastname:%s  id:%d\n",students[i].firstname,students[i].lastname,students[i].number);
    }
    
    
    return 0;
}