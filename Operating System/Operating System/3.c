#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
    int pid;
    pid = fork();
    printf("Process ID:%d",pid);
}
//output : 19823 0  
//Here 2 outputs are getting. 
//Fork () returns 0 to the child address space and child's process ID to the parent process.
//So PID variable in child will have a value 0 while PID variable in parent will have the process ID of child.