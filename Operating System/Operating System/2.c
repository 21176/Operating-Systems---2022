#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
    int pid;
    pid = fork();
    printf("Welcome");
}
//output : welcome welcome
//Generally a C program when we execute with a single printf statement, only one output is supposed to come. But here 2 outputs are coming because, the fork() will create another child with same code. Due to this, same code will get execute twice.