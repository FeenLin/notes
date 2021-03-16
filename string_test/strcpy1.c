//  strcpy and strncpy
#include<stdio.h>
#include<string.h>
#define LEN 80

int main(void){
    int buf[LEN];
    puts("input strings ...");
    fgets(buf, LEN, stdin);    

    int lenstr1 = strlen(buf) + 1;
    char str1[lenstr1];
    strcpy(str1, buf);
    printf("strcpy: %s \n",str1);

    int lenstr2 = strlen(buf);  //不複製換行
    char str2[lenstr2];
    memset(str2,'\0',lenstr2);
    strncpy(str2, buf, lenstr2);
    printf("strncpy: %s\n",str2);

    return 0;
}