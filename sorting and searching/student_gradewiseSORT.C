// Online C compiler to run C program online
#include <stdio.h>
#include<conio.h>
#include<string.h>

struct student
{
    char name[20];
    char grade;
};
int check(char c)
{
    switch (c)
    {
        case 'A':
            return 4;
        case 'B':
            return 3;
        case 'C':
            return 2;
        case 'D':
            return 1;
    }
}
void swap(struct student *a, struct student *b)/* here two pointers pointing to two specific structure elements of the array of structures as given as input */
{
    char temp;
    temp =a->grade;
    a->grade=b->grade;
    b->grade=temp;
    strcpy(a->name,b->name);
}

void bubbleSort(struct student *arr, int n)/* arr stores the address of the 1st element of array of structures*/
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (check(arr[j].grade) > check(arr[j + 1].grade))
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() 
{
    int n,i;
    char c;
    struct student list[20];
    printf("Enter the number of students\n");
    scanf("%d",&n);
    printf("Enter the name and marks\n");
    for( i=0;i<n;i++)
    {
        scanf("%s",list[i].name);
        scanf(" %c",&list[i].grade);
    }
    bubbleSort(&list[0],n);
    printf("ascending-A or descendind -D\n");
    scanf("%c",&c);
    if(c=='D')
    {
        for(i=0;i<n;i++)
        {
            printf("%s",list[i].name);
            printf("  %c",list[i].grade);
            printf("\n");
        }
    }
    else
    {
        for(i=n-1;i<=0;i--)
        {
            printf("%s",list[i].name);
            printf("  %c",list[i].grade);
            printf("\n");
        }
    }
        
    
    return 0;
}