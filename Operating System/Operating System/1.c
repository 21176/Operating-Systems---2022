//fork() will create one more process which is referred as child process. 
// This will share the same code, program counter and CPU register values.
// The only difference is that these two processes will have different address space (Base & Limit register values), Process ID and state.
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
    int pid;
    pid  = fork();
}