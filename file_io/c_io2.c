#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

char buf[255];
static void* creat_file();
static void* read_file();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

struct PEOPLE_DESCR
{
    char name[20];
    int age;
    int height;
    int weight;
    char profession[20];
}feen,peter;

static void* creat_file(){
    pthread_mutex_lock( &mutex1 );
    FILE* fp1 = fopen("src.txt","w+");
    FILE* fp2 = fopen("dest.txt","a+");

    if( !fp1 || !fp2){
        fprintf(stderr,"writre/create file.txt fail\n");
        return 0;
    }

    //struct PEOPLE_DESCR feen;
    strncpy(feen.name, "Feen",20);
    feen.age = 25, feen.height = 177, feen.weight = 70;
    strncpy(feen.profession,"student",20);
    
    fprintf(fp1," name: %s\n age: %d\n height: %d\n weight: %d\n profession: %s\n",feen.name,feen.age,feen.height,\
            feen.weight,feen.profession);

    strncpy(peter.name, "Peter",20);
    peter.age = 24, peter.height = 175, peter.weight = 60;
    strncpy(peter.profession,"student2",20);
        
    fprintf(fp2,"\n name: %s\n age: %d\n height: %d\n weight: %d\n profession: %s\n",peter.name,peter.age,peter.height,\
            peter.weight,peter.profession);
    printf("write finished!!!\n");
    
    fclose(fp1);
    fclose(fp2);
    pthread_mutex_unlock( &mutex1 );
    pthread_exit(NULL);
    return 0;
}

static void* read_file(){
    pthread_mutex_lock( &mutex1 );
    FILE* fp1 = fopen("src.txt","r");
    FILE* fp2 = fopen("dest.txt","r");
    FILE* fp3 = fopen("pic.jpg","rb");
    if( !fp1 || !fp2 || !fp3){
        fprintf(stderr,"read file.txt fail\n");
        return 0;
    }

    else{
        //printf("%s", fgets(buf, 255, fp1)); 
        //printf("%s", fgets(buf, 255, fp2));
        printf("read finished!!!!\n");
    }
    fclose(fp1);
    fclose(fp2);
    pthread_mutex_unlock( &mutex1 );
    pthread_exit(NULL);
    return 0;
}


int main(int argc, char *argv[]){
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, creat_file, NULL);
    pthread_create(&thread2, NULL, read_file, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}