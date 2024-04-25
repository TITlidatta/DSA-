// implementation of queue
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define SIZE 10

typedef struct node
{
    int processID;
    char processName[10];
    int priority;
    int bursttime;
}Process;


void enQueue();
void deQueue();
void display();
int process_execution(int x);
void priordequeue(int x);

Process queue[SIZE];
int front = -1, rear = -1;

void main()
{
    int value, choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1.Insert Process\n2.Display Process\n3. Process Execution\n4. Prior Processing\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueue();
            break;
        case 2:
            display();
            break;

        case 3:
            printf("if you want to continue processing task  enter 1 else enter 0 to stop\n");
            process_execution(1);
            break;
        case 4:
            priordequeue(1);
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}
void enQueue()
{
    int value1,value3,value4;
    char value2[10];
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!! Insertion is not possible!!!");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        printf("Enter Process Id ");
        scanf("%d",&value1);
        queue[rear].processID = value1;
        printf("Enter Process Name ");
        scanf("%s",value2);
        strcpy(queue[rear].processName ,value2);
        printf("Enter priority ");
        scanf("%d",&value3);
        queue[rear].priority = value3;
        printf("Enter Process burst time ");
        scanf("%d",&value4);
        queue[rear].bursttime=value4;
    }
}
void deQueue()
{
    if (front == -1 || front > rear)
        printf("\nQueue is Empty!!! Deletion is not possible!!!");

    printf("Deleted: \n");
    printf("ID %d\n", queue[front].processID);
    printf("Name %s\n", queue[front].processName);
    printf("Priority %d\n", queue[front].priority);
    printf("bursttime %d\n", queue[front].bursttime);
     
    if (front == rear)
        front = rear = -1;
    else
        front++;
}
void display()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("ID %d\n", queue[i].processID);
            printf("Name %s\n", queue[i].processName);
            printf("Priority %d\n", queue[i].priority);
            printf("Burst time  %d\n", queue[i].bursttime);
            printf("___________________\n");
        }
    }
}
int  process_execution(int x)
{
    int y;
    if(x==1)
    {  
        sleep(4);
        deQueue();
        printf("\nprocess next job? ");
        scanf("%d",&y);
        if(y==1)
        {
            process_execution(1);
        }
        else
        {
            return 0;
        }
        
    }
    return 0;
    
}
void priordequeue(int x)
{
    int min=100;
    int i,y,k;
    if(x==1)
    {
        for(i=front;i<=rear;i++)
        {
            if(queue[i].priority<min)
            {
                min=queue[i].priority;
                k=i;
            }
        }
        for(i=k+1;i<=rear;i++)
        {
            queue[i-1].processID=queue[i].processID;
            strcpy(queue[i-1].processName,queue[i].processName);
            queue[i-1].priority=queue[i].priority;
            queue[i-1].bursttime=queue[i].bursttime;
        }
        rear--;
    }    
    printf("continue?");
    scanf("%d",&y);
    if(y==1)
    {
        priordequeue(1);
    }
    else
    {
        return 0;
    }
}