#include<stdio.h>
#include<stdlib.h>

typedef const char* String;

typedef struct
{
    String id;
    String name;
    double balance;

    char (*_to_str);

    void (*despoite(Account,double));
    void (*withdraw(Account,double));
    String (*to_str(Account));
}Account;

void despoite(Account *people, double amount){
    if(amount <=0){
        printf("pls input number");
        return;
    }
    people->balance +=amount;
}

void withdraw(Account *people, double amount){
    if(people->balance < amount){
        printf("noooo $$$$ !!!");
        return;
    }
    people->balance -=amount;
}

String (*to_str(Account *people)){
    int n = snprintf(NULL,0,"Account(%s%s%f)",people->id, people->name, people->balance);
    if(people->_to_str != NULL ){
        free(people->to_str);
    }
    people->_to_str = malloc((n+1)*sizeof(char));
    snprintf("")
}