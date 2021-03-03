#include<stdlib.h>
#include<stdio.h>

int main(){
    int v[6] = {1,2,3,4,5,6};                  // 一維陣列
    int *p = v;                                // 陣列不必加 &   int *p = &v[0]; 

    for (int i = 0; i < 6; i++)
    {
        printf("v[%d] : %d \n", i, *( v +i ));  // 記憶體位址會相同
        printf("p[%d] : %d \n", i, *( p +i ));

        printf("v[%d] addres: %p \n", i, &v[i]);
        printf("p[%d] addres: %p \n", i,  p +i );
        
        printf("\n");    

    }
    
   return 0;
}