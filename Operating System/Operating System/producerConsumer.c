#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=3,x=0; 
//mutex is just a variable; plays the role of semaphore
//full number of field slots
//empty number of empty slots
//x the number of items produced or consumed

int main(){
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);

    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1){
        printf("\nEnter a choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            if((mutex == 1) && (empty != 0)) //producer wants to produce an item
            producer();
            else
            printf("Buffer is full!!");
            break;

        case 2:
            if((mutex == 1) && (full != 0))
            consumer();
            else
            printf("Buffer is empty!!");
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\nInvalid choice!!");
            break;
        }
    }

    return 0;
}

int wait(int s){
    return (--s);
}

int signal(int s){
    return (++s);
}

void producer(){
    mutex = wait(mutex);//mutex == semaphore ; to indicate that the producer is in the critical section
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    mutex = signal(mutex); //allows the next process to be executed
}

void consumer(){
    mutex = wait(mutex);// to indicate that the consumer is in the critical section6
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex = signal(mutex);
}
