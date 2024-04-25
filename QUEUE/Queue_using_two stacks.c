#include<stdio.h>
#include<stdlib.h>
int stack1[6];
int stack2[6];
int top2=-1;
int top1=-1;
int *x;
int *y;

int enqueue(int value,int *q)
{
    if(q==x)
    {
        stack1[top1+1]=value;
        top1++;
        return 0;
    }
    if(q==y)
    {
        stack2[top2+1]=value;
        top2++;
        return 0;
    }
}
int dequeue()
{
    while((isEmpty(x))==0)
    {
        enqueue(pop(x),y);
            
    }
    printf(" deleted %d",stack2[top2]);
    pop(y);
    while((isEmpty(y))==0)
    {
        enqueue(pop(y),x);
    }
    return 0;
}
int pop(int *q)
{
    int temp;
    if(q==x)
    {
        temp=stack1[top1];
        top1--;
        return temp;
    }
    if(q==y)
    { 
        temp=stack2[top2];
        top2--;
        return temp;
    }
}
int isEmpty(int *p)
{
    if(p==x)
    {
        if (top1==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(p==y)
    {
        if (top2==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int isFull(int *p)
{
    if(p==x)
    {
        if (top1==5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(p==y)
    {
        if (top2==5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int display()
{
    int i;
    printf("Queue elements are:\n ");
    for(i=0;i<=top1;i++)
    {
        printf("%d\t",stack1[i]);
    }
    
    return 0;
}
int main()
{
    x=&stack1[0];
    y=&stack2[0];
    int value, choice;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1.Enqueue\n2. Dequeue\n3. Display\n4. Exit");
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
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}