//priority queue

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define SIZE 10

typedef struct node
{
    int value;
    int priority;
};


void enQueue();
void deQueue();
void display();
void priordequeue();

struct node queue[SIZE];
int front = -1, rear = -1;

void main()
{
    int value, choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1.Insert Process\n2.Display Process\n3. Delete Process\n4. Prior dequeue\n5. Exit");
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
            deQueue();
            break;
        case 4:
            priordequeue();
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
    int value1, value2;
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!! Insertion is not possible!!!");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        printf("Enter value ");
        scanf("%d",&value1);
        queue[rear].value = value1;
        printf("Enter priority ");
        scanf("%d",&value2);
        queue[rear].priority = value2;
    }
}
void deQueue()
{
    if (front == -1 || front > rear)
        printf("\nQueue is Empty!!! Deletion is not possible!!!");

    printf("Deleted: \n");
    printf("value %d\n", queue[front].value);
    printf("Priority %d\n", queue[front].priority);
     
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
            printf("value %d\n", queue[i].value);
            printf("Priority %d\n", queue[i].priority);
            printf("___________________\n");
        }
    }
}

void priordequeue()
{
    int min=100;
    int i,y,k;
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
        queue[i-1].value=queue[i].value;
        queue[i-1].priority=queue[i].priority;
    }
    rear--;
}