#include<stdio.h>
#include<stdlib.h>

typedef struct data   data;
struct data{
    data  *next;
    char    *name;
};

static void print_arry(data *ptr);

int main(int argc, char *argv[]){

    data peter,feen,joe;
    data *ptr;

    peter.name ="Peter Wu";
    feen.name  ="Feen Lin";
    joe.name   ="Joe Chen";

    ptr= &joe;
    ptr->next= &feen;
    ptr->next->next= &peter;
    ptr->next->next->next=(data*) NULL;


    print_arry(ptr);

    return 0;
}

static void print_arry(data *ptr){
    if(ptr == NULL){
        return ;
    }

    if(ptr -> next != NULL){
        print_arry(ptr->next);
    }

    printf("%s\n",ptr->name);
    
}