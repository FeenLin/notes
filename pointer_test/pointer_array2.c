#include<stdlib.h>
#include<stdio.h>

// C 沒有真正的"二維陣列"，是採用 arrays of arrays 去表示

int main(){
    int v[2][3] = { {1,2,3} , {4,5,6} };
    
    for (int i = 0; i < 2; i++)
    {   
        int *raw = v[i];
        for (int j = 0; j < 3; j++)
        {
            printf("%d \t",raw[j]);
        }
        printf("\n");
    }
    

return 0;
}