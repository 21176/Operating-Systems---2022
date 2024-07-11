//factorial program => related to 7.c
#include<stdio.h>
void main(){
    int num,i,fact=1;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        fact=fact*i;
    }
    printf("The factorial of %d is:%d",num,fact);
}