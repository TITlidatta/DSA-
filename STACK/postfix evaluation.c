#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 40

int pop();
void push(int);

char postfix[SIZE];
int stack[SIZE], top = -1;

int main()
{
	int i, a, b, result, pEval;
	char ch;
	printf("\nEnter a postfix expression: ");
	scanf("%s",postfix);

	for(i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(isdigit(ch))
		{
			push(ch-'0');/*here the digit is a part of string element so it is a character so ch converted to integer.
		                         C and C++ store characters as integers using their underlying ASCII codes, 
                                          so '0' is 48, '1' is 49, and so on.The easiest way to convert a single character to the
                                          integer it represents is to subtract the value of '0'.If we take '3' (ASCII code 51)
                                       and subtract '0' (ASCII code 48), we’ll be left with the integer 3, which is what we want.*/
                }

		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '%':result = a%b;
					  break;
			}
			
			push(result);
		}		
	
	}

	pEval = pop();
	
	printf("\nThe postfix evaluation is: %d\n",pEval);
	
	return 0;
}

void push(int n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack is full!\n");
		exit(-1);
	}
}
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
}	