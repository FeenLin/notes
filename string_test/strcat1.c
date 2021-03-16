#include<stdio.h>
#include<string.h>

int main(void){

    char str1[]="hello ";
    char str2[]="world";

    int lenstr3=strlen(str1) + strlen(str2) +1;
    char str3[lenstr3];
    memset(str3, '\0', lenstr3);

    strcat(str3, str1);
    strcat(str3, str2);

    printf("%s\n",str3);

    return 0;
}