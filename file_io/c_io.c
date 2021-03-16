#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char buf[255];
static void* creat_file();
static void* read_file();

typedef struct 
{
    char* name;
    int age;
    int height;
    int weight;
    char* profession;
}PEOPLE_DESCR;

static void* creat_file(){
    FILE* fp1 = fopen("src.txt","w+");
    FILE* fp2 = fopen("dest.txt","w+");

    if( !fp1 || !fp2){
        fprintf(stderr,"writre/create file.txt fail\n");
        return 0;
    }
   
    fputs("hello4 \n",fp1);
    fputs("copy4: \n",fp2);
    printf("write finished!!!\n");
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}

static void* read_file(){
    FILE* fp1 = fopen("src.txt","r");
    FILE* fp2 = fopen("dest.txt","r");
    printf("%s", fgets(buf, 255, fp1)); 
    printf("%s", fgets(buf, 255, fp2)); 

    fclose(fp1);
    fclose(fp2);
    return 0;
}


int main(int argc, char *argv[]){

    creat_file();
    read_file();

    return 0;
}