/*Some Operations on Single Linked List*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Create node*/
typedef struct node
{
    int taskId;
    char description[200];
    int priority;
    struct node *next;
}TASK;

void addTask(int Id, char arr[], int prior);
void deleteTask(int Id);
void displayTasks();
/*void prioritizeTasks();*/
int searchTask(int Id);
TASK  *head=NULL,*temp, *ptr;

int main() 
{
    char arr[200];
    int ID, prior;
    int choice;
    while (1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.ADD a task");
        printf("\n 2.Display all tasks");
        printf("\n 3.delete a task");
        printf("\n 4.prioritize a task");
        printf("\n 5. Search for a task");
        printf("\n 6.Exit");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter taskid");
            scanf("%d",&ID);
            printf("\nEnter description");
            scanf("%s",arr);
            printf("Enter priority of task");
            scanf("%d",&prior);
            addTask(ID,arr,prior);
            break;
        case 2:
            displayTasks();
            break;
        case 3:
            printf("Enter id of task");
            scanf("%d",&ID);
            deleteTask(ID);
            break;
        case 4:
        printf("Later");
            //prioritizeTasks();
            break;
        case 5:
            printf("Enter ID");
            scanf("%d",&ID);
            searchTask(ID);
            break;
        case 6:
            exit(0);
            break;    

        default:
            printf("!!!Wrong Choice!!!");
        }
    }
 return 0;
} 
void addTask(int ID ,char arr[],int prior)
{
    temp = (TASK *)malloc(sizeof(TASK));
    temp->taskId=ID;
    strcpy(temp->description,arr);
    temp->priority=prior;
    
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

void displayTasks() 
{
    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr = head;
        printf("\nThe Task list are:\n\n");
        while (ptr != NULL)
        {
            printf("\n%d\n", ptr->taskId);
            printf("%s\n", ptr->description);
            printf("%d\n", ptr->priority);
            printf("***************************");
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

void deleteTask(int ID) 
{
    int i;
    if (head == NULL)
    {
        printf("\nThe List is Empty!!!\n");
    }
    else if((head->taskId==ID)&& (head->next==NULL))
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
            if (ptr->taskId==ID)
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

int searchTask(int ID) 
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
            if (ptr->taskId==ID)
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

/*void prioritizeTasks()
{
    if(head==NULL)
    {
        printf("No playlist to play");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {   
            printf("playing %s by %s",ptr->title,ptr->artist);
            printf("\nNEXT?\t Yes or No\n");
            scanf("%s",str);
            if(strcmp(str,"Yes")==0)
            {
                ptr=ptr->next;
            }   
            else
            {
                break;
            }
        }
    }
}*/