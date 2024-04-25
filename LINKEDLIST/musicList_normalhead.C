/*Some Operations on Single Linked List*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Create node*/
typedef struct node
{
    char title[100];
    char artist[100];
    struct node *next;
}song;

void addSong(song *head,char Title[],char Artist[]);
void display(song *head);
void deleteSong(song *head,char Title[]);
void searchSong(song *head,char Title[]);

song  *temp, *ptr;

int main() 
{
    song *head=NULL;
    char Title[100], Artist[100];
    int choice;
    while (1)
    {
        printf("\n******************** MENU *******************");
        printf("\n 1.ADD song");
        printf("\n 2.Display");
        printf("\n 3.delete song");
        printf("\n 4.Exit");
        printf("\n 5. Search");
        printf("\n--------------------------------------");
        printf("\nEnter your choice:\t");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter title");
            scanf("%s", Title);
            printf("\nEnter artist");
            scanf("%s", Artist);
            addSong(head,Title, Artist);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter title");
            scanf("%s", Title);
            deleteSong(head,Title);
            break;
        case 4:
            exit(0);
            break;
        case 5:
            printf("Enter title");
            scanf("%s", Title);
            searchSong(head,Title);
            break;
        default:
            printf("!!!Wrong Choice!!!");
        }
    }
 return 0;
} 
void addSong(song *head,char Title[],char Artist[])
{
    temp = (song *)malloc(sizeof(song));
    strcpy(temp->title,Title);
    strcpy(temp->artist,Artist);
    
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

void display(song *head) 
{
    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
    }
    else
    {
        ptr = head;
        printf("\nThe List elements are:\n\n");
        while (ptr != NULL)
        {
            printf("%s\t", ptr->title);
            printf("%s\n", ptr->artist);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

void deleteSong(song *head,char Title[]) 
{
    int i;
    if (head == NULL)
    {
        printf("\nThe List is Empty!!!\n");
    }
    else
    {
        ptr = head;

        while (ptr!=NULL)
        {
            if (strcmp(ptr->title,Title)==0)
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
        printf("\nSong deleted");
        free(ptr);
    }
}

void searchSong(song *head,char Title[]) 
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
            if (strcmp(ptr->title,Title)==0)
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
}