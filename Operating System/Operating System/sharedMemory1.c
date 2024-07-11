//This program creates a shared memory segment, attaches itself to it, and then writes some content into the shared memory segment.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
   int i;
   void *shared_memory;
   char buff[100];
   int shmid;
   //syntax of shmget() => int shmget (key_t key, size_t size, int shmflg); used to create a shared memory 
   shmid = shmget((key_t)2345,1024,0666|IPC_CREAT);
   printf("The key of the shared memory is: %d\n",shmid);
   //syntax of shmat() => void *shmat(int shmid, const void *shmaddr, int shmflg); used to attach the memory 
   //shmdt() => used to detach the memory;int shmdt(const void *shmaddr);
   shared_memory = shmat(shmid,NULL,0);
   printf("Process attached at %p\n",shared_memory);  
   printf("Enter some data to write to shared memory\n");  
   read(0,buff,100);   
   strcpy(shared_memory,buff);  
   printf("You wrote : %s\n",(char *)shared_memory);  
}