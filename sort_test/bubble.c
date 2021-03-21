#include<stdio.h>
#include<stdlib.h>

int tmp[255];

void insortion(int arr[],int len);
void printfarr(int arr[],int len);

void bubble(int arr[],int len){
    int i;
    for ( i = 0; i < len; i++){
        for (int j = 0; j < len-i; j++){
            if (arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] =tmp;
            }     
        }
        printfarr(arr,10); 
    }  
}

void printfarr(int arr[],int len){
     for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}


int main(int argc, char* argv[]){
    int arr[]={1,6,4,8,2,9,5,10,45,99};
    bubble(arr,10);
    printfarr(arr,10);
    return 0;
}