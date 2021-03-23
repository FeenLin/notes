#include<stdio.h>

int main(void){

    char a[]="0113256";
    char *p =a;
    
    printf("%s\n",a);
    printf("%s\n",p);
    printf("%c ",*p++);
    printf("%c ",*(p++));
    printf("%c ",*++p);
    printf("%c ",*(++p));
    printf("%c ",++*p);
    printf("%c ",++(*p));
    printf("%c ",(*p)++);
    printf("\n");
    printf("%s\n",a);
    printf("%s\n",p);
    return 0;
}

/*

*p++ = *(p++)     =>    先取值後,指標下移

*++p = *(++p)     =>    指標下移,再取值

++*p = ++(*p)     =>    先把該值+1,後取值

(*p)++            =>    先取值後,該值+1    

*/