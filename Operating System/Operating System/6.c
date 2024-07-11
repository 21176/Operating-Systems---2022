//Write a program to read a number from the user. Create a child process and child should calculate the square of the number and parent should calculate the half of the number. 
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
    int num,pid,square,half;
    prinf("Enter a number: ");
    scanf("%d",&num);
    pid = fork();
    if(pid==0){//child process
        square = num * num;
        printf("The square of %d is: %d",num,square);
    }
    else{//parent process
        half = num / 2;
        printf("The half of %d is:%d",num,half);
    }
}