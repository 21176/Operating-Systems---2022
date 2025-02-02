//This program attaches itself to the shared memory segment created in sharedMemory1.c, and it reads the content of the shared memory.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
    int i;
    int *shared_memory;
    char buffer[100];
    int shmid;
    
    shmid = shmget((key_t)2345,1024,0666);
    printf("Key of shared memory is: %d\n",shmid);
    
    shared_memory = shmat(shmid,NULL,0);
    printf("Process attached at p: %p\n",shared_memory);
    
    printf("Data read from shared memory is: %s\n",(char *)shared_memory);
    
}
