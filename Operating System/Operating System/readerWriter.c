#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

struct semaphore{
    int x;
    int y;
};

struct semaphore x,y;
int readcount;

void wait(volatile int*semaphore){
    (*semaphore)--;
}

void signal(volatile int*semaphore){
    (*semaphore)++;
}

void *reader(){
    wait(&x.x);
    readcount++;
    if(readcount == 1)
    wait(&y.y);
    printf("\n Number of readers in the database: %d",readcount);
    signal(&x.x);
    readcount--;
    if(readcount == 0){
        signal(&y.y);
    }
    signal(&x.x);
    printf("\nThe number of reader out of database: %d",readcount + 1);
}

void *writer(){
    wait(&y.y);
    printf("\n Writer in the database");
    signal(&y.y);
    printf("\n Writer out of the database");
}

int main(){
    int n,i;
    printf("\nEnter the number of readers: ");
    scanf("%d",&n);
    int pid[n];
    x.x = 1;
    y.y = 1;

    for(i=0;i<n;i++){
        pid[i] = fork();

        if(pid[i] == 0){
            reader();
        }
        if(pid[i] > 0){
            writer();
        }
    }
    return 0;
}