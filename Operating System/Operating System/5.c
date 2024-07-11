//This pgm shows that if block is getting executed in child process and else block is getting executed
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
    int pid;
    pid = fork();
    if(pid==0)
    printf("Child process");
    else
    printf("Parent process");
}
//output: Parent process child process