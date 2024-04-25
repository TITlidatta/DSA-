#include<stdio.h>
#include<stdbool.h>
int MAX_SIZE =30;
int top=-1;
char stack[30];
int push(char x)
{
    int k;
    if(top==MAX_SIZE-1)
    {
        printf("\nStack is full");
    }
    else
    {
        stack[top+1]=x;
        top++;
        k=top;
    }
    return 0;
}
int display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%c",stack[i]);
    }
    return 0;
}
char pop()
{
    char c;
    if (top==-1)
    {
        printf("no item to pop");
    }
    else
    {
       c=stack[top];
       top--;
    }
    return c;
}
int palindromecheck(char arr[],int x)
{
    char brr[30];
    int i;
    for(i=0;i<x;i++)
    {
        if((arr[i]!=';')||(arr[i]!=':')||(arr[i]!='?')||(arr[i]!=',')||(arr[i]!=' '))
        {
            push(arr[i]);
        }
    }/*pushing elements of string arr into stack ignoring space and punctuation*/
    for(i=0;i<=x-1;i++)
    {
        brr[i]=pop();//poping stack from end of stack and filling brr
    }
    for(i=0;i<x;i++)/*to check if brr=arr where brr stores elements of arr from right end*/
    {
       if(brr[i]!=arr[i])
       {
           return false;
           break;
       }
    }
    return true;
}
int main()
{
    char arr[30];
    int x;
    printf("Enter size of string");
    scanf("%d",&x);
    printf("Enter the string ");
    scanf("%s",arr);
    if(palindromecheck(arr,x))
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    return 0;
}