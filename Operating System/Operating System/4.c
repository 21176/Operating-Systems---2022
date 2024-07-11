//write a program to demonstrate getpid(),getppid() functions
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
    int pid;
    pid = fork();
    if(pid>0){//parent process
        printf("The value of PID variable:%d\n",pid);//prints the return value of the fork()
        printf("Process ID:%d\n",getpid());//prints the process ID
        printf("Process ID of parent process:%d\n",getppid());
    }
    if(pid==0){
        printf("The value of PID variable:%d\n",pid);//print the return value of fork()
        printf("Process ID:%d\n",getpid());//print the process id
        printf("Process ID of the parent process:%d\n",getppid());
    }
}