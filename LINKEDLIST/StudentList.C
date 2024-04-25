/*Some Operations on Single Linked List*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Create node*/
typedef struct node
{
    int rollNumber;
    char name[100];
    float marks;
    struct node *next;
}STUDENT;

void addStudent( char arr[], int roll, float mark);
void deleteStudent(int roll);
void displayStudents();
int searchStudent(int roll);
STUDENT  *head=NULL,*temp, *ptr;

int main() 
{
    char arr[200];
    int roll;
    float mark;
    int choice;
    while (1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.ADD a Student");
        printf("\n 2.Display all Student");
        printf("\n 3.delete a Student");
        printf("\n 4. Search for a student");
        printf("\n 5.Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter name ");
            scanf("%s",arr);
            printf("\nEnter roll ");
            scanf("%d",&roll);
            printf("Enter marks ");
            scanf("%f",&mark);
            addStudent(arr,roll,mark);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter roll of student ");
            scanf("%d",&roll);
            deleteStudent(roll);
            break;
        case 4:
            printf("Enter roll ");
            scanf("%d",&roll);
            searchStudent(roll);
            break;
        case 5:
            exit(0);
            break;    

        default:
            printf("!!!Wrong Choice!!!");
        }
    }
 return 0;
} 
void addStudent(char arr[],int roll,float mark)
{
    temp = (STUDENT *)malloc(sizeof(STUDENT));
    temp->rollNumber=roll;
    strcpy(temp->name,arr);
    temp->marks=mark;
    
    temp->next = NULL;
    if (temp == NULL)
    {
        printf("\n!!!Out of Memory Space!!!\n");
        exit(0);
    }

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void displayStudents() 
{
    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr = head;
        printf("\nThe Student list are:\n\n");
        while (ptr != NULL)
        {
            printf("\n%s\n", ptr->name);
            printf("%d\n", ptr->rollNumber);
            printf("%f\n", ptr->marks);
            printf("***************************");
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

void deleteStudent(int roll) 
{
    int i;
    if (head == NULL)
    {
        printf("\nThe List is Empty!!!\n");
    }
    else if((head->rollNumber==roll)&& (head->next==NULL))
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("deleted task");
    }
    else
    {
        ptr = head;

        while (ptr!=NULL)
        {
            if (ptr->rollNumber==roll)
            {
                break;
            }
            temp = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("\nSong not Found:\n");
        }
        temp->next = ptr->next;
        free(ptr);
        printf("deleted task");
    }
}

int searchStudent(int roll) 
{
    int i=1;

    if (head == NULL)
    {
        printf("\nList is empty!!!!\n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->rollNumber==roll)
            {
                printf("\nValue is found at position %d", i);
                break;
            }
            ptr = ptr->next;
            i=i+1;
        }
    }
    if(ptr==NULL)
    {
        printf("-1");
    }
    return 0;
}