// Online C compiler to run C program online
#include <stdio.h>

int MAX_SIZE=6;
int stack[6];
int top=-1;
int push(int value)
{
    stack[top+1]=value;
    top++;
    return 0;
}
int pop()
{
    printf("\nthe element %d is popped",stack[top]);
    top--;
    return 0;
}
int isEmpty()
{
    if (top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("Not empty");
    }
    return 0;
}
int isFull()
{
    if (top==MAX_SIZE-1)
    {
        printf("stack is full");
    }
    else
    {
        printf("Not full");
    }
    return 0;
}
int display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("\n%d",stack[i]);
    }
    
    return 0;
}
int main()
{
   push(4);
   push(5);
   push(6);
   display();
   pop();
   pop();
   display();
   pop();
   isEmpty();
   push(10);
   push(11);
   display();
    return 0;
}