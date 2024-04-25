// Implementation of stack using 2 queue

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define SIZE 10

void enqueue(int,int *);
int dequeue(int *);
void display();
bool IsEmpty(int *);
bool IsFull(int *);

int queue1[SIZE], front1 = -1, rear1 = -1;
int queue2[SIZE], front2 = -1, rear2 = -1;
int *x,*y;

void main()
{
    int value, choice;
    x=&queue1[0];
    y=&queue2[0];
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1.PUSH\n2.POP\n3. Display\n4.Check if STACK is Empty\n5.Check if Stack is full\n 6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            enqueue(value,x);
            break;
        case 2:
            dequeue(x);
            break;
        case 3:
            display();
            break;

        case 4:
            if(IsEmpty(x))
            {
                printf("True");
            }
            else
            {
                printf("False");
            }
            break;
        case 5:
            if(IsFull(x))
            {
                printf("True");
            }
            else
            {
                printf("False");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}
void enqueue(int value,int *p)
{
    if(p==x)
    {
        if (front1 == -1)
            front1 = 0;
        rear1++;
        queue1[rear1] = value;
    }
    if(p==y)
    {
        if (front2 == -1)
            front2 = 0;
        rear2++;
        queue2[rear2] = value;
    }
}
int dequeue(int *p)
{
    int temp,i;
    if(p==x)
    {
        for (i = rear1; i>=front1; i--)
        {
            enqueue(queue1[i],y);
        }
        printf(" Popped element is %d",dequeue(y));
        for(i=rear2;i>=front2;i--)
        {
            enqueue(queue2[i],x);
        }
        return 0;
    }
    if(p==y)
    {
        temp=queue2[front2];
        front2++;
        return temp;
    }
}
void display()
{
    if (rear1 == -1)
        printf("\nSTACK is Empty!!!");
    else
    {
        int i;
        printf("\nSTACK elements are:\n");
        for(i=rear1;i>=front1;i--)
        {
            printf("%d\n",queue1[i]);
        }
       
    }
}
bool IsFull(int *p)
{
    if(p==x)
    {
        if(rear1==SIZE-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    
    if(p==y)
    {
        if(rear2==SIZE-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }   
}

bool IsEmpty(int *p)
{
    if(p==x)
    {
        if(front1==rear1)
        {
            front1=-1;
            rear1=-1;
            return true;
        }
        else
        {
            return false;
        }
    }    
    if(p==y)
    {
        if(front2==rear2)
        {
            front2=-1;
            rear2=-1;
            return true;
        }
        else
        {
            return false;
        }
    }    
}