//infix to postfix
//infix to postfix evaluation
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max 50
 int isoperator(char x)
 {
    if( x =='+' ||  x =='-' ||  x =='/' ||  x =='*' || x=='^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
 }
 
 int precedence(char c)
 {
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2; 
        case '^':
            return 3;
        default:
            return -1;
    }
 }
 char * infix_to_postfix(char infix[])
 {
    int i,j=0,top=-1;
    int len=strlen(infix);
    char stack[max];
    char*postfix=(char*)malloc(sizeof(char)*(len+2));
    for(i=0;i<len;i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            stack[++top]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(top>-1 && stack[top]!='(')
            {
                postfix[j++]=stack[top--];
            }
            if(top>-1 && stack[top]!='(')
            {
                printf("INVALID EXPRESSION");
            }
            else
            {
                top--;
            }
        }
        else if(isoperator(infix[i])==1)
        {
            while(top>-1 && (precedence(stack[top])>=precedence(infix[i])))
            {
                postfix[j++]=stack[top--];
            }
            stack[++top]=infix[i];
        }
    }
    while(top>-1)
    {
        postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
     
    return postfix;
 }
 int main()
 {
    char infix[max]="(a+b^d-c)*(e/f)";
    char*postfix=infix_to_postfix(infix);
    printf("%s",postfix);
    free(postfix);
    return 0;
 }