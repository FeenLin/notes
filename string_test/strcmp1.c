#include<stdio.h>
#include<string.h>

#define LEN 100

int main(void){

    char str1[]="abc5566";
    char password[LEN];

    puts("enter password");
    fgets(password, LEN, stdin);

    if( strncmp(password,str1,7) == 0 ){
        printf("yessss!!!");
    }
    else
        printf("nooooo!!!");
    
    return 0;
}