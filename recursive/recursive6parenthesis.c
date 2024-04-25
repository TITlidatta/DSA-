// parenthesis balancing
#include <stdio.h>// parenthesis check
#include <stdbool.h>
int MAX_SIZE =30;
int top=-1;
char stack[30];
int push(char x)
{
    if(top==MAX_SIZE-1)
    {
        printf("\nStack is full");
    }
    else
    {
        stack[top+1]=x;
        top++;
    }
    return 0;
}
int pop()
{
    if (top==-1)
    {
        printf("no item to pop");
    }
    else
    {
       top--;
    }
    return 0;
}
bool isEmpty()
{
    if (top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool check(char snn[],int i,int size)
{
    if(i<size)
    {
        if((snn[i]== '(') || (snn[i]== '[') || (snn[i]== '{'))
        {  
            push(snn[i]);
        }
         else //if closing bracket
        {
            if(isEmpty())
            {
                printf("false");
                return false;
            }
            else
            {
                if((stack[top]=='(' && snn[i]==')')||(stack[top]=='[' && snn[i]==']')||(stack[top]=='{' && snn[i]=='}'))
                {
                    pop();
                }
            }
        }
    }
    if(i<size)
    {
       check(snn,i+1,size);
    }
    else if(i>=size && isEmpty())
    {
      printf("true");          
      return true;
    }
    else
    {
        printf("false");
        return false;
    }
}
int main() 
{
    char snn[6],i,flag=0;
    printf("Enter an expression\n");
    for(i=0;i<=5;i++)
    {
        scanf("%c",&snn[i]);
    }
    check(snn,0,6);
    return 0;
}