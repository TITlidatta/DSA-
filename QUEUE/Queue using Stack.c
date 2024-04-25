// Implementation of Queue using Array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void enQueue(int);
void deQueue();
void display();
void frontElement();

int STACK[SIZE], TOP = -1, rear = -1;

void main()
{
    int value, choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1.Enqueue\n2. Dequeue\n3. Display\n4. Top_element\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            enQueue(value);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;

        case 4:
            TopElement();
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}
void enQueue(int value)
{
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!! Insertion is not possible!!!");
    else
    {
        if (TOP == -1)
            TOP = 0;
        rear++;
        STACK[rear] = value;
        printf("\nInsertion success!!!");
    }
}
void deQueue()
{
    if (TOP == -1 || TOP > rear)
        printf("\nQueue is Empty!!! Deletion is not possible!!!");

    printf("\nDeleted : %d", STACK[TOP]);

    if (TOP == rear)
        TOP = rear = -1;
    else
        TOP++;
}
void display()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = TOP; i <= rear; i++)

            printf("%d\t", STACK[i]);
    }
}
void TopElement()
{
    if (TOP == -1)
    {
        printf("\nQueue is empty!!!");
    }
    printf("\nThe front element is %d", STACK[TOP]);
}