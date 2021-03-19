#include<stdio.h>

typedef const char* String;

typedef struct
{
    String id;
    String name;
    double balance;

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


int main(int argc,char* argv[]){
    Account people ={"123456","Peter Lin",10000};
    despoite(&people,1000);
    withdraw(&people,5000);

    printf("id: %s, name: %s, balance: %f\n",people.id, people.name, people.balance);

    return 0;

}