//write a program to create a child process,load the executable file factorial inot the child adress space using execlp() function

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main(){
    int pid;
    pid = fork();
    if(pid==0){
        execlp("/home/year2/factorial","factorial",NULL);
    }
    else
    printf("Parent is processing\n");
}

