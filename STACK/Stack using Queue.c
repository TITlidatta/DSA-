#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


int queue[SIZE], front = -1, Top = -1;

void main()
{
    int value, choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2.Pop\n3. Display\n4.Check if stack empty\n5.Check is stack full\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to Push ");
            scanf("%d", &value);
            Push(value);
            break;
        case 2:
            Pop();
            break;
        case 3:
            display();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}

void Push(int value)
{
    if (Top == SIZE - 1)
        printf("\nStack is Full!!! Insertion is not possible!!!");
    else
    {
        if (front == -1)
            front = 0;
        Top++;
        queue[Top] = value;
        printf("\nPushed!!!");
    }
}

void Pop()
{
    if (front == -1 || front > Top)
        printf("\nStack is Empty!!! Deletion is not possible!!!");

    printf("\nPopped : %d", queue[Top]);

    if (front == Top)
        front = Top = -1;
    else
        Top--;
}

void display()
{
    if (Top == -1)
        printf("\nStack is Empty!!!");
    else
    {
        int i;
        printf("\nStack elements are:\n");
        for (i = Top; i >=front; i--)

            printf("%d\n", queue[i]);
    }
}

void isEmpty()
{
    if (front== -1)
    {
        printf("\nStack is empty!!!");
    }
}
void isFull()
{
    if (Top == SIZE - 1)
        printf("\nStack is Full!!!");
    else
        printf("Stack not Full");
}