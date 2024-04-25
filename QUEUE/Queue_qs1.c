// implementation of queue
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define SIZE 10

typedef struct node
{
    int jobID;
    char jobName[10];
    int numPages;
 
}PrintJob;


void enQueue();
void deQueue();
void display();
int multijob(int x);
void priordequeue(int);

PrintJob queue[SIZE];
int front = -1, rear = -1;

void main()
{
    int value, choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1.Insert JOB\n2. Delete JOB \n3. Display JOBS\n4.Add multiple Jobs\n5. Priority printing\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;

        case 4:
            printf("if you want to continue enter 1 else enter 0 to stop\n");
            multijob(1);
            break;
        case 5:
            priordequeue(1);
            break;
        case 6:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}
void enQueue()
{
    int value1,value3;
    char value2[10];
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!! Insertion is not possible!!!");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        printf("Enter Job Id ");
        scanf("%d",&value1);
        queue[rear].jobID = value1;
        printf("Enter Job Name ");
        scanf("%s",value2);
        strcpy(queue[rear].jobName ,value2);
        printf("Enter Job page number ");
        scanf("%d",&value3);
        queue[rear].numPages = value3;
    }
}
void deQueue()
{
    if (front == -1 || front > rear)
        printf("\nQueue is Empty!!! Deletion is not possible!!!");

    printf("Deleting: \n");
    sleep(4);
    printf("ID %d\n", queue[front].jobID);
    printf("Name %s\n", queue[front].jobName);
    printf("Pages %d\n", queue[front].numPages);
     
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
            printf("ID %d\n", queue[i].jobID);
            printf("Name %s\n", queue[i].jobName);
            printf("Pages %d\n", queue[i].numPages);
            printf("___________________\n");
        }
    }
}
int  multijob(int x)
{
    int y;
    if(x==1)
    { 
        enQueue();
        printf("continue? ");
        scanf("%d",&y);
        if(y==1)
        {
            multijob(1);
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
            if(queue[i].numPages<min)
            {
                min=queue[i].numPages;
                k=i;
            }
        }
        for(i=k+1;i<=rear;i++)
        {
            queue[i-1].jobID=queue[i].jobID;
            strcpy(queue[i-1].jobName,queue[i].jobName);
            queue[i-1].numPages=queue[i].numPages;
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