#include<stdio.h>
#include<stdlib.h>

int tmp[255];

void insortion(int arr[],int len);
void printfarr(int arr[],int len);

void insortion(int arr[],int len){
    
    for (int i = 0; i < len; i++){
        int j=i;
        while (j>0 && arr[j-1]>arr[j])
        {
            int tmp = arr[j];
            arr[j]= arr[j-1];
            arr[j-1]= tmp;
            j--;
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
    int arr[]={1,6,4,8,2,9,5,10,45,100};
    insortion(arr,10);
    printf("\n");
    printfarr(arr,10);
    return 0;
}