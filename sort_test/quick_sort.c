#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
#define SWAP(a,b) {int tmp = a ; a =b ; b = tmp;}

static void quick_sort(int[] ,int ,int);

int main(void){
    srand(time(NULL));
    int arry[MAX]={0};

    printf("排序前: ");
    for(int i =0; i<MAX; i++){
        arry[i]=rand()%100;
        printf("%d ",arry[i]);
    }

    
    quick_sort(arry,0,MAX-1);
    printf("\n排序後: ");
    for(int i =0; i<MAX; i++){
        printf("%d ",arry[i]);
    }
    printf("\n");
    return 0;
}

static void quick_sort(int arry[],int left,int right){
    if(left<right){
        int pivot = arry[(left+right)/2];
        int i =left-1;
        int j =right+1;

        while(1){
            while(arry[++i] < pivot);
            while(arry[--j] > pivot);
            if (i >= j)
            {
                break;
            }
            SWAP(arry[i] , arry[j]);
        }
    quick_sort(arry,left,i-1);
    quick_sort(arry,j+1,right);
    }
}