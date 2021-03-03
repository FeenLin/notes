#include<stdio.h>
#include<string.h>

int main(){
    char str[] = "hello world";   //使用" " 後面會自動加\0
    char *ptr =str;               // 也可以直接寫成  char *ptr = "hello world"; 
    int len = strlen(str) + 1;   // +1 為了 \0

   
    printf("%s",str);    
    printf("\n");

    for (int i = 0; i < len ; i++)
    {
        printf("%c",*(str+i));
    }
    printf("\n");

    for (int i = 0; i < len ; i++)
    {
        printf("%c",*(ptr+i));
    }
    printf("\n");

    
    for (int i = 0; i < len ; i++)
    {
        printf("%c",ptr[i]);
    }
    printf("\n");

    return 0;
}